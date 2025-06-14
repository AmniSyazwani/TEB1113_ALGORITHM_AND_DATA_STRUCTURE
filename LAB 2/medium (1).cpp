//NUR AMNI SYAZWANI BINTI MOHAMAD NASIR
// 22011748


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000;

int findMinimumCost(int cost[], int numPackets, int targetWeight) {
    vector<int> packetCosts;
    vector<int> packetWeights;

    for (int i = 0; i < numPackets; ++i) {
        if (cost[i] != -1) {
            packetCosts.push_back(cost[i]);
            packetWeights.push_back(i + 1); 
        }
    }

    int availableTypes = packetCosts.size();
    vector<vector<int>> dp(availableTypes + 1, vector<int>(targetWeight + 1, INF));

    for (int i = 0; i <= availableTypes; ++i) {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= availableTypes; ++i) {
        for (int w = 1; w <= targetWeight; ++w) {
            if (packetWeights[i - 1] > w) {
                dp[i][w] = dp[i - 1][w]; 
            } else {
                dp[i][w] = min(
                    dp[i - 1][w],
                    dp[i][w - packetWeights[i - 1]] + packetCosts[i - 1]  
                );
            }
        }
    }

    return (dp[availableTypes][targetWeight] == INF) ? -1 : dp[availableTypes][targetWeight];
}

int main() {
    int cost[] = {1, 2, 3, 4, 5};
    int W = 5;
    int n = sizeof(cost) / sizeof(cost[0]);

    int result = findMinimumCost(cost, n, W);
    cout << "Minimum cost to fill " << W << " kg: " << result << endl;

    return 0;
}

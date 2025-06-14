//NUR AMNI SYAZWANI BINTI MOHAMAD NASIR
// 22011748


#include <iostream>
#include <climits>
using namespace std;

const int SIZE = 5;

int findMaxDifference(int matrix[SIZE][SIZE]) {
    int maxDiff = INT_MIN;


    for (int a = 0; a < SIZE - 1; ++a) {
        for (int b = 0; b < SIZE - 1; ++b) {
            for (int d = a + 1; d < SIZE; ++d) {
                for (int e = b + 1; e < SIZE; ++e) {
                    int currentDiff = matrix[d][e] - matrix[a][b];
                    if (currentDiff > maxDiff) {
                        maxDiff = currentDiff;
                    }
                }
            }
        }
    }

    return maxDiff;
}

int main() {
    int matrix[SIZE][SIZE] = {
        {  1,  2, -1, -4, -20 },
        { -8, -3,  4,  2,   1 },
        {  3,  8,  6,  1,   3 },
        { -4, -1,  1,  7,  -6 },
        {  0, -4, 10, -5,   1 }
    };

    int result = findMaxDifference(matrix);
    cout << "Maximum Value is " << result << endl;

    return 0;
}

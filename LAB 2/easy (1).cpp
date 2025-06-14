//NUR AMNI SYAZWANI BINTI MOHAMAD NASIR
//22011748

#include <iostream>
#include <unordered_map>
using namespace std;

const int ROWS = 4;
const int COLS = 5;

void printCommonElements(int matrix[ROWS][COLS]) {
    unordered_map<int, int> elementCount;

    for (int j = 0; j < COLS; ++j) {
        elementCount[matrix[0][j]] = 1;
    }

    for (int i = 1; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            int currentElement = matrix[i][j];

            if (elementCount[currentElement] == i) {
                elementCount[currentElement] = i + 1;

                if (i == ROWS - 1 && elementCount[currentElement] == ROWS) {
                    cout << currentElement << " ";
                }
            }
        }
    }
}

int main() {
    int matrix[ROWS][COLS] = {
        {1, 2, 1, 4, 8},
        {3, 7, 8, 5, 1},
        {8, 7, 7, 3, 1},
        {8, 1, 2, 7, 9},
    };

    cout << "Common elements in all rows: ";
    printCommonElements(matrix);
    cout << endl;

    return 0;
}

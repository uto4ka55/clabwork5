#include <iostream>
using namespace std;

bool setArray(int** &arr, int& rows, int &columns) {
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> columns;
    if (rows < 1 || columns < 1) {
        cout << "Invalid input. Please enter positive numbers." << endl;
        return false;
    }
    arr = new int*[rows];
    for(int i = 0; i < rows; ++i)
        arr[i] = new int[columns];

    for (int j = 0; j < columns; ++j) {
        cout << "Enter column number " << j + 1 << ": ";
        for (int i = 0; i < rows; ++i) {
            cout << "\nEnter element " << i + 1 << ": ";
            cin >> arr[i][j];
        }
    }
    return true;
}

void printArray(int** arr, int rows, int columns) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void findEqualPositiveNegativeRawColumn(int** arr, int rows, int columns, int& lastEqualRow, int& lastEqualColumn) {
    lastEqualRow = 0;
    lastEqualColumn = 0;

    // Check each row
    for (int i = 0; i < rows; ++i) {
        int positiveCount = 0;
        int negativeCount = 0;
        for (int j = 0; j < columns; ++j) {
            if (arr[i][j] > 0) {
                positiveCount++;
            } else if (arr[i][j] < 0) {
                negativeCount++;
            }

        }
        if (positiveCount == negativeCount && positiveCount != 0) {
            lastEqualRow = i + 1;
        }
    }

    // Check each column
    for (int j = 0; j < columns; ++j) {
        int positiveCount = 0;
        int negativeCount = 0;
        for (int i = 0; i < rows; ++i) {
            if (arr[i][j] > 0) {
                positiveCount++;
            }
            else if (arr[i][j] < 0) {
                negativeCount++;
            }
        }
        if (positiveCount == negativeCount && positiveCount != 0) {
            lastEqualColumn = j + 1;
        }
    }
}

void printResult(int lastEqualRow, int lastEqualColumn) {
    cout << "Last row with equal positive and negative numbers: " << lastEqualRow << endl;
    cout << "Last column with equal positive and negative numbers: " << lastEqualColumn << endl;
}

int main() {
    char choice;
    do {
        int** arr = nullptr;
        int rows, columns, lastEqualRow, lastEqualColumn;

        if(!setArray(arr, rows, columns)) {
            choice = 'y';
            continue;
        }
        printArray(arr, rows, columns);
        findEqualPositiveNegativeRawColumn(arr, rows, columns, lastEqualRow, lastEqualColumn);
        printResult(lastEqualRow, lastEqualColumn);
        for(int i = 0; i < rows; ++i)
            delete[] arr[i];
        delete[] arr; // Free allocated memory

        cout << "Do you want to continue? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
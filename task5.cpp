#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generatePascalsTriangle(int n) {

    vector<vector<int>> triangle;

    for (int i = 0; i < n; i++) {

        vector<int> row(i + 1, 1);

        for (int j = 1; j < i; j++) {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }

        triangle.push_back(row);
    }

    return triangle;
}

void printTriangle(vector<vector<int>> triangle) {

    for (vector<int> row : triangle) {

        cout << "{ ";

        for (int value : row) {
            cout << value << " ";
        }

        cout << "}" << endl;
    }
}

int main() {

    // Test 1: n = 0
    cout << "Test 1: n = 0" << endl;
    printTriangle(generatePascalsTriangle(0));

    // Test 2: n = 1
    cout << "Test 2: n = 1" << endl;
    printTriangle(generatePascalsTriangle(1));

    // Test 3: n = 5
    cout << "Test 3: n = 5" << endl;
    printTriangle(generatePascalsTriangle(5));

    return 0;
}

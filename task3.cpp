#include <iostream>
#include <vector>
using namespace std;

vector<int> findAllIndices(int arr[], int size, int key) {
    vector<int> indices;

    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            indices.push_back(i);
        }
    }

    return indices;
}

void printVector(vector<int> v) {
    cout << "{ ";
    for (int x : v) {
        cout << x << " ";
    }
    cout << "}" << endl;
}

int main() {

    int arr1[] = {5, 2, 7, 2, 9, 2};
    vector<int> result1 = findAllIndices(arr1, 6, 2);
    cout << "Test 1: ";
    printVector(result1);

    int arr2[] = {5, 2, 7, 2, 9};
    vector<int> result2 = findAllIndices(arr2, 5, 10);
    cout << "Test 2: ";
    printVector(result2);

    int arr3[] = {};
    vector<int> result3 = findAllIndices(arr3, 0, 5);
    cout << "Test 3: ";
    printVector(result3);

    return 0;
}

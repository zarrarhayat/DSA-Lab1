#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Function to find the mode of an array
int findMode(vector<int> arr) {

    // If the array is empty
    if (arr.empty()) {
        return -1;
    }

    map<int, int> frequency;

    // Count frequency of each element
    for (int value : arr) {
        frequency[value]++;
    }

    int mode = arr[0];
    int maxFrequency = 0;

    // Find the element with the highest frequency
    for (auto pair : frequency) {
        if (pair.second > maxFrequency) {
            maxFrequency = pair.second;
            mode = pair.first;
        }
    }

    return mode;
}

int main() {

    // Test 1: Array with a unique mode
    vector<int> arr1 = {1, 2, 2, 3, 4, 2, 5};

    cout << "Test 1: Unique mode" << endl;
    cout << "Mode: " << findMode(arr1) << endl;

    // Test 2: Array with multiple modes
    vector<int> arr2 = {1, 1, 2, 2, 3};

    cout << "Test 2: Multiple modes" << endl;
    cout << "Mode: " << findMode(arr2) << endl;

    // Test 3: Empty array
    vector<int> arr3;

    cout << "Test 3: Empty array" << endl;
    cout << "Mode: " << findMode(arr3) << endl;

    return 0;
}

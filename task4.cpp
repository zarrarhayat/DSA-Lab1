#include <iostream>
#include <string>
using namespace std;

int findPattern(string text, string pattern) {

    if (pattern.empty()) {
        return 0;
    }

    for (int i = 0; i <= text.length() - pattern.length(); i++) {

        int j = 0;

        while (j < pattern.length() && text[i + j] == pattern[j]) {
            j++;
        }

        if (j == pattern.length()) {
            return i;
        }
    }

    return -1;
}

int main() {

    // Test 1: Pattern at the beginning
    cout << "Test 1: "
         << findPattern("Hello World", "Hello") << endl;

    // Test 2: Pattern at the end
    cout << "Test 2: "
         << findPattern("Hello World", "World") << endl;

    // Test 3: Pattern not present
    cout << "Test 3: "
         << findPattern("Hello World", "XYZ") << endl;

    // Test 4: Empty pattern
    cout << "Test 4: "
         << findPattern("Hello World", "") << endl;

    return 0;
}

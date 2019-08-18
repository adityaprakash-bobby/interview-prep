#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to find the Z Array for string matching purpose
vector<int> getZArray(string str) {

    int size = (int) str.size();
    vector<int> Z (size);
    int left, right;

    left = right = 0;

    for (int i = 0; i < size; i++) {

        // right variable tracks the right-most index of the string that has
        // been scanned yet
        if (i <= right) {
            Z[i] = min(right - i + 1, Z[i - left]);
        }

        // trivial algorithm to find the maximum number of characters matching
        // in the suffix and the main string
        while (i + Z[i] < size && str[Z[i]] == str[i + Z[i]]) {
            ++Z[i];
        }

        // Update the rightmost character that has been scanned
        if (i + Z[i] - 1 > right) {
            left = i;
            right = i + Z[i] - 1;
        }

    }
    
    return Z;
}

// Function returns the indices where the pattern in found in the given text
vector<int> posMatchPattern(string text, string pattern) {

    string concat = pattern + "^" + text;
    vector<int> Z = getZArray(concat);
    vector<int> res_index;

    for (int i = 0; i < Z.size(); i++) {
        if (Z[i] == pattern.size()) {
            res_index.push_back(i - pattern.size() - 1);
        }
    }

    return res_index;
}

// Driver to test the above function for string matching
int main(int argc, char const *argv[])
{
    string text = "abaaabaa";
    string pattern = "aba";

    vector<int> res = posMatchPattern(text, pattern);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << "\n";

    return 0;
}
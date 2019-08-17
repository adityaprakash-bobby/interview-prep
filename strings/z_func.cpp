#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

int main(int argc, char const *argv[])
{
    string test = "abaaabaa";
    vector<int> res = getZArray(test);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << "\n";

    return 0;
}
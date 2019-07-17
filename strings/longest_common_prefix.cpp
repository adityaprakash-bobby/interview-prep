#include <iostream>
#include <vector>
#include <string>

using namespace std;

/* Function to return the longest common prefix pf array of strings */
string longComPrefix(vector<string> A) {

    string res;
    int i, j = 0;

    if (A.size() == 1) {
        return A[0];
    }

    while (1) {

        for (i = 1; i < A.size(); i++) {

            if (A[i][j] != A[i - 1][j]) {
                break;
            } 

        }

        if (i == A.size()) {

            res += A[0][j];
            j++;

        } else {
            return res;
        }

    }

}

/* Driver to test the above function */
int main(int argc, char const *argv[])
{
    vector<string> test = { "abcdefgh", "aefghijk", "abcefgh"};
    cout << longComPrefix(test) << endl;
    return 0;
}
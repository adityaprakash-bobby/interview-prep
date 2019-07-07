#include <iostream>
#include <string>
#include <algorithm>
#include <locale>
#define fo(i, a ,b) for(int i = (int)(a); i <= (int)(b); i++)
#define rfo(i, a ,b) for(int i = (int)(a); i >= (int)(b); i--)

using namespace std;

/* Function to find is a sentence is a palindrome */
int palindrome(string A) {

    int i = 0, j = A.size() - 1;
    int left_len = 0, right_len = 0;


    while (i < j) {

        while (!isalnum(A[i]) && i < A.size()) {
            i++;
        }

        while (!isalnum(A[j]) && j > 0) {
            j--;
        }

        if (i > j && left_len == right_len) {
            return 1;
        }

        A[i] = tolower(A[i]);
        A[j] = tolower(A[j]);
        if (A[i] == A[j]) {
            i++;
            j--;
            left_len++;
            right_len++;
        } else {
            return 0;
        }

    }

    if (left_len == right_len) {
        return 1;
    }

    return 0;
}

/* Driver to test the above function */
int main(int argc, char const *argv[])
{
    string str = ",.";
    cout << palindrome(str) << "\n";
    return 0;
}

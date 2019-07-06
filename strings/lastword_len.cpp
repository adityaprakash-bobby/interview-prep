#include <iostream>
#include <string>
#include <locale>
#define fo(i, a ,b) for(int i = (int)(a); i <= (int)(b); i++)
#define rfo(i, a ,b) for(int i = (int)(a); i >= (int)(b); i--)

using namespace std;

/* Function to return the length of the last word in the line */
int lenLastWord(const string A) {

    int length = 0;
    int last_ptr = A.size() - 1;

    // Point the pointer to the last alphabet in the string
    while (!isalpha(A[last_ptr]) && last_ptr > 0) {
        last_ptr--;
    }

    // Increment length for the alphabets that are encountered
    while (isalpha(A[last_ptr--])) {
        length++;
    }

    return length;
}

/* Driver to test the above function */
int main(int argc, char const *argv[])
{
    string line = "    ";
    cout << lenLastWord(line) << endl;
    return 0;
}
#include <iostream>
#include <string>
#define MOD 10003

using namespace std;

/* Count number of sub-strings staring with a vowel */
int amazeSubstr(string A) {

    int res = 0;

    for (int i = 0; i < A.length(); i++) {

        if (A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || \
            A[i] == 'u' || A[i] == 'A' || A[i] == 'E' || A[i] == 'I' || \
            A[i] == 'O' || A[i] == 'U') {
            res += (A.length() - i) % MOD;
                
        }

    }

    return res % MOD;

}

/* Driver to test the above function */
int main(int argc, char const *argv[])
{
    string test = "ABEC";
    cout << amazeSubstr(test) << endl;
    return 0;
}
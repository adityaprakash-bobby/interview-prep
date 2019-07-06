#include <iostream>
#include <map>
#include <string>
#define fo(i, a ,b) for(int i = (int)(a); i <= (int)(b); i++)
#define rfo(i, a ,b) for(int i = (int)(a); i >= (int)(b); i--)

using namespace std;

/* Function to return the integer from roman form */
int romanNumber(string A) {

    map<char, int> map_lit;
    map_lit.insert({'I', 1});
    map_lit.insert({'V', 5});
    map_lit.insert({'X', 10});
    map_lit.insert({'L', 50});
    map_lit.insert({'C', 100});
    map_lit.insert({'D', 500});
    map_lit.insert({'M', 1000});

    int num = 0;

    // Add the number if the successive digit is smaller or equal to the
    // current digit, else substract it.
    for (int i = 0; i < A.size() - 1; i++) {

        if (map_lit[A[i]] >= map_lit[A[i+1]]) {
            num += map_lit[A[i]];
        } else {
            num -= map_lit[A[i]];
        }

    }

    // Add the last digit to the number
    num += map_lit[A[A.size() - 1]];

    return num;

}

/* Driver to test the above function */
int main(int argc, char const *argv[])
{
    string roman = "DCCLXXXIX";
    cout << romanNumber(roman) << endl;
    return 0;
}
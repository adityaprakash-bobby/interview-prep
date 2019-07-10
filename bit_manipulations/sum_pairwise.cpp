#include <iostream>
#include <vector>
#define MOD 1000000007

typedef long long int ll;
using namespace std;

/* Function to return pair-wise different bits sum */
int bitSumPairwise(vector<int> A) {

    ll sum = 0, count;

    for (int i = 0; i < 31; i++) {

        count = 0;

        for (int j = 0; j < A.size(); j++) {

            if (A[j] & 1 << i) {
                count++;
            }

        }
        
        sum += ((2*count*(A.size() - count)));
        sum = sum % MOD;
    }

    return sum % MOD;
}

/* Driver program to test the above function */
int main(int argc, char const *argv[])
{
    vector<int> test = {1, 3, 5};
    cout << bitSumPairwise(test) << endl;
    return 0;
}
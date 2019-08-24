#include <iostream>
#include <vector>

using namespace std;

bool subsetSum(vector<int> A, int sum) {

    int size = A.size();
    vector<vector<bool>> subset (size + 1, vector<bool> (sum + 1));

    for (int i = 0; i <= size; i++) {
        subset[i][0] = true;
    }
    
    for (int j = 0; j <= sum; j++) {
        subset[0][j] = false;
    }

    for (int i = 1; i <= size; i++) {

        for (int j = 1; j <= sum; j++) {

            if (subset[i-1][j] == true) {
                subset[i][j] = true;
            } else {

                if (A[i-1] > j) {
                    subset[i][j] = false;
                } else {
                    subset[i][j] = subset[i-1][j-A[i-1]];
                }

            }
            
        }

    }

    return subset[size][sum];
}

int main(int argc, char const *argv[])
{
    vector<int> test = {1, 2, 3};
    int sum = 0;

    cout << subsetSum(test, sum) << endl;

    return 0;
}
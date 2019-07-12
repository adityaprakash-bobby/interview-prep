/* Load required header files */
#include <iostream>
#include <vector>

using namespace std;

/* Pre-processors and typedef constants */
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fo(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define rfo(i, a, b) for (int i = (int)(a); i >= (int)(b); i--)

/* 
    Function to return whether an element is found in the row-wise and column-
    wise sorted matrix
*/
int matrixSearch(vector<vector<int>> A, int key) {

    int i = 0, j = A[0].size() - 1;

    if (key < A[0][0] || key > A[A.size() - 1][A[0].size() - 1]) {
        return 0;
    }

    while (i < A.size() && j >= 0) {

        if (A[i][j] == key) {
            return 1;
        } else if (A[i][j] > key) {
            j--;
        } else {
            i++;
        }

    }
    
    return 0;
}

/* Driver to test the above function */
int main(int argc, char const *argv[])
{   
    IOS;
    /* Initialize test variables and call your code function here */
    int key = 16;
    vector<vector<int>> test = {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,35}
    };

    cout << matrixSearch(test, key) << endl;
    
    return 0;
}
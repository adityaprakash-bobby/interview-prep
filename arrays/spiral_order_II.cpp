#include <iostream>
#include <vector>
#define fo(i, a, b) for(int i = (int)(a); i <= (int)(b); i++)
#define rfo(i, a, b) for(int i = (int)(a); i >= (int)(b); i--)

using namespace std;

/* Function to return a spiral order matrix */
vector<vector<int>> spiralOrderII(int n) {

    vector<vector<int>> res (n, vector<int> (n, 0));
    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = n - 1;
    int num = 1;

    while (top <= bottom && left <= right) {
        
        fo(i, left, right) {
            res[top][i] = num;
            num++;
        }
        top++;

        fo(i, top, bottom) {
            res[i][right] = num;
            num++;
        }
        right--;

        rfo(i, right, left) {
            res[bottom][i] = num;
            num++;
        }
        bottom--;

        rfo(i, bottom, top) {
            res[i][left] = num;
            num++;
        }
        left++;
    
    }

    return res;

}

/* Driver to test the above function */
int main(int argc, char const *argv[])
{
    int n = 5;
    vector<vector<int>> res = spiralOrderII(n);

    fo(i, 0, n-1) {
        fo(j, 0, n-1) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
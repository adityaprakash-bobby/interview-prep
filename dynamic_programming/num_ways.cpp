#include <iostream>
#include <vector>
#define fo(i, a, b) for(int i = (int)(a); i <= (int)(b); i++)
#define rfo(i, a, b) for(int i = (int)(a); i >= (int)(b); i--)

using namespace std;

/* Function to find the number of ways of travelling from (0,0) to (m-1,n-1) */
int numWays(int M, int N) {

    vector<vector<int>> min_ways (M, vector<int>(N, -1));

    // Assign the minimum cost for 1st cell
    min_ways[0][0] = 1;

    // Fill the ways of travelling the 1st row from (0,0)
    fo(j, 1, N - 1) {
        min_ways[0][j] = 1;
    }

    // FIll the ways of travelling the 1st column from (0,0)
    fo(i, 1, M - 1) {
        min_ways[i][0] = 1;
    }

    // Fill the costs for the rest of the cells
    fo(i, 1, M - 1) {
        fo(j, 1, N - 1) {
            min_ways[i][j] = min_ways[i][j-1] + min_ways[i-1][j];
        }
    }

    return min_ways[M - 1][N - 1];
}

/* Driver to test the above function */
int main(int argc, char const *argv[])
{
    int M = 3, N = 3;

    cout << numWays(M, N) << endl;

    return 0;
}
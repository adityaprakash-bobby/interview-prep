#include <iostream>
#include <vector>
#define fo(i, a, b) for(int i = (int)(a); i <= (int)(b); i++)
#define rfo(i, a, b) for(int i = (int)(a); i >= (int)(b); i--)

using namespace std;

/* 
    Function to find number of ways to reach from 0,0 to m-1,n-1 if P points
    are blocked
*/
int numWaysBlocked(int M, int N, vector<pair<int, int>> P) {

    vector<vector<int>> num_ways (M, vector<int> (N, 0));

    // Mark the given points blocked
    fo(i, 0, P.size() - 1) {
        num_ways[P[i].first][P[i].second] = -1;
    }   

    // Case to handle if the starting point is itself unreachable
    if (num_ways[0][0] == -1) {
        return 0;
    }

    // Now fill the 1st row with 1 till it reaches any unreachable cell
    fo(j, 1, N-1) {
        if (num_ways[0][j] == -1) {
            break;
        }
        num_ways[0][j] = 1;
    }

    // Like-wise fill the 1st column till it reaches any blocked cell
    fo(i, 1, M-1) {
        if (num_ways[i][0] == -1) {
            break;
        }
        num_ways[i][0] = 1;
    }

    // Now fill the rest of the cells with their values
    fo(i, 1, M-1) {
        fo(j, 1, N-1) {

            if (num_ways[i][j]) {
                continue;
            }

            if (num_ways[i][j-1] > 0) {
                num_ways[i][j] += num_ways[i][j-1];
            }

            if (num_ways[i-1][j] > 0) {
                num_ways[i][j] += num_ways[i-1][j];
            }

        }
    }

    return (num_ways[M-1][N-1]>=0?num_ways[M-1][N-1]:0);
}

/* Driver to test the function */
int main(int argc, char const *argv[])
{
    int M, N, P;
    int i, j;
    vector<pair<int, int>> blocked_points;
    
    cin >> M >> N >> P;
    fo(i, 0, P-1) {
        cin >> i >> j;
        blocked_points.push_back(make_pair(i, j));
    }

    cout << numWaysBlocked(M, N, blocked_points);

    return 0;
}

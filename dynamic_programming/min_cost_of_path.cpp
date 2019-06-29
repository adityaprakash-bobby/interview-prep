#include <iostream>
#include <vector>
#define fo(i, a, b) for(int i = (int)(a); i <= (int)(b); i++)
#define rfo(i, a, b) for(int i = (int)(a); i >= (int)(b); i--)

using namespace std;

/* Function to find the minimum cost of travelling from (0,0) to (m-1,n-1) */
int minCostPath(vector<vector<int>> cost) {

    vector<vector<int>> min_cost (cost.size(), vector<int>(cost[0].size(), -1));

    // Assign the minimum cost for 1st cell
    min_cost[0][0] = cost[0][0];

    // Fill the costs of travelling the 1st row from (0,0)
    fo(j, 1, cost[0].size() - 1) {
        min_cost[0][j] = min_cost[0][j-1] + cost[0][j];
    }

    // FIll the costs of travelling the 1st column from (0,0)
    fo(i, 1, cost.size() - 1) {
        min_cost[i][0] = min_cost[i-1][0] + cost[i][0];
    }

    // Fill the costs for the rest of the cells
    fo(i, 1, cost.size() - 1) {
        fo(j, 1, cost[i].size() - 1) {
            min_cost[i][j] = min(min_cost[i][j-1], min_cost[i-1][j]) + cost[i][j];
        }
    }

    return min_cost[cost.size() - 1][cost[0].size() - 1];
}

/* Driver to test the above function */
int main(int argc, char const *argv[])
{
    vector<vector<int>> cost = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    cout << minCostPath(cost);

    return 0;
}

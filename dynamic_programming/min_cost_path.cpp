#include <bits/stdc++.h>

using namespace std;

int min(int a, int b, int c) {
    if (a < b)
        return (a < c)? a : c;
    else
        return (b < c)? b : c;
}

int getMinCost(vector<vector<int>> cost, int m, int n) {
    vector<vector<int>> minCost(m, vector<int>(n, 0));

    if (m == 0 and n == 0) {
        return INT_MAX;
    }

    minCost[0][0] = cost[0][0];

    for (int j = 0; j < n; j++) {
        minCost[0][j] = cost[0][j] + minCost[0][j-1];
    }

    for (int i = 0; i < n; i++) {
        minCost[i][0] = cost[i][0] + minCost[i-1][0];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            minCost[i][j] = cost[i][j] + min(minCost[i-1][j], minCost[i-1][j-1], minCost[i][j-1]);
        }
    }

    return minCost[m-1][n-1];
}

int main() {
    vector<vector<int>> vec{ {1, 2, 3},
        {4, 8, 2},
        {1, 5, 3} };
    cout << getMinCost(vec, 3, 3);
}
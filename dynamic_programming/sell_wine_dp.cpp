#include <iostream>
#include <vector>
#define N 1000

using namespace std;

int memo[N][N];

/* Recursive utility for maximization function */
int maximize_sale_util(int P[], int beg, int end, int n) {

    if (beg > end) {
        return 0;
    }

    if (memo[beg][end] != -1) {
        return memo[beg][end];
    }

    int year = n - (end-beg+1) + 1;

    memo[beg][end] = max(
        maximize_sale_util(P, beg+1, end, n) + year*P[beg],
        maximize_sale_util(P, beg, end-1, n) + year*P[end]
    );

    return memo[beg][end];
}

/* Function to return the mazimum value of wine sale */
int maximize_sale(int P[], int n) {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) { 
            memo[i][j] = -1;
        }
    }

    return maximize_sale_util(P, 0, n-1, n);
}

/* Driver to test the above code */
int main(int argc, char const *argv[])
{

    int wines[5] = {2, 3, 5, 1, 4};
    cout << maximize_sale(wines, 5) << endl;
    return 0;
}

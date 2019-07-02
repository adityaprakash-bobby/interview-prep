#include <iostream>
#include <vector>
#define fo(i, a, b) for(int i = (int)(a); i <= (int)(b); i++)
#define rfo(i, a, b) for(int i = (int)(a); i >= (int)(b); i--)

using namespace std;

int minCoinBottomUp(int total_sum, vector<int> coins) {

    vector<int> min_coins (total_sum + 1, INT32_MAX);
    min_coins[0] = 0;

    fo(i, 0, coins.size() - 1) {

        fo(j, 1, total_sum) {

            if (coins[i] <= j) {
            
                if (min_coins[j - coins[i]] + 1 < min_coins[j]) {
                    min_coins[j] = min_coins[j - coins[i]] + 1;
                }

            }

        } 

    }

    return min_coins[total_sum];
}

int main(int argc, char const *argv[])
{
    vector<int> coins = {1, 3, 5};
    int sum = 11;

    cout << minCoinBottomUp(sum, coins) << endl;

    return 0;
}
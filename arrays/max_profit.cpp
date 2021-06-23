#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int> &prices)
{
    int lenPrices = prices.size();
    int totalProfit = 0;

    for (int i = 0; i < lenPrices - 1; i++)
    {
        if (prices[i] < prices[i+1])
        {
            totalProfit += prices[i+1] - prices[i];
        }
    }

    return totalProfit;
}

int main()
{
    vector<int> prices{1, 2};
    cout << maxProfit(prices) << endl;
}
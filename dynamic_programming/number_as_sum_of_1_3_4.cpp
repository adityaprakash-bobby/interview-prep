#include <iostream>
#include <vector>

using namespace std;

/* 
    Function to return the number of ways a number can be represented as the
    sum of number 1, 3 and 4.  
*/
int num_ways_sum(int N) {

    vector<int> DP;
    DP.push_back(1); // 0 can be represeneted as sum of 1,3,4 in 1 ways
    DP.push_back(1); // 1 can be represeneted as sum of 1,3,4 in 1 ways
    DP.push_back(1); // 1 can be represeneted as sum of 1,3,4 in 1 ways
    DP.push_back(2); // 3 can be represeneted as sum of 1,3,4 in 2 ways

    for (int i = 4; i <= N; i++) {
        DP.push_back(DP[i-1] + DP[i-3] + DP[i-4]);
    }

    return DP[N];
}

/* Driver to test the function */
int main(int argc, char const *argv[])
{
    int number = 9;
    cout << num_ways_sum(number) << endl;    
    return 0;
}

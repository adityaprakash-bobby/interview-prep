#include <iostream>
#include <vector>
#include <climits>
#define fo(i, a, b) for(int i = (int)(a); i <= (int)(b); i++)
#define rfo(i, a, b) for(int i = (int)(a); i >= (int)(b); i--)

using namespace std;

/* Function to return the maximum contiguous array sum */
int maxContiguousArray(vector<int> &A) {
    
    int max_sum = INT_MIN;
    int max_curr = 0;
    
    fo(i, 0, A.size() - 1) {
        
        max_curr += A[i];
        
        if (max_sum < max_curr) {
            max_sum = max_curr;
        }
        
        if (max_curr < 0) {
            max_curr = 0;
        }
        
    }
    
    return max_sum;
}

/* Driver to test the above function */
int main(int argc, char const *argv[])
{
    vector<int> test = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxContiguousArray(test) << endl;
    return 0;
}
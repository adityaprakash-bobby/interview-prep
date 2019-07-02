#include <iostream>
#include <vector>
#define fo(i, a, b) for(int i = (int)(a); i <= (int)(b); i++)
#define rfo(i, a, b) for(int i = (int)(a); i >= (int)(b); i--)
typedef long long int ll;

using namespace std;

vector<int> maxNonNegativeSubArray(vector<int> &A) {

    vector<int> ret_array;
    vector<vector<ll>> res;
    vector<ll> temp;
    ll arr_sum = 0, largest_index = 0;

    // Push all positive subarray into a array of vectors. At the end of each
    // vector being pushed, the last element comprises of the sum of all the 
    // elements in the sub-array
    fo(i, 0, A.size()-1) {
        
        if (A[i] >= 0) {

            temp.push_back(A[i]);
            arr_sum += A[i];
        
        } else if (A[i] < 0) {
                    
            temp.push_back(arr_sum);
            res.push_back(temp);
            temp.clear();
            arr_sum = 0;

        }

    }
    
    // Push the last positive sub-array
    temp.push_back(arr_sum);
    res.push_back(temp);

    // Initialize the 1st sub-array as the largest (result)
    ll large_sum = res[0].back();
    vector<ll> large_arr = res[0];

    // Iterate over all the sub-arrays and find the array with the most number
    // elements having the smallest index and max number of elements
    fo(i, 0, res.size()-1) {

        if (large_sum < res[i].back()) {
            
            large_arr = res[i];
            large_sum = res[i].back();
            largest_index = i;
        
        } else if (large_sum == res[i].back()) {

            if (large_arr.size() < res[i].size()) {

                large_arr = res[i];
                large_sum = res[i].back();
                largest_index = i;
                 
            } else if (large_arr.size() == res[i].size()) {

                large_arr = res[i];
                large_sum = res[i].back();
                
                if (largest_index > i) {
                    largest_index = i;
                }

            }

        }

    } 

    ret_array.assign(res[largest_index].begin(), res[largest_index].end() - 1);
    return ret_array;
}

int main(int argc, char const *argv[])
{

    vector<int> arr = {1967513926, 1540383426, -1303455736, -521595368};
    vector<int> res = maxNonNegativeSubArray(arr);
    
    fo(i, 0, res.size() - 1) {
        cout << res[i] << endl;
    }

    return 0;
}

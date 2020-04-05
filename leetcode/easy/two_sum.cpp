#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int arr_len = nums.size();

        for (int i = 0; i < arr_len; i++) {
            vector<int> temp;
        
            for (int j = i+1; j < arr_len; j++) {
                if(nums[i] + nums[j] == target) {
                    temp.push_back(i);
                    temp.push_back(j);
                    return temp;
                }
            }
            if (temp.size() == 2) {
                break;
            }
        } 

        return res;
    }
};
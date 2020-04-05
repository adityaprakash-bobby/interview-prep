#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int complement_num;
        int arr_len = nums.size();
        
        vector<int> res;
        unordered_map<int, int> seen;
        
        for (int i = 0; i < arr_len; i++) {
            complement_num = target - nums[i];
            
            if (seen.find(complement_num) != seen.end()) {
                res.push_back(seen.find(complement_num)->second);
                res.push_back(i);
        
                return res;
            }
            
            seen.emplace(nums[i], i);
        }
        
        return res;
    }

};
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> result;

        for (int i = 0; i < nums.size(); i += 2) {
            vector<int> temp (nums[i], nums[i+1]);
            result.insert(result.end(), temp.begin(), temp.end());
        }
        
        return result;
    }
};

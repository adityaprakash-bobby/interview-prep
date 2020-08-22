class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        int prevSum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = prevSum + nums[i];
            prevSum = nums[i];
        }
        
        return nums;
    }
};

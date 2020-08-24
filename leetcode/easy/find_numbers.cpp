class Solution {
public:
    int getDigits(int num) {
        int digits = 0;
        while (num > 0) {
            digits++;
            num /= 10;
        }
        return digits;
    }
    
    int findNumbers(vector<int>& nums) {
        int res = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (getDigits(nums[i]) % 2 == 0) {
                res++;
            }
        }
        
        return res;
    }
};

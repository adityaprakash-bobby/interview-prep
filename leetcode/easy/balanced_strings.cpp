class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0;
        int res = 0;
        
        for (auto it = s.begin(); it < s.end(); it++) {
            if (*it == 'R') {
                count++;
            } else if (*it == 'L') {
                count--;
            }
            
            if (count == 0) {
                res++;
            }
        }
        
        return res;
    }
};

class Solution {
public:
    int xorOperation(int n, int start) {
        int cacheStart = start;

        for (int i = 1; i < n; i++) {
            start ^= cacheStart + 2*i;
        }
        
        return start;
    }
};

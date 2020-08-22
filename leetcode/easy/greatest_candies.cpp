class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        int highestThen = *max_element(candies.begin(), candies.end());
        int arrSize = candies.size();
        vector<bool> canHaveGreatest (arrSize);

        for (int i = 0; i < arrSize; i++) {
            if (candies[i] + extraCandies >= highestThen) {
                canHaveGreatest[i] = true;
            }
        }
        
        return canHaveGreatest;
    }
};

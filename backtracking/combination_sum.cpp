#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void combinationRecurseUtil(vector<int>& candidates, int target, vector<vector<int>> &result, int idx, vector<int> &combination) {
        if (target == 0) {
            result.push_back(combination);
            return;
        }

        // till the sum is yet to be arrived at; start is also within limits
        while (idx < candidates.size() && target - candidates[idx] >= 0) {
            combination.push_back(candidates[idx]);
            combinationRecurseUtil(candidates, target - candidates[idx], result, idx, combination);
            idx++;
            combination.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> combination;
        vector<vector<int>> combinations;
        combinationRecurseUtil(candidates, target, combinations, 0, combination);

        return combinations;
    }
};
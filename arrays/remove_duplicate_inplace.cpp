#include <bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int> &nums) {
    int lastIdx = -1;
    int lastNum = INT_MIN;
    int temp;

    for (int i = 0; i < nums.size(); i++) {
        // if current number is bigger than last seen number,
        // swap the number and update the last seen
        if (nums[i] > lastNum) {
            ++lastIdx;
            temp = nums[i];
            nums[i] = nums[lastIdx];
            nums[lastIdx] = temp;
            lastNum = temp;
        }
    }

    return lastIdx++ + 1; // return the slots taken up
}

int main() {
    vector<int> arr {1,1,2};
    cout << removeDuplicates(arr) << endl;
}
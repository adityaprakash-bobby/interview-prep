#include <bits/stdc++.h>

using namespace std;

void reverse(vector<int> &nums, int start, int end)
{
    while (start < end)
    {
        nums[start] = nums[start] ^ nums[end];
        nums[end] = nums[start] ^ nums[end];
        nums[start] = nums[start] ^ nums[end];

        start++;
        end--;
    }
}

void rotate(vector<int> &nums, int k)
{
    int size = nums.size();
    k %= size;

    reverse(nums, 0, size - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, size - 1);
}

int main()
{
    vector<int> arr{1, 2, 3, 5, 6, 7, 8, 9};
    int k = 4;
    rotate(arr, k);

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
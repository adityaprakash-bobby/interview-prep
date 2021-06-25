from typing import List

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        numIdx = 0

        for i, num in enumerate(nums):
            if num != 0:
                nums[i] = 0
                nums[numIdx] = num
                numIdx += 1

from typing import List

class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        size = len(arr)
        start = 0
        end = k - 1

        for i in range(k, size):
            if (abs(arr[start] - x) > abs(arr[i] - x)) or \
                    (abs(arr[start] - x) == abs(arr[i] - x) and arr[start] == arr[i]):
                start += 1
                end += 1

        return arr[start:end+1]

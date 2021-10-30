from typing import List

def min_k_sum(arr: List[int], k: int) -> int:
    max_sum = 0
    window_sum = 0

    # if k is greater than lenth of array then window will not
    # make any sense
    if k > len(arr):
        return 0

    # calculate the first window sum
    for i in range(0, k):
        window_sum += arr[i]

    # check and assign the sum to max if greater
    max_sum = max(max_sum, window_sum)

    # slide the window by 1 till end on the list 
    # and set the max
    for i in range(k, len(arr)):
        window_sum += (arr[i] - arr[i-k])
        max_sum = max(max_sum, window_sum)

    return max_sum

if __name__ == "__main__":
    test_arr = [1, 2, 3, 4, 5, 6]
    k = 4

    max_sum = min_k_sum(test_arr, k)
    print(max_sum)
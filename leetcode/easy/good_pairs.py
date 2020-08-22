class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        visited = dict()
        good_pairs = 0
        
        # get a map of number of elements of each value
        for num in nums:
            if num in visited:
                visited[num] += 1
            else:
                visited[num] = 1
                
        for v in visited:
            good_pairs += visited[v]*(visited[v]-1)//2
            
        return good_pairs

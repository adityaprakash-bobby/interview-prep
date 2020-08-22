func numIdenticalPairs(nums []int) int {
    v := make(map[int]int)
    goodPairs := 0
    
    for _, val := range nums {
        if _, found := v[val]; found {
            v[val] += 1
        } else {
            v[val] = 1
        }
    }

    for _, val := range v {
        goodPairs += val*(val-1)/2
    }
    
    return goodPairs
}

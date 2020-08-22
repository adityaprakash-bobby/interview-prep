func maxProduct(nums []int) int {
    largest := 0
    secondLargest := 0
    
    for _, val := range nums {
        if val > largest {
            secondLargest, largest = largest, val
        } else if val > secondLargest {
            secondLargest = val
        } 
    }
    
    return (largest-1) * (secondLargest-1)
}

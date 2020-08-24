package main

import (
	"fmt"
)

func HasPairWithSum(data []int, sum int) bool {
	seen := make( map[int]bool)

	for _, num := range data {
		comp := sum - num

		if _, found := seen[num]; found {
			return true
		} else {
			seen[comp] = true
		}
	}

	return false
}

func main() {
	testData := []int{1, 3, 4, 5}
	testSum := 4

	fmt.Println(HasPairWithSum(testData, testSum))
}

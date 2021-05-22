package main

import "fmt"

func AllOnesKPlacesAway(arr []int, k int) bool {
	last1 := -1
	distance := -1

	for i, val := range arr {
		// check for 1s or 0s
		if val == 1 {
			// if last seen 1 is present, then calculate the distance and check
			// if the 1's are k places away, else just update the last1
			if last1 != -1 {
				if distance = i - last1; distance <= k {
					return false
				}
			}

			last1 = i
		}
	}

	// return false if there is not atleast 2 1s
	return true && (last1 != -1 && distance != -1)
}

func main() {
	arr := []int{0, 1, 0, 0, 0, 1, 0, 0, 1}
	k := 2

	fmt.Printf("Are all 1s in %v %v places away? %v", arr, k, AllOnesKPlacesAway(arr, k))
}

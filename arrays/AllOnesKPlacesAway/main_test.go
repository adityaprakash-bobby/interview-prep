package main

import "testing"

func TestForArraysStartingNotWith1(t *testing.T) {
	arr := []int{0, 1, 0, 0, 1, 0, 0, 0, 1}
	k := 2
	want := true

	result := AllOnesKPlacesAway(arr, k)

	if result == false {
		t.Fatalf(`TestForArraysStartingNotWith1(%v, %v) = %v, want %v`, arr, k, result, want)
	}

}

func TestForArrayWithOnly0s(t *testing.T) {
	arr := []int{0, 0, 0, 0, 0}
	k := 2
	want := false

	result := AllOnesKPlacesAway(arr, k)

	if result == true {
		t.Fatalf(`TestForArraysStartingNotWith1(%v, %v) = %v, want %v`, arr, k, result, want)
	}
}

func TestForArrayWithOnlyOne1(t *testing.T) {
	arr := []int{0, 0, 0, 1, 0}
	k := 2
	want := false

	result := AllOnesKPlacesAway(arr, k)

	if result == true {
		t.Fatalf(`TestForArraysStartingNotWith1(%v, %v) = %v, want %v`, arr, k, result, want)
	}
}

func TestForNormalTrueReturn(t *testing.T) {
	arr := []int{0, 1, 0, 0, 0, 1, 0, 0, 1}
	k := 2
	want := true

	result := AllOnesKPlacesAway(arr, k)

	if result == false {
		t.Fatalf(`TestForArraysStartingNotWith1(%v, %v) = %v, want %v`, arr, k, result, want)
	}
}

func TestForNormalFalseReturn(t *testing.T) {
	arr := []int{0, 1, 0, 0, 0, 1, 0, 0, 1}
	k := 4
	want := false

	result := AllOnesKPlacesAway(arr, k)

	if result == true {
		t.Fatalf(`TestForArraysStartingNotWith1(%v, %v) = %v, want %v`, arr, k, result, want)
	}
}

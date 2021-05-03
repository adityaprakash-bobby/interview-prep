package main

import "fmt"

type TwoStacks struct {
	data        []int
	size        int
	left, right int
}

func NewTwoStack(size int) *TwoStacks {
	return &TwoStacks{
		data:  make([]int, size),
		size:  size,
		left:  -1,
		right: size,
	}
}

func (st *TwoStacks) pop1() (int, error) {
	if st.left == -1 {
		return -1, fmt.Errorf("Stack Underflow")
	}

	poppedElement := st.data[st.left]
	st.left--

	return poppedElement, nil
}

func (st *TwoStacks) pop2() (int, error) {
	if st.right == st.size {
		return -1, fmt.Errorf("Stack Underflow")
	}

	poppedElement := st.data[st.right]
	st.right++

	return poppedElement, nil
}

func (st *TwoStacks) push1(element int) error {
	if st.left+1 == st.right {
		return fmt.Errorf("Stack Overflow")
	}

	st.left++
	st.data[st.left] = element

	return nil
}

func (st *TwoStacks) push2(element int) error {
	if st.right-1 == st.left {
		return fmt.Errorf("Stack Overflow")
	}

	st.right--
	st.data[st.right] = element

	return nil
}

func main() {
	ts := NewTwoStack(4)

	err := ts.push1(5)
	if err != nil {
		fmt.Println(err)
	}

	err = ts.push2(10)
	if err != nil {
		fmt.Println(err)
	}

	err = ts.push2(15)
	if err != nil {
		fmt.Println(err)
	}

	err = ts.push1(11)
	if err != nil {
		fmt.Println(err)
	}

	err = ts.push2(7)
	if err != nil {
		fmt.Println(err)
	}

	pop1Element, err := ts.pop1()
	if err != nil {
		fmt.Println(err)
	} else {
		fmt.Printf("The popped element is %d\n", pop1Element)
	}

	pop2Element, err := ts.pop2()
	if err != nil {
		fmt.Println(err)
	} else {
		fmt.Printf("The popped element is %d\n", pop2Element)
	}
}

package main

import "fmt"

type Stack struct {
	data []rune
}

func (s Stack) isEmpty() bool {
	return len(s.data) == 0
}

func (s *Stack) push(element rune) {
	s.data = append(s.data, element)
}

func (s *Stack) pop() (rune, error) {
	if s.isEmpty() {
		return -1, fmt.Errorf("Stack underflow")
	}

	poppedElement := s.data[len(s.data)-1]
	s.data = s.data[:len(s.data)-1]

	return poppedElement, nil
}

func BalancedParentheis(str string) bool {
	var stack Stack

	for _, char := range str {
		// if the char is one of '{', '[' or '(', then push to the stack
		if char == '(' || char == '{' || char == '[' {
			stack.push(char)
			continue
		}

		// if it is not a opening bracket, check if the stack is empty else
		// proceed with the further checks
		if stack.isEmpty() {
			return false
		}

		switch char {
		case ')':
			top, _ := stack.pop()

			if top != '(' {
				return false
			}
		case ']':
			top, _ := stack.pop()

			if top != '[' {
				return false
			}
		case '}':
			top, _ := stack.pop()

			if top != '{' {
				return false
			}
		}

	}

	return stack.isEmpty()
}

func main() {
	str := "{[()]}()()"
	isBalanced := BalancedParentheis(str)
	fmt.Printf("The string is balanced: %v", isBalanced)
}

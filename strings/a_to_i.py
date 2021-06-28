from typing import Tuple


class Solution:
    def __clamp(self, num: int) -> int:
        uBound = 2**31 - 1
        lBound = -1 * 2**31

        if num >= uBound:
            return uBound

        if num <= lBound:
            return lBound

        return num

    def __getDigit(self, char: str) -> Tuple[int, bool]:
        if char >= '0' and char <= '9':
            return int(char), True

        return char, False

    def myAtoi(self, s: str) -> int:
        # trim leading space
        num = 0
        size = len(s)
        ptr = 0

        while ptr < size:
            if s[ptr] == " ":
                ptr += 1
            else:
                break

        if ptr == size:
            return 0

        sign = 1

        if s[ptr] == "-":
            ptr += 1
            sign = -1
        elif s[ptr] == "+":
            ptr += 1

        while ptr < size:
            digit, isDigit = self.__getDigit(s[ptr])
            if not isDigit:
                break
            num = num * 10 + digit
            ptr += 1

        return self.__clamp(num * sign)

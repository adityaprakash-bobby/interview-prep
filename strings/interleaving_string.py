from typing import List


def toString(iStr: List) -> str:
    return "".join(iStr)


def interleavingStrRecurseUtil(
    str1: str, str2: str, iStr: List, m: int, n: int, i: int
) -> str:
    # no elements are present in either of the strings
    if m == 0 and n == 0:
        print(toString(iStr))

    # elements present in the the first string
    if m != 0:
        iStr[i] = str1[0]
        interleavingStrRecurseUtil(str1[1:], str2, iStr, m - 1, n, i + 1)

    # elements preset in the second string
    if n != 0:
        iStr[i] = str2[0]
        interleavingStrRecurseUtil(str1, str2[1:], iStr, m, n - 1, i + 1)


def interleavingString(str1: str, str2: str) -> str:
    iStr = [""]*(len(str1) + len(str2))

    interleavingStrRecurseUtil(str1, str2, iStr, len(str1), len(str2), 0)

if __name__ == "__main__":
    str1 = "AB"
    str2 = "CD"

    interleavingString(str1, str2)
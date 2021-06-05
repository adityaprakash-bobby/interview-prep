def countDecodings(digits: str, len: int) -> int:
    # traverse from the end of the digit string
    # 1. check the length, if 0 or 1 add to one decoding
    # 2. check for the last character
    # 3. check for the last to characters
    # recurse the string in sub-problems

    # base case
    if len == 0 or len == 1:
        return 1

    if digits[0] == "0":
        return 0

    count = 0
    # check the last character, if it's mot 1 we can recurse
    if digits[len - 1] > "0":
        count = countDecodings(digits, len - 1)

    if digits[len - 2] == "1" or \
        (digits[len - 2] == "2" and digits[len - 1] < "7"):
        count += countDecodings(digits, len - 2)

    return count


def countDecodingsDP(digits: str, len: int) -> int:
    count = [0] * (len + 1)

    # base case
    count[0] = 1
    count[1] = 1

    for i in range(2, len + 1):
        if digits[i - 1] > "0":
            count[i] = count[i - 1]

        if digits[i - 2] == "1" or \
            (digits[i - 2] == "2" and digits[i - 1] < "7"):
            count[i] += count[i - 2]

    return count[len]

if __name__ == "__main__":
    digitStr = "1234"
    print(f"Number of ways to get decodings: {countDecodings(digitStr, len(digitStr))}")
    print(f"Number of ways to get decodings (DP): {countDecodingsDP(digitStr, len(digitStr))}")


from typing import List


def catchMaxThief(arr: List[str], k: int) -> int:
    police = list()
    thief = list()

    for idx, person in enumerate(arr):
        if person == "p":
            police.append(idx)
        else:
            thief.append(idx)

    maxThiefCaught = 0

    atPolice = 0
    atThief = 0

    while(atPolice < len(police) and atThief < len(thief)):
        if abs(police[atPolice] - thief[atThief]) <= k:
            maxThiefCaught += 1
            atPolice += 1
            atThief += 1
        else:
            atThief += 1

    return maxThiefCaught


if __name__ == "__main__":
    policeThiefArray = ["t", "t", "p", "t", "t"]
    maxTravel = 1

    print(catchMaxThief(policeThiefArray, maxTravel))
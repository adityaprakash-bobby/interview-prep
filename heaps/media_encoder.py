from typing import List
from min_heap import MinHeap

def minTimeEncoding(fileSizes: List[int]) -> int:
    # create a min heap and add all the sizes to it
    minHeap = MinHeap()

    for size in fileSizes:
        minHeap.add(size)

    while not minHeap.isEmpty():
        # pull the least two sizes and add it to the heap until there
        # is only one size left in the heap
        size1 = minHeap.poll()

        if minHeap.isEmpty():
            return size1

        size2 = minHeap.poll()
        mergeTime = size1 + size2
        minHeap.add(mergeTime)

    return 0


if __name__ == "__main__":
    sizes = [8, 4, 6, 12]
    print(f"Min. Time for encoding the file chunks {sizes}: {minTimeEncoding(sizes)}")

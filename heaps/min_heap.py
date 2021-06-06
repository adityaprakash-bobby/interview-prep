class MinHeap:
    def __init__(self) -> None:
        """
        A heap with size and array that holds the actual data for the nodes
        """
        self.__size = 0
        self.__heap = []

    def __repr__(self) -> str:
        """
        repr method
        """
        return str(self.__heap)

    def __getLeftChildIndex(self, index: int) -> int:
        """
        This gets the index of the left child for a node
        """
        return 2*index + 1

    def __getRightChildIndex(self, index: int) -> int:
        """
        This gets the index of the right child for a node
        """
        return 2*index + 2

    def __getParentIndex(self, index: int) -> int:
        """
        This gets the index of the parent node for a node
        """
        if index % 2 == 0:
            return index // 2 - 1

        return index // 2

    def __hasParent(self, index: int) -> bool:
        """
        Tells if a node has a parent or not
        """
        return self.__getParentIndex(index) >= 0

    def __hasLeftChild(self, index: int) -> bool:
        """
        Tells if a node has a left child or not
        """
        return self.__getLeftChildIndex(index) < self.__size

    def __hasRightChild(self, index: int) -> bool:
        """
        Tells if a node has a right child or not
        """
        return self.__getRightChildIndex(index) < self.__size

    def __parent(self, index: int) -> int:
        """
        Returns the value of the parent node for given index
        """
        return self.__heap[self.__getParentIndex(index)]

    def __leftChild(self, index: int) -> int:
        """
        Returns the value of the left child node for given index
        """
        return self.__heap[self.__getLeftChildIndex(index)]

    def __rightChild(self, index: int) -> int:
        """
        Returns the value of the right child node for given index
        """
        return self.__heap[self.__getRightChildIndex(index)]


    def __swap(self, idx1: int, idx2: int) -> None:
        """
        Helper method to swap between two nodes based on their indices
        """
        self.__heap[idx1], self.__heap[idx2] = self.__heap[idx2], self.__heap[idx1]

    def __heapifyUp(self) -> None:
        """
        This heapifies bottom up from the last element from the heap
        """
        curNodeIdx = self.__size - 1

        while self.__hasParent(curNodeIdx) and \
            self.__heap[curNodeIdx] < self.__parent(curNodeIdx):
            # swap the current node and the parent node if smaller
            self.__swap(curNodeIdx, self.__getParentIndex(curNodeIdx))

            # update the current node as the parent node
            curNodeIdx = self.__getParentIndex(curNodeIdx)

    def __heapifyDown(self) -> None:
        """
        This heapifies top to dowm from the root element
        """
        curNodeIndex = 0

        while self.__hasLeftChild(curNodeIndex):
            smallerChildIndex = self.__getLeftChildIndex(curNodeIndex)

            if self.__hasRightChild(curNodeIndex) and \
                self.__rightChild(curNodeIndex) < self.__leftChild(curNodeIndex):
                smallerChildIndex = self.__getRightChildIndex(curNodeIndex)

            if self.__heap[curNodeIndex] > self.__heap[smallerChildIndex]:
                # swap the node with the smaller child
                self.__swap(curNodeIndex, smallerChildIndex)
            else:
                break

            curNodeIndex = smallerChildIndex

    def add(self, num: int) -> None:
        """
        add adds an element into the heap in the right place
        """
        self.__size += 1
        self.__heap.append(num)
        self.__heapifyUp()

    def peek(self) -> int:
        """
        Peek returns the value of the root node - minimum
        """
        if self.__size == 0:
            raise Exception("No elements in the heap")
        return self.__heap[0]

    def poll(self) -> int:
        """
        Poll returns the value of the root node - minimum and removes it from
        the heap
        """
        if self.__size == 0:
            raise Exception("No elements in the heap")

        self.__swap(0, self.__size - 1)
        self.__size -= 1
        minElement = self.__heap.pop()

        self.__heapifyDown()

        return minElement

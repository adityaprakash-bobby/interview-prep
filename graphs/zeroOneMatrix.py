import queue
import sys
from typing import List

dx, dy = [0, 0, -1, 1], [-1, 1, 0, 0]


def zeroOneMatrix(arr: List[List[int]]) -> List[List[int]]:
    distMatrix = [[sys.maxsize for _ in row] for row in arr]
    que = queue.Queue()  # holds cells that are visited once

    for r, row in enumerate(arr):
        for c, data in enumerate(row):
            if data == 0:
                distMatrix[r][c] = 0
                que.put((r, c))

    rows, cols = r + 1, c + 1

    while not que.empty():
        # pop the visited cell and update the neighbouring distances
        curPosR, curPosC = que.get()

        for i in range(4):
            # loop thru' neighbours of the cell
            neighR, neighC = curPosR + dx[i], curPosC + dy[i]
            if neighR >= 0 and neighR < rows and neighC >= 0 and neighC < cols:
                # valid neighbour
                if distMatrix[neighR][neighC] == sys.maxsize:
                    # cell not visited
                    distMatrix[neighR][neighC] = 1 + distMatrix[curPosR][curPosC]
                    que.put((neighR, neighC))

    return distMatrix

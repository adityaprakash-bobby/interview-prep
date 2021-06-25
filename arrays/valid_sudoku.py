from typing import List


class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        # set hashmaps for each block, column and row
        block = {k: set() for k in range(9)}
        row = {k: set() for k in range(9)}
        col = {k: set() for k in range(9)}

        for r in range(9):
            for c in range(9):
                if board[r][c] != '.':
                    # check row
                    if board[r][c] not in row[r]:
                        row[r].add(board[r][c])
                    else:
                        return False

                    # check col
                    if board[r][c] not in col[c]:
                        col[c].add(board[r][c])
                    else:
                        return False

                    # check block
                    b = 3*(r//3)+(c//3)
                    if board[r][c] not in block[b]:
                        block[b].add(board[r][c])
                    else:
                        return False

        return True


if __name__ == '__main__':
    sudokuBoard = [
        ["5", "3", ".", ".", "7", ".", ".", ".", "."],
        ["6", ".", ".", "1", "9", "5", ".", ".", "."],
        [".", "9", "8", ".", ".", ".", ".", "6", "."],
        ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
        ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
        ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
        [".", "6", ".", ".", ".", ".", "2", "8", "."],
        [".", ".", ".", "4", "1", "9", ".", ".", "5"],
        [".", ".", ".", ".", "8", ".", ".", "7", "9"]
    ]
    solution = Solution()
    answer = solution.isValidSudoku(sudokuBoard)

    print(answer)

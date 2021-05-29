from collections import deque

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def deepestLeavesSum(self, root: TreeNode) -> int:
        if not root:
            return 0

        # a queue to hold the nodes
        que = deque([root])
        deepestSum = 0

        # level order traversal and give the sum for the last level
        while que:
            deepestSum = 0
            qSize = len(que)

            for _ in range(qSize):
                node = que.popleft()
                deepestSum += node.val

                if node.left:
                    que.append(node.left)

                if node.right:
                    que.append(node.right)

        return deepestSum

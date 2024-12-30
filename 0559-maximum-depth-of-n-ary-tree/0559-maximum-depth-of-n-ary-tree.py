"""
# Definition for a Node.
class Node:
    def __init__(self, val: Optional[int] = None, children: Optional[List['Node']] = None):
        self.val = val
        self.children = children
"""

class Solution:
    def maxDepth(self, root: 'Node') -> int:
        if not root:
            return 0
        depth = 0
        q = deque([root])
        while q:
            n = len(q)
            depth += 1
            for i in range(n):
                currNode = q.popleft()
                for child in currNode.children:
                    if child:
                        q.append(child)
        return depth
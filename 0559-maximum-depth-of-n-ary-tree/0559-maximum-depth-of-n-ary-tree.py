"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution(object):
    def maxDepth(self, root):
        """
        :type root: Node
        :rtype: int
        """
        if not root:
            return 0

        depth = []
        def dfs(node, dep):
            if not node.children:
                depth.append(dep+1)
            for child in node.children:
                dfs(child, dep+1)

        for c in root.children:
            dfs(c, 1)

        return max(depth)
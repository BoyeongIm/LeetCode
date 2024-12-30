# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def maxDepth(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        if not root:
            return 0
        if not root.left and not root.right:
            return 1
        height = 0
        q = deque([root])
        while q:
            n = len(q)
            height += 1
            for i in range(n):
                currNode = q.popleft()
                if currNode.left:
                    q.append(currNode.left)
                if currNode.right:
                    q.append(currNode.right)
        return height
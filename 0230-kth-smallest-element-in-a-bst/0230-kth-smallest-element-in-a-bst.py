# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution(object):
    def _DFT_inorderHelp(self, currNode, k):
        if not currNode:
            return 
        left = self._DFT_inorderHelp(currNode.left, k)
        if left is not None:
            return left
        self.order += 1
        if self.order == k:
            return currNode.val
        return self._DFT_inorderHelp(currNode.right, k)

    def kthSmallest(self, root, k):
        self.order = 0
        return self._DFT_inorderHelp(root, k)
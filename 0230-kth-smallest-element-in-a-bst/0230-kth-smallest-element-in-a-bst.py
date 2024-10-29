# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def _DFT_inorderHelp(self, currNode, treelist):
        if not currNode:
            return 
        self._DFT_inorderHelp(currNode.left, treelist)
        treelist.append(currNode.val)
        self._DFT_inorderHelp(currNode.right, treelist)

    def kthSmallest(self, root, k):
        treelist = []
        self._DFT_inorderHelp(root, treelist)
        return treelist[k-1]
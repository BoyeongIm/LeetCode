# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        bst = []
        def dfs(node, bst):
            if not node:
                return
            if node.left:
                dfs(node.left, bst)
            bst.append(node.val)
            if node.right:
                dfs(node.right, bst)
        dfs(root, bst)
        print(bst)
        return bst[k-1]
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        diff = [0]
        def dfs(currNode, maxi, mini):
            if not currNode:
                return 
            diff[0] = max(currNode.val-mini, maxi-currNode.val, diff[0])
            dfs(currNode.left, max(currNode.val, maxi), min(currNode.val, mini))
            dfs(currNode.right, max(currNode.val, maxi), min(currNode.val, mini))

        dfs(root.left, root.val, root.val)
        dfs(root.right, root.val, root.val)
        
        return diff[0]

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        def dfs(currNode, maxi, mini):
            if not currNode:
                return maxi-mini
            maxi = max(currNode.val, maxi)
            mini = min(currNode.val, mini)
            left_diff = dfs(currNode.left, maxi, mini)
            right_diff = dfs(currNode.right, maxi, mini)
            return left_diff if left_diff>right_diff else right_diff

        l = dfs(root.left, root.val, root.val)
        r = dfs(root.right, root.val, root.val)

        return l if l>r else r
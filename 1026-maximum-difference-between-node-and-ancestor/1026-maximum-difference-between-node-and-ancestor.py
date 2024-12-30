# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def maxAncestorDiff(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        def dfs(currNode, max_val, min_val):
            if not currNode:
                return max_val - min_val
            if currNode.val > max_val:
                max_val = currNode.val
            if currNode.val < min_val:
                min_val = currNode.val
            left = dfs(currNode.left, max_val, min_val)
            right = dfs(currNode.right, max_val, min_val)
            return left if left > right else right
        
        left_result = dfs(root.left, root.val, root.val)
        right_result = dfs(root.right, root.val, root.val)

        return left_result if left_result > right_result else right_result
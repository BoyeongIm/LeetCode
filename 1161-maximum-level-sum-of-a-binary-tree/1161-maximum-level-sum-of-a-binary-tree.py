# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        if not root.left and not root.right:
            return 1
        
        level = 0
        max_level_sum = root.val
        max_level = 0
        q = deque([root])
        while q:
            n = len(q)
            level += 1
            level_sum = 0
            for i in range(n):
                node = q.popleft()
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
                level_sum += node.val
            if level_sum > max_level_sum:
                max_level_sum = level_sum
                max_level = level
        return max_level
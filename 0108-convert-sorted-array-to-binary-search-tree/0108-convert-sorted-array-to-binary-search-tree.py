# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        if len(nums)==1:
            return TreeNode(nums[0])

        mid = len(nums)//2
        root = TreeNode(nums[mid])

        left_subtree = nums[:mid]
        right_subtree = nums[mid+1:]

        if left_subtree:
            root.left = self.sortedArrayToBST(left_subtree)
        if right_subtree:
            root.right = self.sortedArrayToBST(right_subtree)
        
        return root
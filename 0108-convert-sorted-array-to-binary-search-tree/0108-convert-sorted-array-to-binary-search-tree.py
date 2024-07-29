# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def sortedArrayToBST(self, nums):
        mid = len(nums)//2
        root = TreeNode(nums[mid])

        left = nums[:mid]
        right = nums[mid+1:]

        if len(left)>0:
            root.left = self.sortedArrayToBST(left)
        if len(right)>0:
            root.right = self.sortedArrayToBST(right)

        return root
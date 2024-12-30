# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        max_v = float('inf')
        min_v = float('-inf')

        def help_bst(currNode, max_val, min_val):
            # 재귀적으로 돌다가 자식 노드가 없어서 None에 돋라하면 더 이상 탐색할 필요가 없고
            # 지금까지 bst의 조건을 다 만족한 것이므로 True를 return
            if not currNode:
                return True
            # BST의 조건을 만족하지 못하면 False 반환
            if not (currNode.val > min_val and currNode.val < max_val):
                return False
            return help_bst(currNode.left, currNode.val, min_val) and help_bst(currNode.right, max_val, currNode.val)
        
        return help_bst(root, max_v, min_v)
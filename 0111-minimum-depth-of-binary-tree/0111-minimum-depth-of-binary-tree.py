# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        if not root.left and not root.right:
            return 1
        depth = 0
        q = deque([root])
        while q:
            n = len(q) 
            depth += 1
            for i in range(n):
                currNode = q.popleft()
                if currNode.left and currNode.right:
                    q.append(currNode.left)
                    q.append(currNode.right)
                elif currNode.right:
                    q.append(currNode.right)
                elif currNode.left:
                    q.append(currNode.left)
                else:
                    return depth
        return depth
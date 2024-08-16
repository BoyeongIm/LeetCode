# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def binaryTreePaths(self, root):
        if not root:
            return []
        paths = []
        self.__help(root, paths, [root.val])
        return paths
    
    def __help(self, currNode, paths, path):
        if not currNode.left and not currNode.right:
            pathstring = str(path[0])
            for i in range(1, len(path)):
                pathstring += "->"
                pathstring += str(path[i])
            if pathstring not in paths:
                paths.append(pathstring)
                return
        if currNode.left:
            self.__help(currNode.left, paths, path+[currNode.left.val])
        if currNode.right:
            self.__help(currNode.right, paths, path+[currNode.right.val])
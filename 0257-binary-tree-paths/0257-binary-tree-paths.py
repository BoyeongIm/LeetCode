class Solution(object):
    def binaryTreePaths(self, root):
        if not root:
            return []
        paths = []
        self.__help(root, paths, str(root.val))
        return paths
    
    def __help(self, currNode, paths, path):
        if not currNode.left and not currNode.right:
            if path not in paths:
                paths.append(path)
                return
        if currNode.left:
            self.__help(currNode.left, paths, path+"->"+str(currNode.left.val))
        if currNode.right:
            self.__help(currNode.right, paths, path+"->"+str(currNode.right.val))
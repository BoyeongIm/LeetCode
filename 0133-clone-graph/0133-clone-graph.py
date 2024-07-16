"""
# Definition for a Node.
class Node(object):
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution(object):
    def cloneGraph(self, node):
        """
        :type node: Node
        :rtype: Node
        """
        if not node:
            return node

        ans, visited = {}, set()
        self.dfs(node, ans, visited)
        return ans[node]

    def dfs(self, node, ans, visited):
        if node in visited:
            return

        visited.add(node)
        if node not in ans:
            ans[node] = Node(node.val)

        for n in node.neighbors:
            if n not in ans:
                ans[n] = Node(n.val)
            ans[node].neighbors.append(ans[n])
            self.dfs(n, ans, visited)
        
        return ans
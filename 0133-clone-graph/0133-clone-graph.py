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
        ans, visited, q = {}, [], deque([])
        q.append(node)
        while q:
            v = q.popleft()
            if v not in visited:
                visited.append(v)
                if v not in ans:
                    ans[v] = Node(v.val)
                for w in v.neighbors:
                    q.append(w)
                    if w not in ans:
                        ans[w] = Node(w.val)
                    ans[v].neighbors.append(ans[w])
        return ans[node]        
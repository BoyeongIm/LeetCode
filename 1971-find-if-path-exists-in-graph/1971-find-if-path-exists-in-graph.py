class Solution(object):
    def validPath(self, n, edges, source, destination):
        if not edges:
            return True
        adj = {i:[] for i in range(n)}
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        path, visited = [], set()
        self.dfs(adj, source, destination, path, visited)
        if path:
            return True
        else: 
            return False
        
    def dfs(self, adjlist, node, destination, path, visited):
        if node not in visited:
            visited.add(node)
            path.append(node)
            for neighbor in adjlist[node]:
                self.dfs(adjlist, neighbor, destination, path, visited)
                if neighbor==destination:
                    return
            path.pop()
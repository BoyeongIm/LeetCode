class Solution(object):
    def validPath(self, n, edges, source, destination):
        adj = {i:[] for i in range(n)}
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        path, visited = [], set()
        self.dfs(n, adj, source, destination, path, visited)
        if path and path[-1]==destination:
            print(path)
            return True
        else: 
            print(path)
            return False

    def dfs(self, n, adj, source, destination, path, visited):
        if source in visited:
            return
        visited.add(source)
        path.append(source)
        for neighbor in adj[source]:
            if neighbor not in visited:
                self.dfs(n, adj, neighbor, destination, path, visited)
                
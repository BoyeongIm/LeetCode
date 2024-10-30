class Solution(object):
    def _DFTHelp(self, visited, node, destination, adj):
        if node==destination:
            return True
        if not visited[node]:
            visited[node]=True
            for w in adj[node]:
                if self._DFTHelp(visited, w, destination, adj):
                    return True
        return False

    def validPath(self, n, edges, source, destination):
        adj = {i:[] for i in range(n)}
        for e in edges:
            adj[e[0]].append(e[1])
            adj[e[1]].append(e[0])
        visited = {}
        for i in range(n):
            visited[i] = False
        return self._DFTHelp(visited, source, destination, adj)
        
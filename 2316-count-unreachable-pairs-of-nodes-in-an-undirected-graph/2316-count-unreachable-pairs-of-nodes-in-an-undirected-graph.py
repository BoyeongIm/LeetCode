class Solution:
    def validPath(self, G, source: int, destination: int) -> bool:
        visited = [False for i in range(len(G))]
        def dfs(u, v):
            if u == v:
                return True
            if visited[u] == False:
                visited[u] = True
                for n in G[u]:
                    if dfs(n, v): 
                        return True
            return False
        return dfs(source, destination)

    def countPairs(self, n: int, edges: list[list[int]]) -> int:
        G = {i : [] for i in range(n)}
        
        # an undirected graph: edge list to adjacency list
        for e in edges:
            G[e[0]].append(e[1])
            G[e[1]].append(e[0])
        count = 0
        for i in range(n-1):
            for j in range(i+1, n):
                if not self.validPath(G, i, j):
                    count += 1
        return count
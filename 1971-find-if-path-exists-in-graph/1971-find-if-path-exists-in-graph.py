class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        graph = defaultdict(list)
        for e in edges: # bi-directional graph
            graph[e[0]].append(e[1])
            graph[e[1]].append(e[0])

        visited = [False for i in range(n)]
        def dfs(u, v):
            if u == v:
                return True
            if visited[u] == False:
                visited[u] = True
                for n in graph[u]:
                    if dfs(n, v): 
                        return True
            return False
        return dfs(source, destination)
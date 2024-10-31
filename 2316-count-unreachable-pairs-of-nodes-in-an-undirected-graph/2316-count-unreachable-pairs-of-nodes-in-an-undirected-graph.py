class Solution(object):
    def countPairs(self, n, edges):
        adj = {i:[] for i in range(n)}
        for u,v in edges:
            adj[u].append(v)
            adj[v].append(u)
        print(adj)
        total = n*(n-1) / 2
        comb = set()
        for i in range(n):
            if len(adj[i]) == 1:
                comb.add(tuple(sorted((i, adj[i][0]))))
            elif len(adj[i]) > 1:
                for j in range(len(adj[i])):
                    comb.add(tuple(sorted((i,adj[i][j]))))
                    for k in adj[i][j+1:]:
                        comb.add(tuple(sorted((adj[i][j],k))))
        total -= len(comb)
        return total
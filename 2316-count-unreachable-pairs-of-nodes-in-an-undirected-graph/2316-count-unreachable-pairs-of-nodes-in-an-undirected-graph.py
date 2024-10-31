class Solution(object):
    def countPairs(self, n, edges):
        #adj = {i:[] for i in range(n)}
        #for u,v in edges:
        #    adj[u].append(v)
        #    adj[v].append(u)
        parents = [i for i in range(n)]
        for u, v in edges:
            if self.findparent(u, parents) != self.findparent(v, parents):
                self.unite(u, v, parents)
        count = {i:0 for i in range(n)}
        for i in range(n):
            parents[i] = self.findparent(i, parents)
            count[parents[i]] +=1
        total = n*(n-1)/2
        for c in count:
            if count[c] > 1:
                v = count[c]
                total -= v*(v-1)/2
        return total

    def findparent(self, node, parents):
        if node != parents[node]:
            parents[node] = self.findparent(parents[node], parents)
        return parents[node]
    
    def unite(self, u, v, parents):
        u_root = self.findparent(u, parents)
        v_root = self.findparent(v, parents)
        if u_root == v_root:
            return
        if u_root < v_root:
            parents[v_root] = u_root
        else:
            parents[u_root] = v_root
    
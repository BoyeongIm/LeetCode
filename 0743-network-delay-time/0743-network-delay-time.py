class Solution:    
    def networkDelayTime(self, times, n, k):
        graph = defaultdict(list)
        for u, v, w in times:
            graph[u].append((v, w))
        
        dist = [10000] * (n+1)
        dist[k] = 0
        prQ = []
        heappush(prQ, (0, k))

        while prQ:
            total_weight, u = heappop(prQ)
            
            for v, w in graph[u]:
                if dist[u] + w < dist[v]:
                    dist[v] = dist[u]+w
                    heappush(prQ, (dist[v], v))
        
        max_d = max(dist[1:])
        return -1 if max_d==10000 else max_d
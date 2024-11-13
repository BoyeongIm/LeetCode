class Solution(object):
    def minCostConnectPoints(self, points):
        def calculate_cost(point1, point2):
            return abs(point1[0] - point2[0]) + abs(point1[1] - point2[1])
        
        n = len(points)
        total_weight = 0
        visited = [False] * n
        dist = [float('inf')] * n
        dist[0] = 0  # Start from the first point
        
        for _ in range(n):
            # Find the unvisited node with the smallest distance
            min_cost = float('inf')
            u = -1
            for i in range(n):
                if not visited[i] and dist[i] < min_cost:
                    min_cost = dist[i]
                    u = i
            
            # Mark this node as visited and add the cost to the total weight
            visited[u] = True
            total_weight += min_cost
            
            # Update distances to the unvisited neighbors
            for v in range(n):
                if not visited[v]:
                    cost = calculate_cost(points[u], points[v])
                    if cost < dist[v]:
                        dist[v] = cost
        
        return total_weight

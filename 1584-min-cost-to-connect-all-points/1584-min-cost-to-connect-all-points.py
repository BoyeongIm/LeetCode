class Solution(object):
    def minCostConnectPoints(self, points):
        def make_edges(points):
            edges = []
            for i in range(len(points)):
                for j in range(i + 1, len(points)):
                    x1, y1 = points[i]
                    x2, y2 = points[j]
                    w = abs(x1 - x2) + abs(y1 - y2)
                    edges.append((w, i, j))  # (weight, point1, point2)
            return edges

        n = len(points)
        edges = make_edges(points)
        total_weight = 0
        visited = set()

        queue = [(0,0)]
        while queue and len(visited)<n:
            queue.sort(key = lambda x: x[0])
            cost, u = queue.pop(0)

            if u in visited:
                continue
            visited.add(u)
            total_weight+=cost
            for w, i, j in edges:
                if i==u and j not in visited:
                    queue.append((w, j))
                elif j==u and i not in visited:
                    queue.append((w, i))
        
        return total_weight
            
class Solution(object):
    def isBipartite(self, graph):
        vertices = [i for i in range(len(graph))]
        color = [0 for i in range(len(graph))]
        q = []
        for v in vertices:
            if color[v] == 0:
                color[v] = 1
                q.append(v)
                while q:
                    curr = q.pop(0)
                    for w in graph[curr]:
                        if color[w] == 0:
                            color[w] = -color[curr]
                            q.append(w)
                        elif color[w] == color[curr]:
                            return False
        return True
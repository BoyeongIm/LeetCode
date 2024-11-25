from collections import defaultdict
class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        frequency = []
        for i in range(len(mat)):
            frequency.append((sum(mat[i]), i))
        frequency.sort(key=lambda x:(x[0],x[1]))
        answer = []
        for f in frequency:
            answer.append(f[1])
        return answer[:k]

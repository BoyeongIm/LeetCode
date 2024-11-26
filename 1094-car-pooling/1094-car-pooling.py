class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        heap = []
        locations = [0]*1001
        for passengers, dep, arr in trips:
            heap.append([(dep, passengers), (arr, -passengers)])
        heapify(heap)
        while capacity>=0 and heap:
            capacity += heappop(heap)[1][1]
            if capacity < 0:
                return False
        return True
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        if not stones:
            return 0
        if len(stones) == 1:
            return stones[0]
        
        maxheap = []
        for s in stones:
            heapq.heappush(maxheap, -s)
            
        first = -heapq.heappop(maxheap)
        second = -heapq.heappop(maxheap)
        new_w = first-second
        stones.append(new_w)
        stones.remove(first)
        stones.remove(second)

        return self.lastStoneWeight(stones)
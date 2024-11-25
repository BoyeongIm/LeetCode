class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        if not stones:
            return 0
        if len(stones) == 1:
            return stones[0]

        sorted_stones = sorted(stones, reverse=True)
        first, second = sorted_stones[0], sorted_stones[1]
        
        new_w = first-second
        stones.append(new_w)
        stones.remove(first)
        stones.remove(second)
        return self.lastStoneWeight(stones)
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 1:
            return strs[0]
        sorted_strs = sorted(strs, key = len)
        shortest = sorted_strs[0]
        length = 0
        while length < len(shortest):
            for word in sorted_strs:
                if shortest[:length+1] != word[:length+1]:
                    return shortest[:length]
            length += 1
        return shortest 
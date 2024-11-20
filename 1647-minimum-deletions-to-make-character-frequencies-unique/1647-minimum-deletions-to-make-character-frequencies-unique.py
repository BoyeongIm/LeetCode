class Solution(object):
    def minDeletions(self, s):
        freq = dict()
        unique_freq = set()
        for c in s:
            if c not in freq:
                freq[c] = 1
            else:
                freq[c] += 1
        if len(set(freq.values())) == len(freq):
            return 0
        sorted_freq = dict(sorted(freq.items(), key=lambda x:x[1], reverse=True))
        for k,v in sorted_freq.items():
            if v not in unique_freq:
                unique_freq.add(v)
            else:
                v-=1
                unique_freq.add(v)
        return len(s) - sum(unique_freq)
        
        
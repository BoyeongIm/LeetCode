class Solution(object):
    def frequencySort(self, s):
        answer = ""
        sdict = dict()
        for c in s:
            if c not in sdict:
                sdict[c] = 1
            else:
                sdict[c] += 1
        sorted_sdict = sorted(sdict.items(), key=lambda x:x[1], reverse=True)
        for k, v in sorted_sdict:
            while v > 0:
                answer += k
                v -= 1

        return answer
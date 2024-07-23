class Solution(object):
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        freq_dict = {}
        for i in range(len(s)):
            if s[i] not in freq_dict:
                freq_dict[s[i]] = 1
            else: 
                freq_dict[s[i]] += 1
        sorted_dict = sorted(freq_dict.items(), key=lambda x:x[1], reverse=True)
        print(sorted_dict)
        s2 = ""
        for j in sorted_dict:
            s2 += j[0]*j[1]

        return s2
class Solution(object):
    def sortTheStudents(self, score, k):
        """
        :type score: List[List[int]]
        :type k: int
        :rtype: List[List[int]]
        """
        sorted_dic = {}
        for r in range(len(score)):
            sorted_dic[score[r][k]] = r
        sorted_dic = sorted(sorted_dic.items(), reverse=True)
        new_score = []
        i=0
        for n in sorted_dic:
            new_score.append(score[n[1]])
            i += 1
        return new_score
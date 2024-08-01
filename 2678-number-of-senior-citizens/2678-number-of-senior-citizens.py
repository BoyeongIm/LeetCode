class Solution(object):
    def countSeniors(self, details):
        """
        :type details: List[str]
        :rtype: int
        """
        count = 0
        for d in details:
            if int(d[11:13]) > 60:
                count+=1
        return count
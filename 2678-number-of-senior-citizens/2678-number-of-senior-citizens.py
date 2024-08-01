class Solution(object):
    def countSeniors(self, details):
        """
        :type details: List[str]
        :rtype: int
        """
        agelist = []
        for d in details:
            age = int(d[11:13])
            agelist.append(age)
        count = 0
        for a in agelist:
            if a > 60:
                count+=1
        return count
class Solution(object):
    def countSeniors(self, details):
        """
        :type details: List[str]
        :rtype: int
        """
        count = 0
        for d in details:
            age = int(d[11:13])
            if age>60:
                count+=1
        return count
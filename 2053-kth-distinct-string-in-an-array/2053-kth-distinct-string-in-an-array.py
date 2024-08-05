class Solution(object):
    def kthDistinct(self, arr, k):
        arr_dict = dict()
        for a in arr:
            if a not in arr_dict:
                arr_dict[a] = 1
            else:
                arr_dict[a] += 1

        count = 0
        for a in arr:
            if arr_dict[a]==1:
                count+=1
                if count==k:
                    return a

        return ""
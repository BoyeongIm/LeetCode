class Solution(object):        
    def canBeEqual(self, target, arr):
        """
        :type target: List[int]
        :type arr: List[int]
        :rtype: bool
        """
        target_dict=dict()
        for t in target:
            if t in target_dict:
                target_dict[t]+=1
            else:
                target_dict[t]=1

        arr_dict = dict()
        for n in arr:
            if n in arr_dict:
                arr_dict[n]+=1
            else:
                arr_dict[n]=1
        
        return target_dict==arr_dict

        

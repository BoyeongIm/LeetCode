class Solution(object):
    def combinationSum(self, candidates, target):
        combinations = []
        #candidates.sort()
        self.__help(candidates, combinations, [], target)
        return combinations
    
    def __help(self, candidates, combinations, comb, target):
        if target==0:
            combinations.append(comb)
            return
        
        for i in range(len(candidates)):
            if target-candidates[i]<0:
                continue
            self.__help(candidates[i:], combinations, comb+[candidates[i]], target-candidates[i])     
        
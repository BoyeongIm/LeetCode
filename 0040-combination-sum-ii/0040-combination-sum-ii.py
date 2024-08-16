class Solution(object):
    def combinationSum2(self, candidates, target):
        if sum(candidates) < target:
            return []
        if sum(candidates) == target:
            return [candidates]
        combinations = []
        candidates.sort()
        self.__help(candidates, combinations, [], target)
        return combinations
    
    def __help(self, candidates, combinations, comb, target):
        if target==0 and comb not in combinations:
            combinations.append(comb)
            return
        
        for i in range(len(candidates)):
            if target-candidates[i]<0:
                continue
            self.__help(candidates[i+1:], combinations, comb+[candidates[i]], target-candidates[i])     
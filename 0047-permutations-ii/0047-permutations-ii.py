class Solution(object):
    def permuteUnique(self, nums):
        visited = [0 for i in range(len(nums))]
        answer = []
        permuted = []
        self.__help(nums, visited, answer, permuted)
        return list(answer)

    def __help(self, lst, visited, answer, permuted):
        if len(permuted) == len(lst) and permuted not in answer:
            answer.append(permuted[:])
            return
        
        for i in range(len(lst)):
            if not visited[i]:
                permuted.append(lst[i])
                visited[i] = 1
                self.__help(lst, visited, answer, permuted)
                visited[i] = 0
                permuted.pop()
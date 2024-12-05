class Solution:
    def pancakeSort(self, arr: List[int]) -> List[int]:
        def flip(arr, k):
            arr[:k] = arr[:k][::-1]

        def find_max_loca(arr, n):
            max_idx = 0
            for i in range(n):
                if arr[i] > arr[max_idx]:
                    max_idx = i
            return max_idx
        
        answer = []
        for i in range(len(arr), 1, -1):
            max_idx = find_max_loca(arr, i)
            if max_idx != i-1:
                if max_idx != 0:
                    flip(arr, max_idx+1)
                    answer.append(max_idx+1)
                flip(arr,i)
                answer.append(i)
        return answer
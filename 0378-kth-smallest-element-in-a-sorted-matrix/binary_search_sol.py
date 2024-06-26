class Solution(object):
    def kthSmallest(self, matrix, k):
        # binary search
        n = len(matrix)
        left, right = matrix[0][0], matrix[n-1][n-1]

        while left < right:
            mid = (left + right) // 2
            count = 0
            j = n-1
            for i in range(n): # 각 행에 대해서
                while j>=0 and matrix[i][j] > mid:
                # mid 값이랑 계속 비교해서, mid 값이 더 작으면 j를 계속 앞당김 (각 행의 마지막 element에서 하나씩 앞당김)
                    j -= 1
                # while 문을 벗어나게 되는 것은 j가 음수가 되거나 mid 값과 같거나 mid가 더 커지는 순간
                ## 그것(인덱스)보다 1 더한 만큼이, mid보다 작거나 같은 숫자의 개수임.
                count += j+1 
            if count < k: # 원하는 횟수(k)만큼의 숫자가 안나왔으면 mid보다 더 작은 숫자로 이루어진 부분을 볼 필요가 없음. 그래서 mid 다음부터 보기
                left = mid + 1
            else: 
                right = mid

        return left

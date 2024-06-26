class Solution(object):
    def kthSmallest(self, matrix, k):
        '''
        비효율적임, 복잡한 test case에 대해 time limit exceeded 오류 남
        l = len(matrix)
        lst = []
        for i in range(l):
            for j in range(l):
                lst.append(matrix[i][j])
        // selection sort 대신에 그냥 sorted()함수 혹은 sort메서드를 쓰면 됨
        for i in range(len(lst)):
            smallest = i
            for j in range(i+1, len(lst)):
                if lst[j] < lst[smallest]:
                    smallest=j
            lst[i], lst[smallest] = lst[smallest], lst[i]

        return lst[k-1]
        '''
        '''
        for i in range(l):
            for j in range(l):
                lst.append(matrix[i][j])
                '''
        lst = []
        for r in matrix:
            lst.extend(r)
                
        lst.sort()
        return lst[k-1]
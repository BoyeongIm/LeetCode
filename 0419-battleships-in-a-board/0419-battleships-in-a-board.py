class Solution(object):
    def countBattleships(self, board):
        row = len(board)
        col = len(board[0])
        visited = [[False] * col for _ in range(row)] 
        s = 0
        def dfs(x,y):
            if x<0 or x>=row or y<0 or y>=col or board[x][y] == '.' or visited[x][y] == True:
                return 0

            visited[x][y] = True

            dx = [-1, 0, 1, 0]
            dy = [0, 1, 0, -1]
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]
                dfs(nx, ny)

        count = 0
        for i in range(row):
            for j in range(col):
                if board[i][j] == 'X' and visited[i][j] == False:
                    dfs(i,j)
                    count+=1
        return count


class Solution:
    def countBattleships(self, board: List[List[str]]) -> int:
        if not board:
            return 0

        row = len(board)
        col = len(board[0])
        visited = [[False] * col for _ in range(row)]
        
        def dfs(x, y):
            if x < 0 or x >= row or y < 0 or y >= col or board[x][y] == '.' or visited[x][y] == True:
                return

            # 방문 처리
            visited[x][y] = True

            dx = [0, 1, 0, -1]
            dy = [1, 0, -1, 0]

            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]
                dfs(nx, ny)

        count = 0
        for i in range(row):
            for j in range(col):
                if board[i][j] == 'X' and visited[i][j] == False:  
                    dfs(i, j)
                    count += 1
        return count
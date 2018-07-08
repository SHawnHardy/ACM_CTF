class Solution:
    """
    @param grid: Given a 2D grid, each cell is either 'W', 'E' or '0'
    @return: an integer, the maximum enemies you can kill using one bomb
    """

    def maxKilledEnemies(self, grid):
        # write your code here
        N = len(grid)
        if N == 0:
            return 0
        M = len(grid[0])
        if M == 0:
            return 0

        ans = [[0 for i in range(M)] for j in range(N)]

        for i in range(N):
            val = 0
            for j in range(M):
                if grid[i][j] == '0':
                    ans[i][j] += val
                elif grid[i][j] == 'W':
                    val = 0
                else:
                    val += 1

        for i in range(N):
            val = 0
            for j in range((M - 1), -1, -1):
                if grid[i][j] == '0':
                    ans[i][j] += val
                elif grid[i][j] == 'W':
                    val = 0
                else:
                    val += 1

        for j in range(M):
            val = 0
            for i in range(N):
                if grid[i][j] == '0':
                    ans[i][j] += val
                elif grid[i][j] == 'W':
                    val = 0
                else:
                    val += 1

        for j in range(M):
            val = 0
            for i in range((N - 1), -1, -1):
                if grid[i][j] == '0':
                    ans[i][j] += val
                elif grid[i][j] == 'W':
                    val = 0
                else:
                    val += 1

        result = 0
        for i in range(N):
            result = max(result, max(ans[i]))
        return result

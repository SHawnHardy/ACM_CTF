class Solution:
    """
    @param matrix: the given matrix
    @return: True if and only if the matrix is Toeplitz
    """

    def chk(self, matrix, x, y, M, N):
        num = matrix[x][y]
        while x < M and y < N:
            if matrix[x][y] != num:
                return False
            x += 1
            y += 1
        return True

    def isToeplitzMatrix(self, matrix):
        # Write your code here
        M = len(matrix)
        N = len(matrix[0])
        for i in range(M):
            if not self.chk(matrix, i, 0, M, N):
                return False

        for i in range(1, N):
            if not self.chk(matrix, 0, i, M, N):
                return False
        return True

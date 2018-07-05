class Solution:
	"""
	@param n: non-negative integer, n posts
	@param k: non-negative integer, k colors
	@return: an integer, the total number of ways
	"""

	def matrix_multi(self, a, b):
		M = len(a)
		K = len(a[0])
		N = len(b[0])

		result = [[] for i in range(M)]

		for i in range(M):
			for j in range(N):
				result[i].append(0)
				for k in range(K):
					result[i][j] += a[i][k] * b[k][j]
		return result

	def matrix_pow(self, matrix, a):
		N = len(matrix)
		result = [[1 if i == j else 0 for j in range(N)] for i in range(N)]

		while a > 0:
			if a & 1 == 1:
				result = self.matrix_multi(result, matrix)
			a >>= 1
			matrix = self.matrix_multi(matrix, matrix)

		return result

	def numWays(self, n, k):
		# write your code here
		if k == 0:
			return 0
		if k == 1:
			if n > 2:
				return 0
			else:
				return 1

		result = [[1, k, k * k, k * k * k - k]]
		if n < 4:
			return result[0][n]

		matrix = [[0 for j in range(4)] for i in range(4)]
		matrix[1][0] = matrix[2][1] = matrix[3][2] = 1
		matrix[1][3] = 1 - k
		matrix[3][3] = k

		matrix = self.matrix_pow(matrix, n - 3)
		result = self.matrix_multi(result, matrix)

		return result[0][3]

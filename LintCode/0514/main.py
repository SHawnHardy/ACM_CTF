class Solution:
	"""
	@param n: non-negative integer, n posts
	@param k: non-negative integer, k colors
	@return: an integer, the total number of ways
	"""

	def numWays(self, n, k):
		# write your code here
		if k == 0:
			return 0
		if k == 1:
			if n > 2:
				return 0
			else:
				return 1

		result = [1, k, k * k, k * k * k - k]
		if n < 4:
			return result[n]

		for i in range(4, n + 1):
			result[0] = result[1]
			result[1] = result[2]
			result[2] = result[3]
			result[3] = result[3] * k - result[0] * (k - 1)

		return result[3]

class Solution:
	def binary_search(self, A, x):
		l, r = 0, (len(A) - 1)
		if r == -1:
			return -1

		if A[l] >= x:
			return l
		if A[r] < x:
			return -1

		while (r - l) > 1:
			mid = (l + r) >> 1
			if A[mid] < x:
				l = mid
			else:
				r = mid
		return r

	"""
	@param: envelopes: a number of envelopes with widths and heights
	@return: the maximum number of envelopes
	"""

	def maxEnvelopes(self, envelopes):
		# write your code here
		envelopes.sort(key=lambda x:[x[0], -x[1]])

		dp = []

		for i in envelopes:
			pos = self.binary_search(dp, i[1])
			if pos == -1:
				dp.append(i[1])
			else:
				dp[pos] = i[1]
		return len(dp)

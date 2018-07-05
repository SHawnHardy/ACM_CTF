class Solution:
	"""
	@param s: A string
	@return: whether the string is a valid parentheses
	"""

	def isValidParentheses(self, s):
		# write your code here
		LEFT = ('{', '[', '(')
		RIGHT = {'}': '{', ']': '[', ')': '('}

		stack = []
		s = list(s)
		N = len(s)
		for i in range(N):
			if s[i] in LEFT:
				stack.append(s[i])
			elif len(stack) == 0:
				return False
			elif stack[-1] != RIGHT[s[i]]:
				return False
			else:
				stack.pop(-1)

		return len(stack) == 0

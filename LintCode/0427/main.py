class Solution:
    """
    @param n: n pairs
    @return: All combinations of well-formed parentheses
    """
    result = []

    def dfs(self, l, r, s):
        if (l + r) == 0:
            self.result.append(s)
            return

        if l > 0:
            self.dfs(l - 1, r, s + '(')
        if l < r:
            self.dfs(l, r - 1, s + ')')

    def generateParenthesis(self, n):
        # write your code here
        self.dfs(n, n, "")
        return self.result

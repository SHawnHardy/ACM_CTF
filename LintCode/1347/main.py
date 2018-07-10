class Solution:
    """
    @param n: a integer
    @return: return a integer
    """

    def trailingZeroes(self, n):
        # write your code here
        result = 0
        c = 5
        while (c <= n):
            result += (n // c)
            c *= 5
        return result

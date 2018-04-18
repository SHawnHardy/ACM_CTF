class Solution:
    """
    @param: n: An integer
    @return: An integer, denote the number of trailing zeros in n!
    """

    def trailingZeros(self, n):
        # write your code here, try to do it without arithmetic operators.
        result = 0
        c = 5
        while (c <= n):
            result += (n // c)
            c *= 5
        return result

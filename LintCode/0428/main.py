class Solution:
    """
    @param: x: the base number
    @param: n: the power number
    @return: the result
    """

    def myPow(self, x, n):
        # write your code here
        if n < 0:
            n = -n
            x = 1 / x

        result = 1
        while n > 0:
            if n & 1 == 1:
                result *= x
            x *= x
            n >>= 1
        return result

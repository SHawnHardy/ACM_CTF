class Solution:
    """
    @param a: An integer
    @param b: An integer
    @return: The sum of a and b
    """

    def aplusb(self, a, b):
        # write your code here, try to do it without arithmetic operators.
        limit = 0xfffffffff
        while b != 0:
            a, b = (a ^ b) & limit, (a & b) << 1
        return a if a & 1 << 32 == 0 else a | (~limit)

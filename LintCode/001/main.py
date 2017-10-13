class Solution:
    """
    @param a: The first integer
    @param b: The second integer
    @return:  The sum of a and b
    """
    def aplusb(self, a, b):
        # write your code here, try to do it without arithmetic operators.
        limit=0xffffffff
        while a&b!=0:
            aa=a
            bb=b
            a=(aa^bb)&limit
            b=((aa&bb)<<1)&limit
        return a^b

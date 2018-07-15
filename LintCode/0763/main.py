class Solution:

    def baseN(self, num, b):
        return ((num == 0) and "0") or (
                self.baseN(num // b, b).lstrip("0") + "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[num % b])

    """
    @param n: a decimal number
    @param k: a Integer represent base-k
    @return: a base-k number
    """

    def hexConversion(self, n, k):
        # write your code here
        return self.baseN(n, k)

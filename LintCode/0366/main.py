class Solution:
    """
    @param n: an integer
    @return: an ineger f(n)
    """

    def fibonacci(self, n):
        # write your code here
        if n == 1:
            return 0
        if n == 2:
            return 1

        a, b = 0, 1

        for i in range(2, n):
            a = a + b
            a, b = b, a

        return b

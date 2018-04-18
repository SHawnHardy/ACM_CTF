class Solution:
    """
    @param: : An integer
    @param: : An integer
    @return: An integer denote the count of digit k in 1..n
    """

    def digitCounts(self, k, n):
        # write your code here
        rst = 0 if k > 0 else 1
        num = ['0'] + list(str(n))

        for i in range(1, len(num)):
            lt = int(''.join(num[:i]))
            rt = int(''.join(num[i + 1:])) if (i + 1) < len(num) else 0
            rt += 1
            if k != 0:
                lt += 1
            if k < int(num[i]):
                rst += lt * 10 ** (len(num) - i - 1)
            elif k == int(num[i]):
                rst += (lt - 1) * (10 ** (len(num) - i - 1)) + rt
            else:
                rst += (lt - 1) * (10 ** (len(num) - i - 1))
        return rst

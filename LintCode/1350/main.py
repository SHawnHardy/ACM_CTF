class Solution:
    """
    @param n: a integer
    @return: return a string
    """

    def convertToTitle(self, n):
        # write your code here
        result = []
        while n > 0:
            result.append(n % 26)
            n //= 26

        for i in range(len(result) - 1):
            if result[i] <= 0:
                result[i] += 26
                result[i + 1] -= 1

        if result[-1] == 0:
            result.pop()

        l, r = 0, (len(result) - 1)

        while l < r:
            result[l], result[r] = result[r], result[l]
            l += 1
            r -= 1

        result = [chr(64 + x) for x in result]
        return ''.join(result)

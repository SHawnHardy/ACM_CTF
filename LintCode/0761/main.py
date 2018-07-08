class Solution:
    """
    @param arr:  an array of non-negative integers
    @return: minimum number of elements
    """

    def minElements(self, arr):
        # write your code here
        arr.sort(reverse=True)
        s = sum(arr)
        result = 0
        tmp = 0

        for i in arr:
            tmp += i
            result += 1
            if tmp > (s - tmp):
                return result

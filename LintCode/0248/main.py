class Solution:
    def binary_search(self, A, x):
        l, r = 0, (len(A) - 1)
        if r == -1:
            return 0

        if A[l] >= x:
            return l
        if A[r] < x:
            return 0

        while (r - l) > 1:
            mid = (l + r) >> 1
            if A[mid] < x:
                l = mid
            else:
                r = mid
        return r

    """
    @param A: An integer array
    @param queries: The query list
    @return: The number of element in the array that are smaller that the given integer
    """

    def countOfSmallerNumber(self, A, queries):
        # write your code here
        A.sort()
        return [self.binary_search(A, x) for x in queries]

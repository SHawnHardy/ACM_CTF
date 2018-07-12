class Solution:
    def func(self, A, x):
        result = 0
        l = r = 0
        while r < len(A):
            if A[r] > x:
                result += (1 + (r - l)) * (r - l) // 2
                l = r + 1
            r += 1
        result += (1 + (r - l)) * (r - l) // 2
        return result
                
    """
    @param A: an array
    @param L: an integer
    @param R: an integer
    @return: the number of subarrays such that the value of the maximum array element in that subarray is at least L and at most R
    """
    def numSubarrayBoundedMax(self, A, L, R):
        # Write your code here
        return self.func(A, R) - self.func(A, L - 1)

class Solution:
    # @param k & A a integer and an array
    # @return ans a integer
    def kthLargestElement(self, k, A):
        if len(A) == 1:
            return A[0]
        key = A[0]
        lt = 0
        rt = len(A)
        while rt - lt > 1:
            while rt - lt > 1 and A[lt + 1] >= key:
                lt += 1
            while rt - lt > 1 and A[rt - 1] <= key:
                rt -= 1
            if rt - lt <= 1:
                break
            A[lt + 1], A[rt - 1] = A[rt - 1], A[lt + 1]
            lt += 1
            rt -= 1
        A[lt], A[0] = A[0], A[lt]
        if k - 1 == lt:
            return A[lt]
        else:
            if k - 1 < lt:
                return self.kthLargestElement(k, A[:lt])
            else:
                return self.kthLargestElement(k - lt - 1, A[rt:])

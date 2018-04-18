class Solution:
    """
    @param A: sorted integer array A
    @param B: sorted integer array B
    @return: A new sorted integer array
    """

    def mergeSortedArray(self, A, B):
        # write your code here
        if len(A) < len(B):
            A, B = B, A
        pa = len(A) - 1
        pb = len(B) - 1
        A += [0 for x in range(len(B))]
        p = len(A) - 1
        while pb >= 0:
            if B[pb] >= A[pa] or pa == -1:
                A[p] = B[pb]
                p -= 1
                pb -= 1
            else:
                A[p] = A[pa]
                p -= 1
                pa -= 1
        return A


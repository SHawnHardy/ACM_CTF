class Solution:
    """
    @param A: a string
    @param B: a string
    @return: a boolean
    """
    def Permutation(self, A, B):
        # write your code here
        letters = [chr(x) for x in range(97, 123)] + [' ']
        for i in letters:
            if A.count(i) != B.count(i):
                return False
        return True

class Solution:
    """
    @param words: a list of string
    @return: a boolean
    """

    def validWordSquare(self, words):
        # Write your code here
        N = len(words)
        if N != len(words[0]):
            return False

        for i in range(N):
            for j in range(i + 1, N):
                if words[i][j] != words[j][i]:
                    return False

        return True

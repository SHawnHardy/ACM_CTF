class Solution:
    """
    @param s: the given string
    @return: all the possible states of the string after one valid move
    """

    def generatePossibleNextMoves(self, s):
        # write your code here
        result = []
        N = len(s)
        for i in range(N - 1):
            if s[i] == '+' and s[i + 1] == '+':
                result.append(s[:i] + "--" + s[i + 2:])
        return result

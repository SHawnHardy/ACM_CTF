class Solution:
    """
    @param N: The number of integers
    @return: The number of beautiful arrangements you can construct
    """

    def dfs(self, available, pos, N):
        if pos == (N + 1):
            return 1

        result = 0
        for i in available:
            if i % pos == 0 or pos % i == 0:
                tmp_available = available.copy()
                tmp_available.remove(i)
                result += self.dfs(tmp_available, pos + 1, N)
        return result

    def countArrangement(self, N):
        # Write your code here
        return self.dfs(set(range(1, N + 1)), 1, N)

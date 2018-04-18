class Solution:
    """
    @param n: An integer
    @return: the nth prime number as description.
    """

    def nthUglyNumber(self, n):
        # write your code here
        arr = [1]
        p = [0, 0, 0]
        for i in range(1, n):
            arr.append(min(arr[p[0]] * 2, arr[p[1]] * 3, arr[p[2]] * 5))
            if arr[-1] == 2 * arr[p[0]]:
                p[0] += 1
            if arr[-1] == 3 * arr[p[1]]:
                p[1] += 1
            if arr[-1] == 5 * arr[p[2]]:
                p[2] += 1

        return arr[-1]


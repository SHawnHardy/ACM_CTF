class Solution:
    """
    @param num: a string
    @return: true if a number is strobogrammatic or false
    """

    def isStrobogrammatic(self, num):
        # write your code here
        conv = {'0': '0', '1': '1', '2': '5', '3': None, '4': None, '5': '2', '6': '9', '7': None, '8': '8', '9': '6'}
        l, r = 0, len(num) - 1
        while l <= r:
            if conv[num[l]] == None or conv[num[r]] == None:
                return False

            if conv[num[l]] != num[r]:
                return False

            l += 1
            r -= 1
        return True

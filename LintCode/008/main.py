class Solution:
    """
    @param str: An array of char
    @param offset: An integer
    @return: nothing
    """

    def rotateString(self, str, offset):
        # write your code here
        def rotate(str, lt, rt):
            while lt < rt:
                str[lt], str[rt] = str[rt], str[lt]
                lt += 1
                rt -= 1

        if len(str) == 0:
            return
        offset = offset % len(str)
        rotate(str, 0, len(str) - 1)
        rotate(str, 0, offset - 1)
        rotate(str, offset, len(str) - 1)

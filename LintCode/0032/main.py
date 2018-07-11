class Solution:
    """
    @param source : A string
    @param target: A string
    @return: A string denote the minimum window, return "" if there is no such a string
    """

    def minWindow(self, source, target):
        # write your code here
        letter = [chr(i) for i in range(0, 256)]
        letter = [target.count(i) for i in letter]
        s = sum(letter)
        if s == 0:
            return ""
        letter = [-1073741824 if i == 0 else i for i in letter]

        l = r = 0

        while s > 0 and r < len(source):
            tmp = ord(source[r])
            if letter[tmp] > 0:
                s -= 1
            letter[tmp] -= 1
            r += 1
        if s > 0:
            return ""
        while True:
            tmp = ord(source[l])
            if letter[tmp] == 0:
                break
            letter[tmp] += 1
            l += 1

        result_len = r - l
        result = l

        while r < len(source):
            tmp = ord(source[r])
            letter[tmp] -= 1
            r += 1

            while letter[ord(source[l])] != 0:
                letter[ord(source[l])] += 1
                l += 1
            if result_len > (r - l):
                result_len = r - l
                result = l

        return source[result: result + result_len]

class Solution:
    """
    @param input: an abstract file system
    @return: return the length of the longest absolute path to file
    """

    def lengthLongestPath(self, input):
        # write your code here
        result = 0
        tmp_result = 0
        input = input.split('\n')
        stack = []
        stack_len = 0
        for i in input:
            c = i.count('\t')
            word_len = len(i) - c
            while c < stack_len:
                tmp_result -= (stack[-1] + 1)
                stack.pop()
                stack_len -= 1
            stack.append(word_len)
            stack_len += 1
            tmp_result += (word_len + 1)

            if '.' in i:
                result = max(result, tmp_result - 1)
        return result

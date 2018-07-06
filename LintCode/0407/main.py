class Solution:
    """
    @param digits: a number represented as an array of digits
    @return: the result
    """

    def plusOne(self, digits):
        # write your code here
        add_one = 1
        for i in range(len(digits) - 1, -1, -1):
            digits[i] += add_one
            if digits[i] == 10:
                digits[i] = 0
                add_one = 1
            else:
                add_one = 0
                break
        if add_one == 1:
            return [1] + digits
        else:
            return digits

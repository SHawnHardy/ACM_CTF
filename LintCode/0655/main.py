class Solution:
    """
    @param num1: a non-negative integers
    @param num2: a non-negative integers
    @return: return sum of num1 and num2
    """

    def addStrings(self, num1, num2):
        # write your code here
        num1 = list(num1)
        num2 = list(num2)
        length_a = len(num1)
        length_b = len(num2)
        if length_a < length_b:
            num1, num2 = num2, num1
            length_a, length_b = length_b, length_a

        add_one = 0
        for i in range(1, length_a + 1):
            a = (add_one + ord(num1[length_a - i]) - ord('0'))
            if i <= length_b:
                a += (ord(num2[length_b - i]) - ord('0'))

            if a > 9:
                a %= 10
                add_one = 1
            else:
                add_one = 0
            num1[length_a - i] = chr(a + ord('0'))

            if i > length_b and add_one == 0:
                break

        if add_one == 1:
            return "1" + "".join(num1)
        else:
            return "".join(num1)

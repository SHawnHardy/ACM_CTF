class Solution:
    """
    @param color: the given color
    @return: a 7 character color that is most similar to the given color
    """

    def get_similar(self, x):
        a, b = [int(i, 16) for i in x]
        if a == b:
            return x[0] + x[0]

        if a < b:
            if (a + 1) < 16:
                if (b - a) < (a + 17 - b):
                    return hex(a * 17)[2:].zfill(2)
                else:
                    return hex((a + 1) * 17)[2:].zfill(2)
            else:
                return hex(a * 17)[2:].zfill(2)
        else:
            if (a - 1) >= 0:
                if (b + 17 - a) < (a - b):
                    return hex((a - 1) * 17)[2:].zfill(2)
                else:
                    return hex(a * 17)[2:].zfill(2)
            else:
                return hex(a * 17)[2:].zfill(2)

    def similarRGB(self, color):
        # Write your code here
        return "#" + self.get_similar(color[1:3]) + self.get_similar(color[3:5]) + self.get_similar(color[5:7])

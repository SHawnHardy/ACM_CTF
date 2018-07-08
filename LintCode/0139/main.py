class Solution:
    """
    @param: nums: A list of integers
    @return: A list of integers includes the index of the first number and the index of the last number
    """

    def subarraySumClosest(self, nums):
        # write your code here
        if len(nums) == 1:
            return [0, 0]

        prefix = []

        prefix.append((0, nums[0]))

        for i in range(1, len(nums)):
            prefix.append((i, prefix[-1][1] + nums[i]))

        prefix.sort(key=lambda x: x[1])
        print(prefix)
        result_det = abs(prefix[0][1])
        result = [0, prefix[0][0]]

        for i in range(1, len(prefix)):
            if abs(prefix[i][1]) < result_det:
                tmp_det = abs(prefix[i][1])
                result = [0, prefix[i][0]]

            tmp_det = abs(prefix[i][1] - prefix[i - 1][1])
            if tmp_det < result_det:
                result_det = tmp_det
                result = [min(prefix[i][0], prefix[i - 1][0]) + 1, max(prefix[i][0], prefix[i - 1][0])]

        return result

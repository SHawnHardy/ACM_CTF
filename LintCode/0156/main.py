"""
Definition of Interval.
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""


class Solution:
    """
    @param intervals: interval list.
    @return: A new interval list.
    """

    def merge(self, intervals):
        # write your code here
        intervals.sort(key=lambda x: x.start)
        ite = 1
        while ite < len(intervals):
            if intervals[ite - 1].end >= intervals[ite].start:
                intervals[ite - 1].end = max(intervals[ite].end, intervals[ite - 1].end)
                intervals.pop(ite)
                continue
            ite += 1
        return intervals

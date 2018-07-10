"""
Definition of SegmentTreeNode:
class SegmentTreeNode:
	def __init__(self, start, end, max):
		self.start, self.end, self.max = start, end, max
		self.left, self.right = None, None
"""


class Solution:
    """
    @param A: a list of integer
    @return: The root of Segment Tree
    """

    def func(self, l, r, A):
        if l == r:
            return SegmentTreeNode(l, r, A[l])

        result = SegmentTreeNode(l, r, 0)
        mid = (l + r) >> 1
        result.left = self.func(l, mid, A)
        result.right = self.func(mid + 1, r, A)
        result.max = max(result.left.max, result.right.max)
        return result

    def build(self, A):
        # write your code here
        return self.func(0, len(A) - 1, A)

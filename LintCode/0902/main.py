"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""


class Solution:
    """
    @param root: the given BST
    @param k: the given k
    @return: the kth smallest element in BST
    """

    k = 0
    ans = None

    def ldr(self, root):
        if root.left:
            self.ldr(root.left)
        if self.k < 0:
            return
        self.k -= 1
        if self.k == 0:
            self.ans = root.val
            return
        if root.right:
            self.ldr(root.right)

    def kthSmallest(self, root, k):
        # write your code here
        self.k = k
        self.ldr(root)
        return self.ans

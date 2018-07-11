"""
Definition of TreeNode:
class TreeNode:
	def __init__(self, val):
		self.val = val
		self.left, self.right = None, None
"""


class Solution:
    """
    @param: root: The root of the binary search tree.
    @param: node: insert this node into the binary search tree
    @return: The root of the new binary search tree.
    """

    def insertNode(self, root, node):
        # write your code here
        current = root
        if not root:
            return node
        while True:
            if node.val <= current.val:
                if current.left:
                    current = current.left
                    continue
                else:
                    current.left = node
                    break
            else:
                if current.right:
                    current = current.right
                    continue
                else:
                    current.right = node
                    break
        return root

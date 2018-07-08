"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""


class Solution:
    """
    @param root: An object of TreeNode, denote the root of the binary tree.
    This method will be invoked first, you should design your own algorithm 
    to serialize a binary tree which denote by a root node to a string which
    can be easily deserialized by your own "deserialize" method later.
    """

    def serialize(self, root):
        # write your code here
        def dfs(node, rst):
            rst.append(str(node.val))
            if node.left == None:
                rst.append("#")
            else:
                dfs(node.left, rst)

            if node.right == None:
                rst.append("#")
            else:
                dfs(node.right, rst)

        rst = []
        if root == None:
            rst.append("#")
        else:
            dfs(root, rst)
        return ",".join(rst)

    """
    @param data: A string serialized by your serialize method.
    This method will be invoked second, the argument data is what exactly
    you serialized at method "serialize", that means the data is not given by
    system, it's given by your own serialize method. So the format of data is
    designed by yourself, and deserialize it here as you serialize it in 
    "serialize" method.
    """

    def deserialize(self, data):
        # write your code here
        data = data.split(',')
        idx = 1

        def dfs(idx):
            node = None
            if data[idx] != "#":
                node = TreeNode(int(data[idx]))
                idx += 1
                idx, node.left = dfs(idx)
                idx, node.right = dfs(idx)
            else:
                node = None
                idx += 1
            return idx, node

        return dfs(0)[1]


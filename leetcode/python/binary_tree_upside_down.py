from util import TreeNode


class Solution:
    # @param root, a tree node
    # @return root of the upside down tree
    def upsideDownBinaryTree(self, root):
        pre = leaf = None
        while root:
            root.left, root.right, pre, root, leaf = leaf, pre, root, root.left, root.right
        return pre

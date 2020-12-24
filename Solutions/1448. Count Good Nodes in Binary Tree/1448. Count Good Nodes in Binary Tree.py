# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode,val=-10000) -> int:
        return self.goodNodes(root.left,max(val,root.val))+self.goodNodes(root.right,max(val,root.val))+(val<=root.val) if root else 0
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# set implementation
class Solution:
    def findTarget(self, root: TreeNode, k: int) -> bool:
        def dfs(s,root,k):
            if root==None:
                return False
            if k-root.val in s:
                return True
            s.add(root.val)
            return dfs(s,root.left,k) or dfs(s,root.right,k)         
        s=set()
        return dfs(s,root,k)
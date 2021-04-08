# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    cnt=[0]*10
    def pseudoPalindromicPaths (self,root,odds=0,res=0) -> int:
        res=0
        if root:
            self.cnt[root.val]+=1
            odds+=1 if self.cnt[root.val]%2==1 else -1
            if root.left==root.right:
                res=1 if odds<2 else 0
            else:
                res=self.pseudoPalindromicPaths(root.left,odds)+self.pseudoPalindromicPaths(root.right,odds)
            self.cnt[root.val]-=1
            odds+=1 if self.cnt[root.val]%2==-1 else 1
        return res
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deepestLeavesSum(self, root: TreeNode) -> int:
        res,maxlevel=0,0
        def deep(root,level):
            nonlocal maxlevel,res
            if root:
                deep(root.left,level+1)
                deep(root.right,level+1)
                if not root.left and not root.right and maxlevel<=level:
                    if maxlevel<level:
                        maxlevel=level
                        res=root.val
                    else:
                        res+=root.val
        deep(root,0)
        return res
        





# implemented by queue(BFS)

class Solution:
    def deepestLeavesSum(self, root: TreeNode) -> int:
        q,res=[],0
        q.append(root)
        while q:
            res=0
            size=len(q)
            for i in range(size):
                node=q[0]
                q=q[1:]
                res+=node.val
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
        return res
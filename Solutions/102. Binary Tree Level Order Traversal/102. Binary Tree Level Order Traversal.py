# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        q,res=[],[]
        if not root:
            return res
        q.append(root)
        while q:
            sz=len(q)
            tmp=[]
            for i in range(sz):
                if q[0].left:
                    q.append(q[0].left)
                if q[0].right:
                    q.append(q[0].right)
                tmp.append(q[0].val)
                q.pop(0)
            res.append(tmp)
        return res
            
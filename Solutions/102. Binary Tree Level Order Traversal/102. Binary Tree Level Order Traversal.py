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
                q=q[1:]
            res.append(tmp)
        return res
            
#DFS            
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        res=[]
        def dfs(root,depth):
            if not root:
                return
            if len(res)==depth:
                res.append([])
            res[depth].append(root.val)
            dfs(root.left,depth+1)
            dfs(root.right,depth+1)
        dfs(root,0)
        return res        
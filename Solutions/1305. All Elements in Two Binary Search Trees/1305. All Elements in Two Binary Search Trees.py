# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        def inorder(node:TreeNode)->None:
            if not node:
                return
            inorder(node.left)
            res.append(node.val)
            inorder(node.right)
        res=[]
        inorder(root1)
        inorder(root2)
        return sorted(res)
        
        
        
        





#update add new implementation,credit to https://leetcode.com/votrubac/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        def pushleft(s: List[int],root: TreeNode):
            while root!=None:
                s.append(root)
                root=root.left
        s1,s2=[],[]
        pushleft(s1,root1)
        pushleft(s2,root2)
        res=[]
        while s1 or s2:
            s=s2 if not s1 else s1 if not s2 else s1 if s1[-1].val<s2[-1].val else s2
            n=s.pop()
            res.append(n.val)
            if n.right!=None:
                pushleft(s,n.right)
        return res
        
        
    
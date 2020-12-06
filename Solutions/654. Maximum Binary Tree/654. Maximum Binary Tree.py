# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> TreeNode:
        return self.BuildTree(nums,0,len(nums)-1)
    def BuildTree(self, nums: List[int], left: int, right :int):
        if left>right:
            return None
        maxvalue,maxindex=-9999,0
        for i in range(left,right+1):
            if nums[i]>maxvalue:
                maxvalue=nums[i]
                maxindex=i
        root=TreeNode(maxvalue)
        root.left=self.BuildTree(nums,left,maxindex-1) 
        root.right=self.BuildTree(nums,maxindex+1,right) 
        return root
        
        
# stack implementaion
class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> TreeNode:
        stk=[]
        for i in range(len(nums)):
            curr=TreeNode(nums[i])
            while stk and stk[-1].val<curr.val:
                curr.left=stk[-1]
                stk.pop()
            if stk:
                stk[-1].right=curr
            stk.append(curr)
        return stk[0]
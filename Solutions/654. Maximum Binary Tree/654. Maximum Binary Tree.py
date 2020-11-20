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
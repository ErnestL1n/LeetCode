/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

var res int

func minCameraCover(root *TreeNode) int {
    res=0
    if dfs(root)<1{
        return res+1
    }else{
        return res
    }
}

func dfs(root *TreeNode) int{
    if root==nil{
        return 2
    }
    left,right:=dfs(root.Left),dfs(root.Right)
    if left==0 || right==0{
        res+=1
        return 1
    }
    if left==1 || right==1{
        return 2
    }else{
        return 0
    }
}
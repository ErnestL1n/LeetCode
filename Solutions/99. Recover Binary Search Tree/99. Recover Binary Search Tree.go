/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

var first,second,prev *TreeNode

func recoverTree(root *TreeNode)  {
    first,second=nil,nil
    prev=new(TreeNode)
    prev.Val=math.MinInt
    traverse(root)
    first.Val,second.Val=second.Val,first.Val
}

func traverse(root *TreeNode) {
    if root==nil{
        return
    }
    traverse(root.Left)
    if first==nil && prev.Val>root.Val{
        first=prev
    }
    if first!=nil && prev.Val>root.Val{
        second=root
    }
    prev=root
    traverse(root.Right)
}
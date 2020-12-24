/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
import "math"
func goodNodes(root *TreeNode) int {
    if root==nil{
        return 0;
    }
    res:=0
    foo(&res,root,math.MinInt32)
    return res;
}
func foo(res *int,root *TreeNode,val int){
    if root!=nil{
        if val<=root.Val{
            *res+=1
        }
        foo(res,root.Left,max(root.Val,val))
        foo(res,root.Right,max(root.Val,val))
    }
}
func max(a,b int)int{
    if a<b{
        return b
    }
    return a
}
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func increasingBST(root *TreeNode) *TreeNode {
    return increasing(root,nil)
}

func increasing(cur,tail *TreeNode) *TreeNode {
    if cur==nil{
        return tail
    }
    res:=increasing(cur.Left,cur)
    cur.Left=nil
    cur.Right=increasing(cur.Right,tail)
    return res
}
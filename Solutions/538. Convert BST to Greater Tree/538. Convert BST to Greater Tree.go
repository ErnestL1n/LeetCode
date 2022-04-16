/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

var sum int

func convertBST(root *TreeNode) *TreeNode {
    sum=0
    reverse_inorder(root)
    return root
}

func reverse_inorder(root *TreeNode) {
    if root==nil{
        return
    }
    reverse_inorder(root.Right)
    root.Val+=sum
    sum=root.Val
    reverse_inorder(root.Left)
}
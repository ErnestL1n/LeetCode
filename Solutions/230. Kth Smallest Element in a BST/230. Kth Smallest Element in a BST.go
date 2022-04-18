/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

//Binary Search (dfs)
//time complexity: O(N) best, O(N^2) worst
func kthSmallest(root *TreeNode, k int) int {
    cnt:=count(root.Left)
    if k<=cnt{
        return kthSmallest(root.Left,k)
    }else if k>cnt+1{
        return kthSmallest(root.Right,k-cnt-1)
    }
    return root.Val
}

func count(root *TreeNode) int {
    if root==nil{
        return 0
    }
    return 1+count(root.Left)+count(root.Right)
}


//DFS in-order recursive
//time complexity: O(N)
var cnt,res int

func kthSmallest(root *TreeNode, k int) int {
    cnt=k
    dfs_inorder(root)
    return res
}

func dfs_inorder(root* TreeNode) {
    if root.Left!=nil{
        dfs_inorder(root.Left)
    }
    cnt-=1
    if cnt==0{
        res=root.Val
        return
    }
    if root.Right!=nil{
        dfs_inorder(root.Right)
    }
}


//DFS in-order iterative
//time complexity: O(N) best

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
func kthSmallest(root *TreeNode, k int) int {
    var stk []*TreeNode
    for root!=nil{
        stk=append(stk,root)
        root=root.Left
    }
    for k>0{
        n:=stk[len(stk)-1];stk=stk[:len(stk)-1]
        k-=1
        if k==0{
            return n.Val
        }
        right:=n.Right
        for right!=nil{
            stk=append(stk,right)
            right=right.Left
        }
    }
    return -1
}


//Follow up: 
//If the BST is modified often (i.e., we can do insert and delete operations) 
//and you need to find the kth smallest frequently, how would you optimize?

func kthSmallest(root *TreeNode, k int) int {
    var count []int
    dfs(root,&count)
    return count[k-1]
}

func dfs(root *TreeNode,count *[]int){
    if root==nil{
        return
    }
    dfs(root.Left,count)
    *count=append(*count,root.Val)
    dfs(root.Right,count)
}


//DFS recursive, stop early when meet kth



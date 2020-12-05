/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
//recursive
func inorderTraversal(root *TreeNode) []int {
    var res []int
    inorder(root,&res)
    return res
}

func inorder(root *TreeNode,res *[]int){
    if(root!=nil){
        inorder(root.Left,res)
        *res=append(*res,root.Val)
        inorder(root.Right,res)
    }
}

//iteration ,stack
func inorderTraversal(root *TreeNode) []int {
    var stk []*TreeNode
    var res []int
    for len(stk)>0 || root!=nil{
        for root!=nil{
            stk=append(stk,root)
            root=root.Left
        }
        top:=len(stk)-1  //top index
        root=stk[top]  
        stk=stk[:top]    //pop
        res=append(res,root.Val)
        root=root.Right
    }
    return res
}
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 
//set implementation
func findTarget(root *TreeNode, k int) bool {
    set:=make(map[int]bool)
    return dfs(root,set,k)
}
func dfs(root *TreeNode,set map[int]bool,k int) bool{
    if(root==nil){
        return false;
    }
    if _,ok:=set[k-root.Val];ok{
        return true;
    }
    set[root.Val]=true
    return dfs(root.Left,set,k) ||  dfs(root.Right,set,k)
}


//binary search method

func foo(root *TreeNode,Begin *TreeNode,k int) bool{
    if Begin==nil{
        Begin=root
    }
    if root==nil{
        return false
    }
    if search(root,k-root.Val,Begin){
        return true
    }
    return foo(root.Left,Begin,k) || foo(root.Right,Begin,k)
}

func findTarget(root *TreeNode, k int) bool {
    var Begin *TreeNode=nil
    return foo(root,Begin,k)
}
func search(root *TreeNode,complement int,Begin *TreeNode) bool{
    var curr *TreeNode=Begin
    for curr!=nil{
        if(curr.Val>complement){
            curr=curr.Left
        }else if(curr.Val<complement){
            curr=curr.Right
        }else{
            if curr==root{
                return false
            }
            return true
        }
    }
    return false
}
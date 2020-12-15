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


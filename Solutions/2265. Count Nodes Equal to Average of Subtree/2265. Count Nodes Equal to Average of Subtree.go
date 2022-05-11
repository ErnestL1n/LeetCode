/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func dfs(root *TreeNode) []int {
    if root==nil{
        return []int{0,0,0}
    }
    p1,p2:=dfs(root.Left),dfs(root.Right)
    sum,cnt:=p1[0]+p2[0]+root.Val,1+p1[1]+p2[1]
    if(root.Val==sum/cnt){
        return []int{sum,cnt,p1[2]+p2[2]+1}
    }else{
        return []int{sum,cnt,p1[2]+p2[2]}
    }
}

func averageOfSubtree(root *TreeNode) int {
    return dfs(root)[2]
}
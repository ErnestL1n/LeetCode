/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func deepestLeavesSum(root *TreeNode) int {
    sum,maxlevel:=0,0
    deep(root,0,&sum,&maxlevel)
    return sum
}
func deep(root *TreeNode,level int,sum *int,maxlevel *int){
    if root!=nil{
        deep(root.Left,level+1,sum,maxlevel)
        deep(root.Right,level+1,sum,maxlevel)
        if root.Left==nil&&root.Right==nil&&level>=*maxlevel{
            if level>*maxlevel{
                *sum=root.Val
                *maxlevel=level
            }else{
                *sum+=root.Val
            }
        }
    }
}
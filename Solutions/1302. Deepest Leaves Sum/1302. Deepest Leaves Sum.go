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



//implemented by queue(BFS)

func deepestLeavesSum(root *TreeNode) int {
    res:=0
    var q []*TreeNode
    q=append(q,root)
    for len(q)>0{
        res=0
        for i:=len(q)-1;i>=0;i-=1{
            node:=q[0]
            q=q[1:]
            res+=node.Val
            if node.Left!=nil{
                q=append(q,node.Left)
            }
            if node.Right!=nil{
                q=append(q,node.Right)
            }
        }
    }
    return res
}
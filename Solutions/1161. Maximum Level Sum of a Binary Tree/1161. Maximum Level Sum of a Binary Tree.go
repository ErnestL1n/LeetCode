/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
//BFS , level order traversal
func maxLevelSum(root *TreeNode) int {
    maxsum,level,maxlevel:=math.MinInt64,0,0
    var q []*TreeNode
    q=append(q,root)
    for len(q)>0{
        level+=1
        sum,qsz:=0,len(q)
        for qsz>0{
            qsz-=1
            tmp:=q[0]
            q=q[1:]
            sum+=tmp.Val
            if tmp.Left!=nil{
                q=append(q,tmp.Left)
            }
            if tmp.Right!=nil{
                q=append(q,tmp.Right)
            }
        }
        if maxsum<sum{
            maxsum,maxlevel=sum,level
        }   
    }
    return maxlevel
}
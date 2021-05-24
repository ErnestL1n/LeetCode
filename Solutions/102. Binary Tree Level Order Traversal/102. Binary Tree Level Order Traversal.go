/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 //BFS
func levelOrder(root *TreeNode) [][]int {
    var q []*TreeNode
    var res [][]int
    if root==nil{
        return res
    }
    q=append(q,root)
    for len(q)>0{
        levelNum:=len(q)
        var tmp []int
        for i:=0;i<levelNum;i+=1{
            if q[0].Left!=nil{
                q=append(q,q[0].Left)
            }
            if q[0].Right!=nil{
                q=append(q,q[0].Right)
            }
            tmp=append(tmp,q[0].Val)
            q=q[1:]
        }
        res=append(res,tmp)
    }
    return res
}
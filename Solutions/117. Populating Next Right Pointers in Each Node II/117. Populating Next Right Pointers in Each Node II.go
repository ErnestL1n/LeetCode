/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Left *Node
 *     Right *Node
 *     Next *Node
 * }
 */

func connect(root *Node) *Node {
    var q []*Node
    if root!=nil{
        q=append(q,root)
    }
    for len(q)>0{
        sz:=len(q)
        var prev *Node
        prev=nil
        for i:=0;i<sz;i+=1{
            cur:=q[0];q=q[1:]
            cur.Next=prev
            prev=cur
            if cur.Right!=nil{
                q=append(q,cur.Right)
            }
            if cur.Left!=nil{
                q=append(q,cur.Left)
            }
        }
    }
    return root
}
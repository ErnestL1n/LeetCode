/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 //recursive
func increasingBST(root *TreeNode) *TreeNode {
    return increasing(root,nil)
}

func increasing(cur,tail *TreeNode) *TreeNode {
    if cur==nil{
        return tail
    }
    res:=increasing(cur.Left,cur)
    cur.Left=nil
    cur.Right=increasing(cur.Right,tail)
    return res
}


//iterative
func increasingBST(root *TreeNode) *TreeNode {
    var stk []*TreeNode
    dummyleft:=new(TreeNode)
    dummy:=dummyleft
    for root!=nil || len(stk)>0{
        if root!=nil{
            stk=append(stk,root)
            root=root.Left
        }else{
            cur:=stk[len(stk)-1]
            stk=stk[:len(stk)-1]
            root=cur.Right
            cur.Left=nil
            dummy.Right=cur
            dummy=dummy.Right
        }
    }
    return dummyleft.Right
}
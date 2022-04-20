/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
type BSTIterator struct {
    stk []*TreeNode
}


func Constructor(root *TreeNode) BSTIterator {
    iterator:=BSTIterator{}
    for root!=nil{
        iterator.stk=append(iterator.stk,root)
        root=root.Left
    }
    return iterator
}


func (this *BSTIterator) Next() int {
    n:=len(this.stk)
    tmp:=this.stk[n-1]
    this.stk=this.stk[:n-1]
    cur:=tmp.Right
    for cur!=nil{
        this.stk=append(this.stk,cur)
        cur=cur.Left
    }
    return tmp.Val
}


func (this *BSTIterator) HasNext() bool {
    return len(this.stk)>0
}


/**
 * Your BSTIterator object will be instantiated and called as such:
 * obj := Constructor(root);
 * param_1 := obj.Next();
 * param_2 := obj.HasNext();
 */
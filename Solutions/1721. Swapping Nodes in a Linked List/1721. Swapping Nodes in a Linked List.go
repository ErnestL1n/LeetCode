/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func swapNodes(head *ListNode, k int) *ListNode {
    p1,p2:=new(ListNode),new(ListNode)
    for p:=head;p!=nil;p=p.Next{
        if p2==nil{
            p2=nil
        }else{
            p2=p2.Next
        }
        k-=1
        if k==0{
            p1=p
            p2=head
        }
    }
    p1.Val,p2.Val=p2.Val,p1.Val
    return head
}
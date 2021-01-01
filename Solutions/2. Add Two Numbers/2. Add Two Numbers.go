/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    head:=&ListNode{Val:0}
    extra:=0
    curr:=head
    for l1!=nil || l2!=nil || extra!=0{
        if l1!=nil{
            extra+=l1.Val
            l1=l1.Next
        }
        if l2!=nil{
            extra+=l2.Val
            l2=l2.Next
        }
        curr.Next=&ListNode{Val:extra%10}
        curr=curr.Next
        extra/=10
    }
    return head.Next
}
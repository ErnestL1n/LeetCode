/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 //iterative
func reverseList(head *ListNode) *ListNode {
    var newhead *ListNode=nil
    for head!=nil{
        next:=head.Next
        head.Next=newhead
        newhead=head
        head=next
    }
    return newhead
}


//recursive
func reverseList(head *ListNode) *ListNode {
    return reverList(head,nil)
}
func reverList(head,newhead *ListNode) *ListNode{
    if head==nil{
        return newhead
    }
    next:=head.Next
    head.Next=newhead
    return reverList(next,head)
}
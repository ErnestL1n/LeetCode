/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseBetween(head *ListNode, left int, right int) *ListNode {
    pre:=new(ListNode)
    pre.Next=head
    look:=pre
    for cnt:=1;cnt<left;cnt+=1{
        look=look.Next
    }
    pro:=look.Next
    for cnt:=1;cnt<=right-left;cnt+=1{
        tmp:=look.Next
        look.Next=pro.Next
        pro.Next=pro.Next.Next
        look.Next.Next=tmp
    }
    return pre.Next
}
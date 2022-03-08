/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func hasCycle(head *ListNode) bool {
    fast,slow:=head,head
    for fast!=nil{
        if fast.Next==nil{
            return false
        }
        fast=fast.Next.Next
        slow=slow.Next
        if fast==slow{
            return true
        }
    }
    return false
}
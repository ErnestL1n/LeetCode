/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
    t:=head
    sz,st:=0,0
    for ;t!=nil;t=t.Next{
        sz+=1
    }
    if sz==n{
        return head.Next
    }
    t=head
    for t!=nil{
        st+=1
        if st==sz-n && t.Next!=nil{
            t.Next=t.Next.Next
        }
        t=t.Next
    }
    return head
}

func removeNthFromEnd(head *ListNode, n int) *ListNode {
    fast,slow:=head,head
    for i:=0;i<n;i+=1{
        fast=fast.Next
    }
    if fast==nil{
        return head.Next
    }
    for fast.Next!=nil{
        fast=fast.Next
        slow=slow.Next
    }
    slow.Next=slow.Next.Next
    return head
}
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func middleNode(head *ListNode) *ListNode {
    slow,fast:=head,head;
    for fast!=nil && fast.Next!=nil{
        fast=fast.Next.Next
        slow=slow.Next
    }
    return slow
}

func middleNode(head *ListNode) *ListNode {
    var A []*ListNode
    A=append(A,head)
    for A[len(A)-1].Next!=nil{
        A=append(A,A[len(A)-1].Next)
    }
    return A[len(A)/2]
}
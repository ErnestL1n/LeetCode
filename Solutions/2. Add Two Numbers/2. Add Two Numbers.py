# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        head=ListNode(0)
        curr,extra=head,0
        while l1 or l2 or extra:
            if l1:
                extra+=l1.val
                l1=l1.next
            if l2:
                extra+=l2.val
                l2=l2.next
            curr.next=ListNode(extra%10)
            curr=curr.next
            extra//=10
        return head.next

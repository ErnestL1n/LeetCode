# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        t=head
        sz,st=0,0
        while t:
            sz+=1
            t=t.next
        if sz==n:
            return head.next
        t=head
        while t:
            st+=1
            if st==sz-n and t.next:
                t.next=t.next.next
            t=t.next
        return head
            

# one pass
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        fast,slow=head,head
        for i in range(n):
            fast=fast.next
        if not fast:
            return head.next
        while fast.next:
            fast=fast.next
            slow=slow.next
        slow.next=slow.next.next
        return head
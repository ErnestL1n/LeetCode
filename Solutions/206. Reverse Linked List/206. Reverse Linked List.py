# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        newhead=None
        while head:
            next=head.next
            head.next=newhead
            newhead=head
            head=next
        return newhead


        
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        def reverseList(head,newhead):
            if not head:
                return newhead
            next=head.next
            head.next=newhead
            return reverseList(next,head)
        return reverseList(head,None)



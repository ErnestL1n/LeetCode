# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: ListNode, left: int, right: int) -> ListNode:
        pre=ListNode(0)
        pre.next=head
        look=pre
        for cnt in range(1,left):
            look=look.next
        pro=look.next
        for cnt in range(1,right-left+1):
            tmp=look.next
            look.next=pro.next
            pro.next=pro.next.next
            look.next.next=tmp
        return pre.next
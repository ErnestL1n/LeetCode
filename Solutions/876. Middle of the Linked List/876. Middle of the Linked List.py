# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def middleNodeFastAndSlow(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        slow=fast=head
        while fast and fast.next:
            slow=slow.next
            fast=fast.next.next
        return slow
		
		
	def middleNode(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        A=[head]
        while A[-1].next:
            A.append(A[-1].next)
            return A[len(A)/2]
        
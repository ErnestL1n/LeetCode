class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        fast,slow=head,head
        while fast:
            if not fast.next:
                return False
            fast=fast.next.next
            slow=slow.next
            if fast==slow:
                return True
        return False
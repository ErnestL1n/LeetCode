/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode t=head;
        int sz=0,st=0;
        for(;t!=null;t=t.next)
            ++sz;
        if(sz==n)
            return head.next;
        t=head;
        while(t!=null){
            if(++st==sz-n&&t.next!=null)
                t.next=t.next.next;
            t=t.next;
        }
        return head;
    }
}

class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode fast=head,slow=head;
        for(int i=0;i<n;++i)
            fast=fast.next;
        if(fast==null)
            return head.next;
        while(fast.next!=null){
            fast=fast.next;
            slow=slow.next;
        }
        slow.next=slow.next.next;
        return head;
    }
}
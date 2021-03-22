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
    public ListNode reverseList(ListNode head) {
        return reverseList(head,null);
    }
    private ListNode reverseList(ListNode head,ListNode newhead){
        if(head==null)
            return newhead;
        var next=head.next;
        head.next=newhead;
        return reverseList(next,head);
    }
}

class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode newhead=null;
        while(head!=null){
            var next=head.next;
            head.next=newhead;
            newhead=head;
            head=next;
        }
        return newhead;
    }
}
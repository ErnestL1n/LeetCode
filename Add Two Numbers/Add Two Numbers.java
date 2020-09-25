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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode preHead=new ListNode(0);
        ListNode p=preHead;
        int extra=0;
        while(l1!=null||l2!=null||extra!=0){
            if(l1!=null){
                extra+=l1.val;
                l1=l1.next;
            }
            if(l2!=null){
                extra+=l2.val;
                l2=l2.next;
            }
            p.next=new ListNode(extra%10);
            extra/=10;
            p=p.next;
        }
        return preHead.next;
    }
}
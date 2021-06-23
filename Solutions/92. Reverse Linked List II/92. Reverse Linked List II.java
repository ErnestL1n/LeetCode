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
    public ListNode reverseBetween(ListNode head, int left, int right) {
        ListNode pre=new ListNode(0),look=pre;
        pre.next=head;
        for(int cnt=1;cnt<left;++cnt)
            look=look.next;
        ListNode pro=look.next;
        for(int cnt=1;cnt<=right-left;++cnt){
            ListNode tmp=look.next;
            look.next=pro.next;
            pro.next=pro.next.next;
            look.next.next=tmp;
        }
        return pre.next;
    }
}
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
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        ListNode f=list1;
        for(int i=0;i<=a-2;++i)
            f=f.next;
        ListNode s=list1;
        for(int i=0;i<=b;++i)
            s=s.next;
        ListNode tmp=list2;
        while(tmp.next!=null)
            tmp=tmp.next;
        f.next=list2;
        tmp.next=s;
        return list1;
    }
}
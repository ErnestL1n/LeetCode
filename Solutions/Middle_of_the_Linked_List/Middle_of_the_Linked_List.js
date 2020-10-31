/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var middleNodeFastAndSlow = function(head) {
    slow=fast=head;
    while(fast&&fast.next){
        slow=slow.next;
        fast=fast.next.next;
    }
    return slow;
};
var middleNode = function(head) {
    let A = [head];
    while(A[A.length-1].next!=null)
        A.push(A[A.length-1].next);
    return A[Math.trunc(A.length/2)];
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *x=headA,*y=headB;
    while(x!=y){
        x=x?x->next:headB;
        y=y?y->next:headA;
    }
    return x;
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* prehead=malloc(sizeof(struct ListNode));
    prehead->val=0;
    prehead->next=NULL;
    struct ListNode* p=prehead;
    int extra=0;
    while(l1 || l2 || extra){
        if(l1){
            extra+=l1->val;
            l1=l1->next;
        }
        if(l2){
            extra+=l2->val;
            l2=l2->next;
        }
        p->next=malloc(sizeof(struct ListNode));
        p->next->val=extra%10;
        p->next->next=NULL;
        p=p->next;
        extra/=10;
    }
    p->next=NULL;
    return prehead->next;
}
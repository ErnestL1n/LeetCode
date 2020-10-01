/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* prehead=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* p=prehead;
    int extra=0;
    while(extra!=0||l1!=NULL||l2!=NULL){
        if(l1!=NULL){
            extra+=l1->val;
            l1=l1->next;
        }
        if(l2!=NULL){
            extra+=l2->val;
            l2=l2->next;
        }
        struct ListNode* temp=(struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val=extra%10;
        extra/=10;
        p->next=temp;
        p=p->next;
    }
    p->next=NULL;
    return prehead->next;
}
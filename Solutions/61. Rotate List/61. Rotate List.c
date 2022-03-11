/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
    if(!head){
        return head;
    }
    int len=1;
    struct ListNode* newhead=head,*tail=head;
    while(tail->next){
        tail=tail->next;
        ++len;
    }
    tail->next=head;
    if(k%=len){
        for(int i=0;i<len-k;++i){
            tail=tail->next;
        }
    }
    newhead=tail->next;
    tail->next=NULL;
    return newhead;
}
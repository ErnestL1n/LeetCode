/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//recursive
struct ListNode* foo(struct ListNode*,struct ListNode*);

struct ListNode* reverseList(struct ListNode* head){
    return foo(head,NULL);
}
struct ListNode* foo(struct ListNode* head,struct ListNode* newhead){
    if(!head){
        return newhead;
    }
    struct ListNode* tmp=head->next;
    head->next=newhead;
    return foo(tmp,head);
}

//iterative
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* newhead=NULL;
    while(head){
        struct ListNode* tmp=head->next;
        head->next=newhead;
        newhead=head;
        head=tmp;
    }
    return newhead;
}
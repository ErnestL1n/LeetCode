/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    if(!head){
        return NULL;
    }
    if(head->next && head->val==head->next->val){
        while(head->next && head->val==head->next->val){
            head=head->next;
        }
        return deleteDuplicates(head->next);
    }else{
        head->next=deleteDuplicates(head->next);
    }
    return head;
}

//iterative
struct ListNode* deleteDuplicates(struct ListNode* head){
    if(!head){
        return NULL;
    }
    struct ListNode *newhead=malloc(sizeof(struct ListNode));
    newhead->next=NULL;
    newhead->val=0;
    newhead->next=head;
    struct ListNode* pre=newhead;
    struct ListNode* cur=head;
    while(cur){
        while(cur->next && cur->val==cur->next->val){
            cur=cur->next;
        }
        if(pre->next==cur){
            pre=pre->next;
        }else{
            pre->next=cur->next;
        }
        cur=cur->next;
    }
    return newhead->next;
}
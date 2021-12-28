/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode* newhead=(struct ListNode*)malloc(sizeof(struct ListNode)*1);
    struct ListNode* tmp=newhead;
    while(list1 && list2){
        if(list1->val<list2->val){
            tmp->next=list1;
            tmp=tmp->next;
            list1=list1->next;
        }else{
            tmp->next=list2;
            tmp=tmp->next;
            list2=list2->next;
        }
    }
    tmp->next=list1?list1:list2;
    return newhead->next;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if(!list1){
        return list2;
    }
    if(!list2){
        return list1;
    }
    if(list1->val<list2->val){
        list1->next=mergeTwoLists(list1->next,list2);
        return list1;
    }else{
        list2->next=mergeTwoLists(list1,list2->next);
        return list2;
    }
}
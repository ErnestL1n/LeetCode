/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* copyRandomList(struct Node* head) {
    if(!head){
        return NULL;
    }   
    struct Node* tmp=head;
    while(tmp){
        struct Node* node=malloc(sizeof(struct Node));
        node->val=tmp->val;
        node->next=node->random=NULL;
        node->next=tmp->next;
        tmp->next=node;
        tmp=node->next;
    }
    tmp=head;
    while(tmp){
        tmp->next->random=tmp->random?tmp->random->next:NULL;
        tmp=tmp->next->next;
    }
    struct Node* res=head->next;
    tmp=head->next;
    while(head){
        head->next=tmp->next;
        head=head->next;
        if(!head){
            break;
        }
        tmp->next=head->next;
        tmp=tmp->next;
    }
    return res;
}
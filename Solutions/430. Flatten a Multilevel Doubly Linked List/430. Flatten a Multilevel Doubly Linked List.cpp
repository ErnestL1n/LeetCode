/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head){
            return head;
        }
        auto p=head;
        while(p){
            if(p->child==nullptr){
                p=p->next;
                continue;
            }
            auto tmp=p->child;
            while(tmp->next){
                tmp=tmp->next;
            }
            tmp->next=p->next;
            if(p->next){
                p->next->prev=tmp;
            }
            p->next=p->child; 
            p->child->prev=p;
            p->child=nullptr;
        }
        return head;
    }
};
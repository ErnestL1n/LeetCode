/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return nullptr;
        }   
        Node* tmp=head;
        while(tmp){
            Node* node=new Node(tmp->val);
            node->next=tmp->next;
            tmp->next=node;
            tmp=node->next;
        }
        tmp=head;
        while(tmp){
            tmp->next->random=tmp->random?tmp->random->next:nullptr;
            tmp=tmp->next->next;
        }
        Node* res=head->next;
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
};
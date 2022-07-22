/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode n1(0),n2(0);
        ListNode* p1=&n1,*p2=&n2;
        while(head){
            if(head->val<x){
                p1=p1->next=head;
            }else{
                p2=p2->next=head;
            }
            head=head->next;
        }
        p2->next=nullptr;
        p1->next=n2.next;
        return n1.next;
    }
};
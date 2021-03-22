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
    ListNode* reverseList(ListNode* head) {
        return reverseList(head,nullptr);
    }
    ListNode* reverseList(ListNode* head,ListNode* newhead){
        if(!head)
            return newhead;
        auto next=head->next;
        head->next=newhead;
        return reverseList(next,head);
    }
};

//iterative solution: change the pointer direction one by one
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* newhead=nullptr;
        while(head){
            auto next=head->next;
            head->next=newhead;
            newhead=head;
            head=next;
        }
        return newhead;
    }
};
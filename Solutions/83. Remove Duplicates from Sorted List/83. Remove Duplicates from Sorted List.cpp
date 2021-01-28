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
 
 //recursive solution
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head||!head->next)return head;
        head->next=deleteDuplicates(head->next);
        return head->val==head->next->val?head->next:head;
    }
};

//iterative solution
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* t=head;
        while(t){
            while(t->next&&t->val==t->next->val)
                t->next=t->next->next;
            t=t->next;
        }
        return head;
    }
};
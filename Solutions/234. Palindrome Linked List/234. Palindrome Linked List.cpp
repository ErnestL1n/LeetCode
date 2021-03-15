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
    bool isPalindrome(ListNode* head) {
        ListNode* rev=nullptr;
        auto slow=head,fast=head;
        //slow run faster rev one step
        while(fast && fast->next){
            fast=fast->next->next;
            auto tmp=rev;
            rev=slow;
            slow=slow->next;
            rev->next=tmp;
        }
        //odd length
        if(fast)
            slow=slow->next;
        while(rev && rev->val==slow->val)
            slow=slow->next,rev=rev->next;
        return not rev;
    }
};
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
    ListNode* swapPairs(ListNode* head) {
        if(!head or !head->next){
            return head;
        }
        auto res=head->next;
        while(head or head->next){
            auto tmp=head->next;
            head->next=head->next->next;
            head->next->next=
        }
        return res;
    }
};
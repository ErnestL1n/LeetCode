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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* pre=new ListNode(0);
        pre->next=head;
        while(head and head->next){
            head->next=head->next->val==val?head->next->next:head->next;
            head=head->next;
        }
        return pre->next;
    }
};
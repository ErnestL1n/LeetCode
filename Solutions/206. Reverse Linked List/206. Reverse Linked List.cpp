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

//recursive solution: Operate the next pointed one ,then break my own's next pointer(point to null)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next)return head;
        ListNode *pre=reverseList(head->next);
        head->next->next=head;
        head->next=nullptr;
        return pre;
    }
};

//iterative solution: change the pointer direction one by one
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre=nullptr;
        while(head){
            ListNode *next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        return pre;
    }
};
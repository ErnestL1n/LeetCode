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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* t=head;
        int sz=0,st=0;
        for(;t;t=t->next)
            ++sz;
        if(sz==n)
            return head->next;
        t=head;
        while(t){
            if(++st==sz-n&&t->next)
                t->next=t->next->next;
            t=t->next;
        }
        return head;
    }
};
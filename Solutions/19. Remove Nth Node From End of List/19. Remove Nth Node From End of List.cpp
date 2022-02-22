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


//one pass O(n) time ,O(1) space
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast=head,*slow=head;
        for(int i=0;i<n;++i){
            fast=fast->next;
        }
        if(fast==nullptr){ //case : n is the same as the length of the list
            return head->next;
        }
        while(fast->next){
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return head;
    }
};
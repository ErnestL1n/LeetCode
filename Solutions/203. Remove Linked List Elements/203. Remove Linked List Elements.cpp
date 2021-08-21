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
//iterative
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* pre=new ListNode(0);
        pre->next=head;
        auto cur=head,p=pre;
        while(cur){
            if(cur->val==val)
                p->next=cur->next;
            else
                p=p->next;
            cur=cur->next;
        }
        return pre->next;
    }
};

//recursive
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return nullptr;
        head->next=removeElements(head->next,val);
        return head->val==val?head->next:head;
    }
};
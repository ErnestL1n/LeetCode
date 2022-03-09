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
//recursive
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head){
            return nullptr;
        }
        if(head->next and head->val==head->next->val){
            while(head->next and head->val==head->next->val){
                head=head->next;
            }
            return deleteDuplicates(head->next);
        }else{
            head->next=deleteDuplicates(head->next);
        }
        return head;
    }
};

//iterative
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head){
            return nullptr;
        }
        ListNode *newhead=new ListNode(0);
        newhead->next=head;
        ListNode* pre=newhead;
        ListNode* cur=head;
        while(cur){
            while(cur->next and cur->val==cur->next->val){
                cur=cur->next;
            }
            if(pre->next==cur){
                pre=pre->next;
            }else{
                pre->next=cur->next;
            }
            cur=cur->next;
        }
        return newhead->next;
    }
};
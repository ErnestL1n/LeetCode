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
    ListNode* sortList(ListNode* head) {
        if(!head or !head->next){
            return head;
        }
        ListNode* slow=head,*fast=head->next;
        while(fast and fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* mid=slow->next;
        slow->next=nullptr;
        return merge(sortList(head),sortList(mid));
    }
    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode* dummy=new ListNode(0);
        ListNode* tail=dummy;
        while(l1 and l2){
            if(l1->val>l2->val){
                swap(l1,l2);
            }
            tail->next=l1;
            l1=l1->next;
            tail=tail->next;
        }
        tail->next=l1?l1:l2;
        return dummy->next;
    }
};
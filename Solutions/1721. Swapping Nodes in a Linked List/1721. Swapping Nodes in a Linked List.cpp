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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* p1=nullptr,*p2=nullptr;
        for(auto p=head;p;p=p->next){
            p2=p2?p2->next:nullptr;
            if(--k==0){
                p1=p;
                p2=head;
            }
        }
        swap(p1->val,p2->val);
        return head;
    }
};
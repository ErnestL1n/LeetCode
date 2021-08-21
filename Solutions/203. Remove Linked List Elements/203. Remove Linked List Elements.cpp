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
        ListNode *p=pre,*cur=head;
        while(cur){
            if (cur->val == val) {
                p->next = cur->next;
            } else {
                p = p->next;
            }
            cur = cur->next;
        }
        return pre->next;
    }
};

//recursive
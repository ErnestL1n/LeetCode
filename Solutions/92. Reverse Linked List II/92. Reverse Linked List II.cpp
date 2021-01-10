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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head||m==n)return head;
        ListNode *rec=new ListNode(0),*pre=rec;
        rec->next=head;
        for(int i=1;i<=m-1;++i)
            pre=pre->next;
        ListNode* tail=pre->next;
        for(int i=1;i<=n-m;++i){
            ListNode *tmp=pre->next;        //a
            pre->next=tail->next;           //b
            tail->next=tail->next->next;    //c
            pre->next->next=tmp;            //d
        }
        return rec->next;
    }
};
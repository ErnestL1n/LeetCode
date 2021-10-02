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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res(k);
        int size=0;
        auto cur=head;
        while(cur)
            ++size,cur=cur->next;
        cur=head;
        int sz=size/k,r=size%k;
        ListNode* pre=nullptr;
        for(int i=0;cur and i<k;++i,--r){
            res[i]=cur;
            for(int j=0;j<(r>0)+sz;++j){
                pre=cur;
                cur=cur->next;
            }
            pre->next=nullptr;
        }
        return res;
    }
};
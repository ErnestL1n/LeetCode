// beginner friendly
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
        ListNode* tmp=head,*r;
        int size=0;
        while(tmp){
            ++size;
            tmp=tmp->next;
        }
        int begin=k,end=size-begin+1;
        if(begin>end)
            swap(begin,end);
        tmp=head;
        int s=1,q;
        while(s<=end){
            if(s==begin){
                q=tmp->val;
                r=tmp;
            }
            if(s==end){
                r->val=tmp->val;
                tmp->val=q;
            }
            tmp=tmp->next;
            ++s;
        }
        return head;
    }
};


//trick
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *p1=nullptr,*p2=nullptr;
        for(auto p=head;p!=nullptr;p=p->next){
            p2=p2==nullptr?nullptr:p2->next;
            if(--k==0){
                p1=p;
                p2=head;
            }
        }
        swap(p1->val,p2->val);
        return head;
    }
};
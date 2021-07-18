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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur=head;
        int cnt=0;
        while(cur and cnt<k)
            cur=cur->next,++cnt;
        if(cnt==k){
            cur=reverseKGroup(cur,k);
            while(cnt--){
                auto tmp=head->next;
                head->next=cur;
                cur=head;
                head=tmp;
            }
            head=cur;
        }
        return head;
    }
};

//iterative
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy=new ListNode(0),*jump=dummy,*l,*r;
        dummy->next=l=r=head;
        while(true){
            int cnt=0;
            while(r and cnt<k)
                r=r->next,++cnt;
            if(cnt==k){
                ListNode *cur=l,*pre=r;
                for(int i=0;i<k;++i){
                    auto tmp=cur->next;
                    cur->next=pre;
                    pre=cur;
                    cur=tmp;
                }
                //after the for loop ,cur is on the next group first element
                jump->next=pre;  //jump next points to the last element in previous one,for example for example 1 connect to 4
                jump=l;          //jump : used to connect last node in previous k-group to first node in following k-group  
                l=r;
            }else{
                return dummy->next;
            }
        }
    }
};
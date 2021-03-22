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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *newhead=new ListNode(0);
        newhead->next=head;
        ListNode *pre=newhead;
        //find pre and pre continues stay at left-1 
        for(int i=1;i<=left-1;++i)
            pre=pre->next;
        //current progress begin from left
        ListNode *progress=pre->next;
        //current progress pointer,until reach to right
        
        // a~d do right-left times
        for(int i=1;i<=right-left;++i){
            auto tmp=pre->next;                        //a  :1->2 (next stores)
            pre->next=progress->next;                  //b  :1->->3
            progress->next=progress->next->next;       //c  :2->->4
            pre->next->next=tmp;                       //d  :3->2 (next stores)
        }
        return newhead->next;
    }
};
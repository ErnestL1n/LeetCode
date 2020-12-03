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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* f=list1;
        for(int i=0;i<=a-2;++i)
            f=f->next;
        ListNode* s=list1;
        for(int i=0;i<=b;++i)
            s=s->next;
        ListNode* tmp=list2;
        while(tmp->next!=nullptr)
            tmp=tmp->next;
        f->next=list2;
        tmp->next=s;
        return list1;
    }
};
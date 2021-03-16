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
    bool isPalindrome(ListNode* head) {
        ListNode* rev=nullptr;
        auto slow=head,fast=head;
        //slow run faster rev one step
        while(fast && fast->next){
            fast=fast->next->next;
            auto tmp=rev;
            rev=slow;
            slow=slow->next;
            rev->next=tmp;
        }
        //odd length
        if(fast)
            slow=slow->next;
        while(rev && rev->val==slow->val)
            slow=slow->next,rev=rev->next;
        return not rev;
    }
};


//Same as the above, 
//but while comparing the two halves, 
//restore the list to its original state by reversing the first half back. Not that the OJ or anyone else cares.

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* rev=nullptr;
        auto fast=head;
        //head same as above slow , but finally it returns to origin
        while(fast && fast->next){
            fast=fast->next->next;
            auto tmp=rev;
            rev=head;
            head=head->next;
            rev->next=tmp;
        }
        ListNode* tail;
        //tail same as above code's slow
        if(fast)
            tail=head->next;
        else
            tail=head;
        auto isPal=true;
        while (rev){
            isPal = isPal and rev->val == tail->val;
            auto tmp=head;
            head=rev;
            rev=rev->next;
            head->next=tmp;
            tail = tail->next;
            }
        return isPal;
    }
};

//recursive , O(n) space
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        return foo(head,head);
    } 
    //first parameter of function foo, taking reference on ListNode* type
    bool foo(ListNode* &head,ListNode* tail){
        if(!tail)return true;
        bool isPal=foo(head,tail->next);
        if(head->val!=tail->val)
            isPal=false;
        head=head->next;
        return isPal;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// not delete next
class Solution {
public:
    void deleteNode(ListNode* node) {
        *node=*node->next;
    }
};

// delete wrong one
class Solution {
public:
    void deleteNode(ListNode* node) {
        auto next=node->next;
        *node=*next;
        delete node;
    }
};

// better properly delete the next node
class Solution {
public:
    void deleteNode(ListNode* node) {
        // 5->3->6->1->null
        auto next=node->next;
        *node=*next;
        delete next;
        // 5->3->1->null
    }
};


// code for testing above code
// #include <bits/stdc++.h>
// using namespace std;

// class ListNode {
//  public:
//   int val;
//   ListNode* next;
//   ListNode(int x) { this->val = x; }
// };

// int main() {
//   ListNode* head = new ListNode(5);
//   ListNode* a = new ListNode(3);
//   ListNode* b = new ListNode(6);
//   ListNode* c = new ListNode(1);
//   head->next = a;
//   a->next = b;
//   b->next = c;
//   c->next = nullptr;
//   auto tmp = head;
  
//   // 5->3->6->1->null
//   while (tmp) {
//     cout << tmp->val << "->";
//     tmp = tmp->next;
//   }
//   cout << "null\n";

//   auto next = b->next;
//   *b = *next;
//   delete next;

//   tmp = head;
//   // 5->3->1->null
//   while (tmp) {
//     cout << tmp->val << "->";
//     tmp = tmp->next;
//   }
//   cout << "null\n";
//   return 0;
// };

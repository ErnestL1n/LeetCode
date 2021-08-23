/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p and !q)
            return true;
        if(!p or !q)
            return false;
        if(p->val==q->val)
            return isSameTree(p->left,q->left) and isSameTree(p->right,q->right);
        return false;
    }
};


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> que;
        que.push(p);
        que.push(q);
        while(que.size()){
            auto cur1=que.front();que.pop();
            auto cur2=que.front();que.pop();
            if(!cur1 and !cur2)
                continue;
            else if(!cur1 or !cur2 or cur1->val!=cur2->val)
                return false;
            que.push(cur1->left);
            que.push(cur2->left);
            que.push(cur1->right);
            que.push(cur2->right);
        }
        return true;
    }
};
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
    int cnt[10] = {};
    int pseudoPalindromicPaths(TreeNode* n,int odds=0) {
        int res=0;
        if (n != nullptr) {
            odds += ++cnt[n->val] % 2 ? 1 : -1;
            if (n->left==nullptr and n->right==nullptr)
                res = odds < 2 ? 1 : 0;
            else
                res = pseudoPalindromicPaths(n->left,odds) 
                    + pseudoPalindromicPaths(n->right,odds);
            odds += --cnt[n->val] % 2 ? -1 : 1;
        }
        return res;
    }
};
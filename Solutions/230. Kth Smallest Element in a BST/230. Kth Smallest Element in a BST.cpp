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

//Binary Search (dfs)
//time complexity: O(N) best, O(N^2) worst
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt=count(root->left);
        if(k<=cnt){
            return kthSmallest(root->left,k);
        }else if(k>cnt+1){
            return kthSmallest(root->right,k-cnt-1);
        }
        return root->val;
    }
    int count(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        return 1+count(root->left)+count(root->right);
    }
};
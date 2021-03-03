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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root)return 0;
        if(root->val<low)return rangeSumBST(root->right,low,high);
        if(root->val>high)return rangeSumBST(root->left,low,high);
        return root->val+rangeSumBST(root->right,low,high)+rangeSumBST(root->left,low,high);
    }
};

//iterative
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int res=0;
        stack<TreeNode*> stk;
        stk.push(root);
        while(stk.size()){
            auto curr=stk.top();
            stk.pop();
            if(!curr)continue;
            if(curr->val>low)
                stk.push(curr->left);
            if(curr->val<high)
                stk.push(curr->right);
            if(curr->val<=high && curr->val>=low)
                res+=curr->val;
        }
        return res;
    }
};


class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        return (low<=root->val&&root->val<=high?root->val:0)+rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high);
    }
};


class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high){
        if (!root) { return 0; }
        int sum = 0;
        if (root->val >low) { sum += rangeSumBST(root->left, low, high); } 
        if (root->val < high) { sum += rangeSumBST(root->right, low, high); } 
        if (root->val >= low && root->val <= high) { sum += root->val; } 
        return sum;
    }
};


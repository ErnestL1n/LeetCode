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
//brute force
class Solution {
public:
    vector<int> values;
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        int res=INT_MAX;
        sort(values.begin(),values.end());
        for(int i=0;i<values.size()-1;++i)
            res=min(res,values[i+1]-values[i]);
        return res;
    }
    void dfs(TreeNode* root){
        if(root){
            values.push_back(root->val);
            dfs(root->left);
            dfs(root->right);
        }
    }
};


//inorder for BST ,best for this question setting
class Solution {
public:
    int res=INT_MAX;
    TreeNode* prev=nullptr;
    int minDiffInBST(TreeNode* root) {
        if(!root)
            return res;
        minDiffInBST(root->left);
        if(prev)
            res=min(res,root->val-prev->val);
        prev=root;
        minDiffInBST(root->right);
        return res;
    }
};

//for normal binary tree
//every time we can use O(lgN) time to lookup for the nearest values
//total:O(NlgN)
class Solution {
public:
    set<int> s;
    int res=INT_MAX;
    int minDiffInBST(TreeNode* root) {
        if(!root)
            return res;
        if(!s.empty()){
            auto lw=s.lower_bound(root->val);
            if(lw!=s.begin()){
                --lw;
                if(*lw<root->val){
                    res=min(res,root->val-*lw);
                }
            }
            auto up=s.upper_bound(root->val);
            if(*up>root->val)
                res=min(res,*up-root->val);
        }
        s.insert(root->val);
        minDiffInBST(root->left);
        minDiffInBST(root->right);
        return res;
    }
};

//for normal binary tree
//much faster than above
//O(N)
class Solution {
public:
    set<int> s;
    int res=INT_MAX;
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        for(auto i=s.begin(),j=next(i,1);j!=s.end();++i,++j)
            res=min(*j-*i,res);
        return res;
    }
    void dfs(TreeNode* root){
        if(!root)
            return;
        s.insert(root->val);
        dfs(root->left);
        dfs(root->right);
    }
};
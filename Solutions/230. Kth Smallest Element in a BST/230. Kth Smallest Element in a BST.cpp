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


//DFS in-order recursive
//time complexity: O(N)
class Solution {
public:
    int cnt,res;
    int kthSmallest(TreeNode* root, int k) {
        cnt=k;
        dfs_inorder(root);
        return res;
    }
    void dfs_inorder(TreeNode* root){
        if(root->left){
            dfs_inorder(root->left);
        }
        if(--cnt==0){
            res=root->val;
            return;
        }
        if(root->right){
            dfs_inorder(root->right);
        }
    }
};


//DFS in-order iterative
//time complexity: O(N) best
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        while(root){
            stk.push(root);
            root=root->left;
        }
        while(k){
            auto n=stk.top();stk.pop();
            if(--k==0){
                return n->val;
            }
            auto right=n->right;
            while(right){
                stk.push(right);
                right=right->left;
            }
        }
        return -1;
    }
};


//Follow up: 
//If the BST is modified often (i.e., we can do insert and delete operations) 
//and you need to find the kth smallest frequently, how would you optimize?

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> count;
        dfs(root,count);
        return count[k-1];
    }
    void dfs(TreeNode* root,vector<int>& count){
        if(!root){
            return;
        }
        dfs(root->left,count);
        count.push_back(root->val);
        dfs(root->right,count);
    }
};


//DFS recursive, stop early when meet kth
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res;
        res.push_back(k);
        findnode(root,res);
        return res[1];
    }
    void findnode(TreeNode* root,vector<int>& res){
        if(res.size()>1){
            return;
        }
        if(root->left){
            findnode(root->left,res);
        }
        if(--res[0]==0){
            res.push_back(root->val);
            return;
        }
        if(root->right){
            findnode(root->right,res);
        }
    }
};
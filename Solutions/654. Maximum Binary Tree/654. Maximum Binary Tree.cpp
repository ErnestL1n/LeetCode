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
 //recursive version
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return BuildTree(nums,0,nums.size()-1);
    }
    TreeNode* BuildTree(vector<int>&nums,int left,int right){
        if(left>right)
            return nullptr;
        int maxvalue=INT_MIN,maxindex=0;
        for(auto i=left;i<=right;++i){
            if(nums[i]>maxvalue){
                maxindex=i;
                maxvalue=nums[i];
            }
        }
        TreeNode* root=new TreeNode(maxvalue);
        root->left=BuildTree(nums,left,maxindex-1);
        root->right=BuildTree(nums,maxindex+1,right);
        return root;
    }
};


//vector stack version
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> stk;
        for(auto n:nums){
            TreeNode* curr=new TreeNode(n);
            while(!stk.empty()&&stk.back()->val<curr->val){
                curr->left=stk.back();
                stk.pop_back();
            }
            if(!stk.empty())
                stk.back()->right=curr;
            stk.push_back(curr);
        }
        return stk[0];
    }
};



// optimized to use the binary search (as our stack will be always sorted).
// credit to https://leetcode.com/votrubac/
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    vector<TreeNode*> s { new TreeNode(nums[0]) };
    for (int i = 1; i < nums.size(); ++i) {
        TreeNode* cur = new TreeNode(nums[i]);
        auto it = upper_bound(s.rbegin(), s.rend(), cur, 
                              [](const TreeNode* a, const TreeNode* b) { return a->val < b->val; });
        if (it != s.rend()) (*it)->right = cur;
        if (it != s.rbegin()) cur->left = *next(it, -1);
        s.resize(distance(it, s.rend()));
        s.push_back(cur);
    }
    return s.front();
}
};





//stack library version
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        stack<TreeNode*> stk;
        for(int i=0;i<nums.size();++i){
            TreeNode* curr=new TreeNode(nums[i]);
            while(!stk.empty()&&stk.top()->val<curr->val){
                curr->left=stk.top();
                stk.pop();
            }
            if(!stk.empty())
                stk.top()->right=curr;
            stk.push(curr);
        }
        while(stk.size()>1)
            stk.pop();
        return stk.top();
    }
};
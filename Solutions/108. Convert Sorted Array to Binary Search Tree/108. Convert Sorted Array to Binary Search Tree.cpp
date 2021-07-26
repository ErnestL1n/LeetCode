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
class Node {
public:
    TreeNode* root;
    int lidx,ridx;
    Node(TreeNode* root,int lidx,int ridx){
        this->root=root;
        this->lidx=lidx;
        this->ridx=ridx;
    } 
};
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        queue<Node*> q;
        int lo=0,hi=nums.size()-1;
        TreeNode *root=new TreeNode(nums[(lo+hi)/2]);
        q.push(new Node(root,lo,hi));
        while(q.size()){
            Node* cur=q.front();q.pop();
            int mid=(cur->lidx+cur->ridx)/2;
            if(mid!=cur->lidx){
                TreeNode* leftchild=new TreeNode(nums[(cur->lidx+mid-1)/2]);
                cur->root->left=leftchild;
                q.push(new Node(leftchild,cur->lidx,mid-1));
            }
            if(mid!=cur->ridx){
                TreeNode* rightchild=new TreeNode(nums[(mid+1+cur->ridx)/2]);
                cur->root->right=rightchild;
                q.push(new Node(rightchild,mid+1,cur->ridx));
            }
        }
        return root;
    }
};
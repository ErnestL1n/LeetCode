/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root or root==p or root==q)
            return root;
        TreeNode* l=lowestCommonAncestor(root->left,p,q);
        TreeNode* r=lowestCommonAncestor(root->right,p,q);
        if(l==nullptr)
            return r;
        if(r==nullptr)
            return l;
        return root;
    }
};


//bfs iterative
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        queue<TreeNode*> que;
        que.push(root);
        unordered_map<TreeNode*,TreeNode*> parent;
        parent[root]=nullptr;
        //if parent of p not found or parent of q not found
        while(parent.find(p)==parent.end() or parent.find(q)==parent.end()){
            auto cur=que.front();que.pop();
            if(cur->left){
                parent[cur->left]=cur;
                que.push(cur->left);
            }
            if(cur->right){
                parent[cur->right]=cur;
                que.push(cur->right);
            }
        }
        //elder
        unordered_set<TreeNode*> ancestors;
        while(p){
            ancestors.insert(p);
            p=parent[p];
        }
        //while q's parent not in ancestors
        while(ancestors.find(q)==ancestors.end()){
            q=parent[q];
        }
        return q;
    }
};
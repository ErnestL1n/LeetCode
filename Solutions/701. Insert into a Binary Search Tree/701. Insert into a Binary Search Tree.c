/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//iterative
struct TreeNode* insertIntoBST(struct TreeNode* root, int val){
    if(!root){
        struct TreeNode* root=(struct TreeNode*)malloc(sizeof(struct TreeNode));
        root->val=val;
        root->left=root->right=NULL;
        return root;
    }
    struct TreeNode* cur=root;
    while(1){
        if(cur->val<val){
            if(cur->right){
                cur=cur->right;
           }else{
                struct TreeNode* x=(struct TreeNode*)malloc(sizeof(struct TreeNode));
                x->val=val;
                x->left=x->right=NULL;
                cur->right=x;
                break;
           }
        }else{
            if(cur->left){
                cur=cur->left;
            }else{
                struct TreeNode* x=(struct TreeNode*)malloc(sizeof(struct TreeNode));
                x->val=val;
                x->left=x->right=NULL;
                cur->left=x;
                break;
           }
       }
    }  
    return root;
}

//recursive


struct TreeNode* insertIntoBST(struct TreeNode* root, int val){
    if(!root){
        root=(struct TreeNode*)malloc(sizeof(struct TreeNode));
        root->val=val;
        root->left=root->right=NULL;
        return root;
    }
    if(root->val<val){
        root->right=insertIntoBST(root->right,val);
    }else{
        root->left=insertIntoBST(root->left,val);
    }
    return root;
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// int cmp(const void *a, const void *b)
// {
//     int x=*(int*)a;
//     int y=*(int*)b;
//     if(x>y){
//         return 1;
//     }else if(x==y){
//         return 0;
//     }else{
//         return -1;
//     }
// }

void inorder(struct TreeNode* root,int* res,int* size){
    if(!root){
        return;
    }
    ++(*size);
    inorder(root->left,res,size);
    res=(int*)realloc(res,sizeof(int)*(*size));
    // res[0]=root->val;
    inorder(root->right,res,size);
}

int* getAllElements(struct TreeNode* root1, struct TreeNode* root2, int* returnSize){
    int* res=NULL;
    *returnSize=0;
    inorder(root1,res,returnSize);
    inorder(root2,res,returnSize);
    // if(res!=NULL){
    //     qsort(res,*returnSize,sizeof(int),cmp);
    // }
    return res;
}

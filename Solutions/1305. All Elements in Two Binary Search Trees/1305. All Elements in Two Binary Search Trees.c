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


//TLE or MLE

int cmp(const void *a, const void *b)
{
    int x=*(int*)a;
    int y=*(int*)b;
    if(x>y){
        return 1;
    }else if(x==y){
        return 0;
    }else{
        return -1;
    }
}

void inorder(struct TreeNode* root,int** res,int* size){
    if(!root){
        return;
    }
    inorder(root->left,res,size);
    *res=(int*)realloc(*res,++(*size)*sizeof(int));
    (*res)[(*size)-1]=root->val;
    inorder(root->right,res,size);
}

int* getAllElements(struct TreeNode* root1, struct TreeNode* root2, int* returnSize){
    int* res=NULL;
    *returnSize=0;
    inorder(root1,&res,returnSize);
    inorder(root2,&res,returnSize);
    qsort(res,*returnSize,sizeof(int),cmp);
    return res;
}


//AC
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
#define or ||
#define and &&

void inorder(struct TreeNode* root,int** t,int* size){
    if(!root){
        return;
    }
    inorder(root->left,t,size);
    *t=(int*)realloc(*t,++(*size)*sizeof(int));
    (*t)[(*size)-1]=root->val;
    inorder(root->right,t,size);
}

int* getAllElements(struct TreeNode* root1, struct TreeNode* root2, int* returnSize){
    int* t1=NULL,*t2=NULL;
    int s1=0,s2=0;
    inorder(root1,&t1,&s1);
    inorder(root2,&t2,&s2);
    *returnSize=s1+s2;
    int* res=(int*)malloc(sizeof(int)*(*returnSize));
    int idx=0,x=s1,y=s2;
    while(x>0 or y>0){
        if((y<=0) or (x>0 and t1[s1-x]<t2[s2-y])){
            res[idx++]=t1[s1-x];
            --x;
        }else{
            res[idx++]=t2[s2-y];
            --y;
        }
    }
    free(t1);
    free(t2);
    return res;
}

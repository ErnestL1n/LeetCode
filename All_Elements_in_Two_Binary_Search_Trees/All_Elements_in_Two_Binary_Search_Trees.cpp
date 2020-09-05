/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1305
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){};
    TreeNode(int value):val(value){};
    TreeNode(int value,TreeNode* leftchild,TreeNode*rightchild):val(value),left(leftchild),right(rightchild){};
};
class All_Elements_in_Two_Binary_Search_Trees{
    public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2){
        vector<int> res;
        inorder(root1,res);
        inorder(root2,res);
        sort(res.begin(),res.end());
        return res;
    }
    void inorder(TreeNode* root,vector<int>& res){
        if(root==nullptr)
        return;
        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right,res);
    }
    TreeNode* BuildTree(vector<int>& nodes){
        if(nodes.empty()||nodes.size()==0)
        return nullptr;
        queue<int> intqueue;
        queue<TreeNode*> treenodequeue;
        TreeNode* root=new TreeNode(nodes[0]);
        treenodequeue.push(root);
        for(int i=1;i<nodes.size();++i)
        intqueue.push(nodes[i]);
        while(!intqueue.empty()){
            TreeNode* curr=treenodequeue.front();
            treenodequeue.pop();
            int leftvalue,rightvalue;
            if(!intqueue.empty()){
                leftvalue=intqueue.front();
                intqueue.pop();
            }
            if(!intqueue.empty()){
                rightvalue=intqueue.front();
                intqueue.pop();
            }
            if(leftvalue!=NULL){
                TreeNode* leftchild=new TreeNode(leftvalue);
                treenodequeue.push(leftchild);
                curr->left=leftchild;
            }
            if(rightvalue!=NULL){
                TreeNode* rightchild=new TreeNode(rightvalue);
                treenodequeue.push(rightchild);
                curr->right=rightchild;
            }
        }
        return root;
    }
    int TreeSize(TreeNode* root){
        if(root==nullptr)
        return 0;
        int totalcount=1;
        queue<TreeNode*> treenodequeue;
        treenodequeue.push(root);
        while(!treenodequeue.empty()){
            TreeNode* curr=treenodequeue.front();
            treenodequeue.pop();
            if(curr->left!=nullptr){
                ++totalcount;
                treenodequeue.push(curr->left);
                }
            if(curr->right!=nullptr){
                ++totalcount;
                treenodequeue.push(curr->right);
            }
        }
        return totalcount;
    }
    void printTree(TreeNode* root){
        if(root==nullptr)return;
        queue<TreeNode*> treenodequeue;
        int treesize=TreeSize(root);
        treenodequeue.push(root);
        cout << "I am root ,my value is "<< root->val <<"\n";
        --treesize;
        while(treesize!=0){
            TreeNode* curr=treenodequeue.front();
            treenodequeue.pop();
            if(curr->left!=nullptr){
                treenodequeue.push(curr->left);
                cout << "I am leftchild of value " << curr->val <<" , my value is " << curr->left->val <<"\n";
                --treesize;
            }
            if(curr->right!=nullptr){
                treenodequeue.push(curr->right);
                cout << "I am rightchild of value " << curr->val <<" , my value is " << curr->right->val <<"\n";
                --treesize;
            }
        }
    }
};
int main(){
    All_Elements_in_Two_Binary_Search_Trees c;
    vector<int> nodes1={2,1,4};
    vector<int> nodes2={5,1,7,9,2};
    TreeNode* root1=c.BuildTree(nodes1);
    TreeNode* root2=c.BuildTree(nodes2);
    c.printTree(root1);
    c.printTree(root2);
    return 0;
}

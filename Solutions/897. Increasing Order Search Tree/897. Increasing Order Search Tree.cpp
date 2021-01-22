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
 
 //Recursive
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        return foo(root,nullptr);
    }
    TreeNode* foo(TreeNode* root,TreeNode* tail){
        if(!root)return tail;
        TreeNode* res=foo(root->left,root);
        root->left=nullptr;
        root->right=foo(root->right,tail);
        return res;
    }
};

//Iterative
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode*> st;
        //point to the leftmostchild
        TreeNode* dummyleftupside=new TreeNode();
		TreeNode* dummymove=dummyleftupside;
        while(root||st.size()) {
			if(root) {
				st.push(root);
				root=root->left;
			}
			else {
				TreeNode* current=st.top();
                st.pop();				
				//tricky part,check if there is righthchild 
				root=current->right;
				current->left=nullptr;
				dummymove->right=current;
				dummymove=dummymove->right;	
			}
		}
		return dummyleftupside->right;
    }
};
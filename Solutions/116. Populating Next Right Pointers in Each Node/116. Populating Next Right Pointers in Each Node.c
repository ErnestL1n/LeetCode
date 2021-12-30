/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

//dfs
struct Node* connect(struct Node* root) {
    if(!root){
        return NULL;
    }
    struct Node* l=root->left,*r=root->right,*n=root->next;
    if(l){
        l->next=r;
        if(n){
            r->next=n->left;
        }
        connect(root->left);
        connect(root->right);
    }
    return root;
}

//bfs
struct Node* connect(struct Node* root) {
    struct Node* head=root;
    for(;root;root=root->left){
        for(struct Node* cur=root;cur;cur=cur->next){
            if(cur->left){
                cur->left->next=cur->right;
                if(cur->next){
                    cur->right->next=cur->next->left;
                }
            }
        }
    }
    return head;
}
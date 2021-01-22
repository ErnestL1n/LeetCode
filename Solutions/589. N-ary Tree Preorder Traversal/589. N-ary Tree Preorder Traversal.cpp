#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
class Node {
public:
	int val;
	vector<Node*> child;
public:
	Node() :val(0),child(vector<Node*>()){};
	Node(int value) :val(value),child(vector<Node*>()){};
	Node(int value, vector<Node*> children):val(value),child(children) {};
};
class N_ary_Tree_Preorder_Traversal {
public:
	Node* BuildTree(vector<int>& nodes) {
		if (nodes.empty() || nodes.size() == 0)
			return nullptr;
		queue<Node*> treenodequeue;
		queue<int> intqueue;
		Node* root = new Node(nodes[0]);
		treenodequeue.push(root);
		for (int i = 1;i != nodes.size();++i){
			intqueue.push(nodes[i]);
		}
		while (!intqueue.empty()) {
			Node* curr = treenodequeue.front();
			treenodequeue.pop();
			if (intqueue.front() == NULL)
				intqueue.pop();
			while (intqueue.front() != NULL) {
				int temp = intqueue.front();
				intqueue.pop();
				Node* tempnode = new Node(temp);
				curr->child.push_back(tempnode);
				treenodequeue.push(tempnode);
				if(intqueue.empty())break;
			}
		}
		return root;
	}
	int getTreeSize(Node* root) {
		if (root == nullptr)
			return 0;
		int totalcount = 1;
		queue<Node*> nodequeue;
		nodequeue.push(root);
		while (!nodequeue.empty()) {
			Node* curr = nodequeue.front();
			nodequeue.pop();
			if (curr->child.size() != 0) {
				totalcount += curr->child.size();
				for (int i = curr->child.size() - 1;i >= 0;--i)
					nodequeue.push(curr->child[i]);
			}
		}
		return totalcount;
	}
	void printTree(Node* root) {
		if (root == nullptr)
			return;
		queue<Node*> treenodequeue;
		int size = getTreeSize(root);
		treenodequeue.push(root);
		cout << "I am root , my value is " << root->val << "\n";
		--size;
		while (size != 0) {
			int index = 1;
			Node* curr = treenodequeue.front();
			treenodequeue.pop();
			for (int i = 0; i <curr->child.size(); ++i) {
				cout << "I am " << index << "th child of: " << curr->val << " , my value is " << curr->child[i]->val << "\n" ;
				--size;
				++index;
				treenodequeue.push(curr->child[i]);
			}
		}
	}
	vector<int> preorder(Node* root) {
		vector<int> res;
		if (root == nullptr)
			return res;
		stack<Node*> stk;
		stk.push(root);
		while (!stk.empty()) {
			Node* curr = stk.top();
			stk.pop();
			res.push_back(curr->val);
			for (int i = curr->child.size() - 1;i >= 0;--i)
				if (curr->child[i] != nullptr)
					stk.push(curr->child[i]);
		}
		return res;
	}
};

int main() {
	N_ary_Tree_Preorder_Traversal c;
	vector<int> nodes = { 1,NULL,2,3,4,5,NULL,NULL,6,7,NULL,8,NULL,9,10,NULL,NULL,11,NULL,12,NULL,13,NULL,NULL,14 };
	Node* root = c.BuildTree(nodes);
	c.printTree(root);
	cout << "The  preorder traversal is :" ;
	vector<int> res=c.preorder(root);
	for(auto i=res.begin();i!=res.end();++i)
	cout<< *i << " ";
	return 0;
}



/* recursive solution
class Solution {
public:
    vector<int> res;
    vector<int> preorder(Node* root) {
        if(!root)return res;
        res.push_back(root->val);
        vector<Node*> children=root->children;
        for(int i=0;i<children.size();++i){
            preorder(children[i]);
        }
        return res;
    }
};
*/ 
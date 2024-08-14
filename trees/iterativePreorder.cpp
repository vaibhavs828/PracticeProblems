#include<iostream>
#include<stack>
using namespace std;
struct Node{
	int data;
	struct Node *left, *right;
	Node(int val){
		data=val;
		left=right=NULL;
	}
};

void iterativePreorder(Node* root){
	if(root==NULL)
		return;
	stack<Node*> s;
	s.push(root);
	while(!s.empty()){
		int stackSize=s.size();
		for(int i=0;i<stackSize;i++){
			Node* node = s.top();
			s.pop();
			cout<<node->data<<" ";
			if(node->right!=NULL){
				s.push(node->right);
			}
			if(node->left!=NULL){
				s.push(node->left);
			}
		}
	}
}

int main(){
	struct Node* root = new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->right=new Node(7);
	iterativePreorder(root);
	return 0;
}
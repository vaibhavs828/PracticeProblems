#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int val){
    	data=val;
    	left=right=NULL;
	}
};

void LevelOrder(Node* root) {
    if (root == NULL) return;
    
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size(); // Number of nodes at the current level

        // Traverse all nodes at the current level
        for (int i = 0; i < levelSize; i++) {
            Node* node = q.front();
            q.pop();
            cout << node->data << " ";

            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
        }
        
        // Print a newline after each level
        cout << endl;
    }
}

int main() {
    struct Node* root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->right=new Node(7);
	LevelOrder(root);
    return 0;
}

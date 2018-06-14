/*
TREE: A simple daa structure 
 - Average running time of most operations is O(log N)
 - Tree is a collection of nodes, with a distinguished node (root)
 - Terms: Child, parent, leaves (no children), siblings (same parent), Grandparent, grandchild
 - Terms: path, length, depth (length of the unique path from the root to node), height (length of longest path to a leaf)
 - Terms: ancestor, descendent, proper ancestor, proper descendent
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;


class TreeNode{
public:




};

// Every node has either 0,1 or 2 children
class BinTreeNode {
public:
	int data;
	BinTreeNode* left;
	BinTreeNode* right;

	/* Constructor */
	BinTreeNode(int d) {
		data = d;
		left = right = NULL;
	}
};

class Solution {
public:
	// Iterative solution for inorder traversal which is left root right
	vector<int> inorderTraversal(BinTreeNode* root) {
		vector<int> result;
		stack<BinTreeNode*> mystack;
		BinTreeNode* curr = root;

		while (curr != NULL || !mystack.empty()) {
			while (curr != NULL) {
				mystack.push(curr);
				curr = curr->left;
			}
			curr = mystack.top();
			mystack.pop();

			result.push_back(curr->data);
			curr = curr->right;
		}
		return result;
	}

	// Iterative solution for Preorder traversal
	vector<int> preorderTraversal(BinTreeNode* root) {
		vector<int> result;
		stack<BinTreeNode*> mystack;
		BinTreeNode* curr = root;
		while (curr != NULL || !mystack.empty()) {
			while (curr != NULL) {
				mystack.push(curr);
				result.push_back(curr->data);
				curr = curr->left;
			}
			curr = mystack.top();
			mystack.pop();
			curr = curr->right;
		}
		return result;
	}
};

int main() {

	BinTreeNode* root = new BinTreeNode(1);

	cout << root->data;
	return 0;
}




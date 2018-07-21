#include<iostream>
#include<stack>
#include<queue>
#include<string.h>
using namespace std;

class TreeNode {
public: 
	int val;
	TreeNode* left = NULL;
	TreeNode* right = NULL;

	TreeNode(int v) {
		(*this).val = v;
	}
	
	
	void levelOrderTraversal() {
		TreeNode* root = this;
		if (root == NULL) return;
		queue<TreeNode*> levelNodes;
		levelNodes.push(root);
	
		while (!levelNodes.empty()) {
			TreeNode* cur = levelNodes.front();
			cout << (char)cur->val << " ";
			if (cur->left != NULL) levelNodes.push(cur->left);
			if (cur->right != NULL) levelNodes.push(cur->right);
			levelNodes.pop();
		
		}
	}

};
int main () {

	TreeNode* A = new TreeNode('A');
	TreeNode* B = new TreeNode('B');
	TreeNode* C = new TreeNode('C');
	TreeNode* D = new TreeNode('D');
	TreeNode* E = new TreeNode('E');
	TreeNode* F = new TreeNode('F');
	TreeNode* G = new TreeNode('G');
	TreeNode* H = new TreeNode('H');
	TreeNode* I = new TreeNode('I');
	TreeNode* J = new TreeNode('J');
	TreeNode* K = new TreeNode('K');

	B->left = A;
	B->right = C;

	D->left = B;
	D->right = E;

	F->left = D;
	F->right = J;

	J->left = G;
	J->right = K;

	I->left = H;
	G->right = I;

	F->levelOrderTraversal();

	return EXIT_SUCCESS;
}


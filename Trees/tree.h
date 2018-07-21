#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct treeNode {
	int val;
	struct treeNode* left;
	struct treeNode* right;
};

typedef struct treeNode tnode;
tnode* newTnode(int data);
void insert_into_BST(tnode** rootPtr, int data);
void printTree(tnode* root);
bool searchBST(tnode* root, int data);
int findMin_in_BST(tnode* root);
int findMax_in_BST(tnode* root);
int getHeight(tnode* root);
void Preorder(tnode* root);   // Depth first
void PostOrder(tnode* root);  // Depth first
void Inorder(tnode* root);	  // Depth first
void levelOrder(tnode* root); // Breadth first

tnode* newTnode(int data){
	
	tnode* node = (tnode*) malloc(sizeof(tnode));
	(*node).val = data;
	(*node).left = NULL;
	(*node).right = NULL;

}


void insert_into_BST(tnode** rootPtr, int data){
	
	if(*rootPtr == NULL){ 
		*rootPtr = newTnode(data);
		return;
	}	
	if(data <= (*rootPtr)->val){
		insert_into_BST(&(*rootPtr)->left, data);
		
	} else{
		
		insert_into_BST(&(*rootPtr)->right, data);
	}
	
	
}

bool searchBST(tnode* root, int data){
	if(root == NULL) return false;
	if(root->val == data) {
		return true;
	}
	else {
		if(data > root->val)
			return searchBST(root->right, data);
		else return searchBST(root->left, data);
	}
}

int findMin_in_BST(tnode* root){
	if(root == NULL) return -1;
	while(root->left != NULL){
		root = root->left;
	}
	return root->val;
}
int findMax_in_BST(tnode* root  ){
	
	if(root == NULL) return -1;
	else if(root->right == NULL){
		return root->val;
	}
	return findMax_in_BST(root->right);
	
}

/*Height of a binary tree:
Height of a tree is the height of root.
// HEIGHT OF A NODE is the number of edges in longest 
path from the node to a leaf node.
- empty tree         = -1
- Height of tree with one node = 0 (root node is a leaf node) 
Depth of a tree is the number of edges on path from root to that node.
				1        root  (height: 3, depth: 0)
			   / \
			  2   3
			 / \  / \
			4   5 6  7
			   / \
			  8   9		leaf((height: 0, depth: 3))
			  
*/

int getHeight(tnode* root){
	
	if(root == NULL) { 
		printf("*\n");
		return -1;
	}
	int leftH = getHeight(root->left);
	int rightH = getHeight(root->right);
	
	return leftH > rightH ? leftH+1 : rightH+1;
}

/*
Tree traversals: Visiting each node of a tree eaxctly once.
- Breadth first traversal: Where you visit the node, then its children, then their grandchildren
(Also called level order traversal.)

- Depth first search: When you visit the node, its children and while you are at the child node, you visit the grandchildren too. So if you 
visit the left node of the tree, you will recursively visit all the children and their grandchildren of the LEFT child's subtree, and then proceed to right.

There are 6 ways you can do this, but according to convention you visit the left before the right, hence the conventions should be:
root D: Left  L: Right R - PreOrder
Left L: root  D: Right R - Inorder
Left L: Right R: root  D - PostOrder
Left L: Right R: root  D - PostOrder
*/

void Preorder(tnode* root){
	if(root==NULL) return;
	
	printf("%c ", root->val);
	
	Preorder(root->left);
	
	Preorder(root->right);
	
}

void Inorder(tnode* root){
	if(root==NULL) return;
	
	
	
	Inorder(root->left);
	printf("%c ", root->val);
	Inorder(root->right);
	
}

void PostOrder(tnode* root){
	if(root==NULL) return;
	PostOrder(root->left);
	
	PostOrder(root->right);
	printf("%c ", root->val);
	
}
	
void printTree(tnode* root){
	if(root == NULL) return;
	printf("%c ", root->val);
	printTree(root->left);
	printTree(root->right);
	
}
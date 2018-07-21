#include "tree.h"

int main(){
	
	tnode* root = newTnode('F');
	insert_into_BST(&root, 'D');
	insert_into_BST(&root, 'B');
	insert_into_BST(&root, 'E');
	insert_into_BST(&root, 'A');
	insert_into_BST(&root, 'C');
	
	insert_into_BST(&root, 'J');
	insert_into_BST(&root, 'G');
	insert_into_BST(&root, 'K');
	
	insert_into_BST(&root, 'I');
	insert_into_BST(&root, 'H');
	
	//printTree(root);
	
	//int x = 11;
	//if(searchBST(root, x) == true) printf("%d found\n",x);
	//else printf("%d not found\n",x);
	Preorder(root);
	printf("\n");
	
	Inorder(root);
	printf("\n");
	
	PostOrder(root);
	printf("\n");
	
	//printf("Height: %d\n",getHeight(root));
	return 0;
}
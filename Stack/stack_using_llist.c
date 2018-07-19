/* Implementation of a stack using Linked List */
#include "list.h"

lnode* top = NULL;
void push(int x);
int getTop();
bool isEmpty();

// Insertion O(1)
void push(int x){
	struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = top;
	top = temp;
}

void pop(){
	lnode* temp;
	if(top == NULL) return; // Stack empty
	temp = top;
	top = top->next;      //next in line is new top
	free(temp);
}

int getTop(){
	if(isEmpty()== false) return (*top).data;
	else return -1;
}

bool isEmpty(){
	return top == NULL ? true : false;
}
int main(){
	push(4);
	push(5);
	push(6);
	
	printlist(top);
	int t = getTop();
	printf("Current Top: %d\n",t);
	
	pop();
	printlist(top);
	t = getTop();
	printf("Current Top: %d\n",t);
	return 0;
}



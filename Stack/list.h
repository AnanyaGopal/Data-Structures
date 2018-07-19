#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
	int data;
	struct Node* next;
	
};
typedef struct Node lnode;

void printlist(struct Node* head);
struct Node* newNode(int data);
void populateList(struct Node* head, int n);
void  reverse_list_poin(struct Node** ptrHead);
struct Node*  reverse_list(struct Node* head);
struct Node* addHead(struct Node* head, int n);
void insert_nth(struct Node* head, int data, int n);
lnode* delete_nth(lnode* head, int n);
void print_recurse(struct Node* head);
lnode*  reverse_recurse(lnode* head);
lnode* removeDuplicates(lnode* head);
void removeDuplicates_unsortedList(lnode* head);


/*
	Utility function to create a new node
	Param: int data, returns new node;
*/
struct Node* newNode(int data){
	struct Node* node = (struct Node*)	malloc(sizeof(struct Node));
	node->data = data;
	node->next = NULL;
	return node;
}
/*
	Utility function to print a list.
	Param: Head node 
*/
void printlist(struct Node* head){
	struct Node* t = head;
	while(t != NULL){
		printf("%d ", (*t).data);
		t = (*t).next;
	}
	printf("\n");
	
}
/*
	Utility function to generate a list.
	Param: Head node, int number of nodes that need to be added // node data populateList ascending // returns nothing 
*/
void populateList(struct Node* head, int n){
	struct Node* t = head;
	int i = 2;
	if(t == NULL) t = newNode(1);
	while(n-- != 0){
		t->next = newNode(i);
		i++;
		t = t->next;
	}
}
/*
	Function to reverse iteratively () 
	Param: Head node, int data to be inserted, int position to be inserted at; returns nothing 
*/ 
void  reverse_list_poin(struct Node** ptrHead){
	
	if(*ptrHead == NULL || (**ptrHead).next == NULL) return ; 
	
	struct Node* curr = *ptrHead;
	struct Node* prev = NULL;
	struct Node* next = NULL;
	
	while(curr != NULL){
		next = (*curr).next;
		(*curr).next = prev;
		prev = curr; 
		curr = next;
		//printf("%d %d %d \n",(*prev).data, (*curr).data, (*next).data);
	}
	
	*ptrHead = prev;
}
/*
	Function to add a node at the head into a linked list;
	Param: Head node, int data to be inserted ; returns new head.
*/
struct Node* addHead(struct Node* head, int n){
	struct Node* newHead = (struct Node*)malloc(sizeof(struct Node));
	newHead->data = n;
	newHead->next = head;
	return newHead;
}

/*
	Function to reverse a linked list iteratively. (3 pointer method)
	Param: Head node, int data to be inserted, int position to be inserted at; returns nothing 
*/ 
struct Node*  reverse_list(struct Node* head){
	if(head == NULL || (*head).next == NULL) return ; 
	
	struct Node* curr = head;
	struct Node* prev = NULL;
	struct Node* next = NULL;
	
	while(curr != NULL){
		next = (*curr).next;
		(*curr).next = prev;
		prev = curr; 
		curr = next;
		//printf("%d %d %d \n",(*prev).data, (*curr).data, (*next).data);
	}
	
	return prev;
}
/*
	Function to insert a node at nth index (1-indexed) into a linked list. 
	Param: Head node, int data to be inserted, int position to be inserted at; returns nothing 
*/
void insert_nth(struct Node* head, int data, int n){
	
	if(head == NULL || n < 0) return;
	struct Node* node = (struct Node*) malloc(sizeof(struct Node));
	node->data = data;
	
	if(n==1){
		node->next = head;
		head = node;
		return;
	}
	
	struct Node* temp = head;
	int i;
	for(i = 0 ; i < n-2; i++){
		temp = temp->next;
		if(temp == NULL) return;
	}
	
	if(temp != NULL && node != NULL){
		node->next = temp->next;
		temp->next = node;
	}	
}

/*
	Function to delete a node at nth position (1 - len of list) of a linked list. 
	Param: Head node, index at which node to be deleted;  returns nothing 
	// To delete a node -> we need to do 2 steps:
	// 1) Fix links.
	// 2) Free the soace taken by the node.
	
*/
lnode* delete_nth(lnode* head, int n){
	if(n <= 0 || head == NULL) return;
	// Assuming n is valid -> what happens if we delete 1st node (head).
	lnode* temp = head;
	if(n==1){
		head = temp->next;
		free(temp);
	}
	else{
	int i;
	printf("node: %d\n", temp->data);
	
	for(i = 0; i<n-2; i++){
		temp = temp->next;
		printf("going through node: %d\n", temp->data);
	}
	
	// 1 2 3 4 5 6
	lnode* temp2 = temp->next;
	printf("to be del: %d\n", temp2->data);
	temp->next = temp2->next;
	
	free(temp2);
	}
	return head;
}
/*
	Function to print the nodes' data of a linked list recursively. 
	Param: Head node, returns nothing 
*/
void print_recurse(struct Node* head){
	if(head == NULL){
		printf("NULL\n");
		return;
	} 
	printf("%d->", head->data);
	print_recurse(head->next);
}
/*
	Function to print the reverse of a linked list recursively. 
	Param: Head node, returns nothing 
*/
void print_recurse_reverse(struct Node* head){
	if(head == NULL){
		return;
	} 
	print_recurse_reverse(head->next);
	printf("%d ", head->data);
}

/*
	Function to reverse a linked list recursively. 
	Param: Head node, returns new head node;
*/
lnode* reverse_recurse(lnode* p){
	lnode* q;
	printf("%d ", p->data);
	if(p == NULL || p->next == NULL) return p;
	q = reverse_recurse(p->next);
	p->next->next = p;
	p->next = NULL;
	return q;
}
/*
	Function to find the middle of a linked list
	Param: Head node, return mid node.
*/
lnode* findMid(lnode* head){
	if(head== NULL) return head;
	
	lnode* slowPtr = head;
	lnode* fastPtr = head;
	
	while(fastPtr->next != NULL && fastPtr->next->next != NULL){
		//if((*slowPtr).data == (*fastPtr).data) 
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;
	}
	return slowPtr;
}

/*
	Function to remove nodes from a sorted linked list
	Param: Head node, return the same head node pointing to list without duplicates.
	
	Copy the following code to test:
	lnode* test = newNode(1);
	test->next = newNode(1);
	test->next->next = newNode(3);
	test->next->next->next = newNode(3);
	test->next->next->next->next = newNode(3);
	test->next->next->next->next->next = newNode(3);
	
	printlist(test);
	test = removeDuplicates(test);
	printlist(test);
	
*/
lnode* removeDuplicates(lnode* head){
	if(head == NULL) return;
	
	lnode* t = head;
	
	while(t != NULL && t->next != NULL){
		if((*t->next).data == (*t).data){
			lnode* q = t->next;
			t->next = q->next;
			free(q);
			
		}
		
		else{
			t = t->next;
		}
		
	}
	
	return head;
}
/*
	Function to remove nodes from an unsorted linked list
	Param: Head node, return the same head node pointing to list without duplicates.
	
	Copy the following code to test:
	lnode* test = newNode(1);
	test->next = newNode(4);
	test->next->next = newNode(3);
	test->next->next->next = newNode(4);
	test->next->next->next->next = newNode(3);
	test->next->next->next->next->next = newNode(1);
	
	printlist(test);
	test = removeDuplicates(test);
	printlist(test);
	
*/
void removeDuplicates_unsortedList(lnode* head){
	
	lnode* mainPtr;
	lnode* rollPtr;
	lnode* dup;
	mainPtr = head;
	
	while(mainPtr != NULL && mainPtr->next != NULL){
		rollPtr = mainPtr;
		
		while(rollPtr ->next != NULL){
			if(mainPtr->data == rollPtr->next->data){
				dup = rollPtr->next;
				mainPtr->next = dup->next;
				free(dup);
			}
			else{
				rollPtr = rollPtr->next;
			}		
			
				
		}
		mainPtr = mainPtr->next;
		
	}

}
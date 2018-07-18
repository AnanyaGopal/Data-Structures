#include<stdio.h>
#include<stdlib.h>

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
void print_recurse_reverse(struct Node* head);


struct Node* newNode(int data){
	struct Node* node = (struct Node*)	malloc(sizeof(struct Node));
	node->data = data;
	node->next = NULL;
	return node;
}

void printlist(struct Node* head){
	struct Node* t = head;
	while(t != NULL){
		printf("%d ", (*t).data);
		t = (*t).next;
	}
	printf("\n");
	
}
void populateList(struct Node* head, int n){
	struct Node* t = head;
	int i = 2;
	while(n-- != 0){
		t->next = newNode(i);
		i++;
		t = t->next;
	}
}

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
		printf("%d %d %d \n",(*prev).data, (*curr).data, (*next).data);
	}
	
	
}

struct Node* addHead(struct Node* head, int n){
	struct Node* newHead = (struct Node*)malloc(sizeof(struct Node));
	newHead->data = n;
	newHead->next = head;
	return newHead;
}
   
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

lnode* delete_nth(lnode* head, int n){
// To delete a node -> we need to do 2 steps:
// 1) Fix links.
// 2) Free the soace taken by the node.
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

void print_recurse(struct Node* head){
	if(head == NULL){
		printf("NULL\n");
		return;
	} 
	printf("%d->", head->data);
	print_recurse(head->next);
}

void print_recurse_reverse(struct Node* head){
	
	if(head == NULL){
		return;
	} 
	print_recurse_reverse(head->next);
	printf("%d ", head->data);
	
	
}


int main(){
	
	//struct Node* head = addHead(NULL,0);
	struct Node* head = newNode(1);
	populateList(head, 9);
	printlist(head); 
	head = reverse_list(head);
	
	printlist(head);
	head = addHead(head, 5);
		
	insert_nth(head, 34, 4);
	
	printlist(head);
	//head = delete_nth(head, 1);
	head = delete_nth(head, 6);
	print_recurse(head);
	
	print_recurse_reverse(head);
	return 0;
}

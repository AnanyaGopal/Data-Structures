#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAXSIZE 10
int stack[MAXSIZE];
int top = -1;

void push(int x);
void pop();
int peek();
bool isEmpty();
void print();

void push(int x){
	if(top != MAXSIZE -1){
		stack[++top] = x;
	}
	else{
		printf("Stack full, cannot push %d\n", x);
	}
}

void pop(){
	if(!isEmpty()) top--;
	else printf("Nothing to pop");
}

int peek(){
	if(!isEmpty()) return stack[top];
}

bool isEmpty(){
	return top == -1 ? true : false;
}

void print(){
	int i;
	for(i = 0; i <= top; i++ )
		printf("%d ", *(stack + i));
	
	
	printf("\n");
}

int main(){
	
	push(20);
	push(18);
	push(17);
	push(17);
	push(20);
	push(20);
	push(20);
	push(14);
	push(14);
	push(14);
	push(14);
	pop();
	push(90);
	print();
	return 0;
}

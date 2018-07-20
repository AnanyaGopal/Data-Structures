#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define MAXSIZE 256
char char_stack[MAXSIZE];
int top = -1;

void push(char x);
void pop();
char peek();
bool isEmpty();
void print();

void push(char x){
	if(top != MAXSIZE -1){
		char_stack[++top] = x;
	}
	else{
		printf("Stack full, cannot push %d\n", x);
	}
}

void pop(){
	if(!isEmpty()) top--;
	else printf("Nothing to pop");
}

char peek(){
	if(!isEmpty()) return char_stack[top];
}

bool isEmpty(){
	return top == -1 ? true : false;
}

void print(){
	int i;
	for(i = 0; i <= top; i++ )
		printf("%c ", *(char_stack + i));
	
	
	printf("\n");
}
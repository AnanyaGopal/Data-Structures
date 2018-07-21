/*
 Abstract data type
 - List or collection with the restriction that:
	Insertion is performed at one end. (back)
	Deletion is performed at the other end. (front)
	
Operations: 
void Enqueue: 
int Dequeue: Removes element from front of queue
int front() or peek() gives you the front without removing it
isEmpty: If the queue is empty.

Example of practical application of a queue:
- A printer operating in a shared network.
* Multiple computers send print requests to printer
* Printer queues the requests, and processes them in order of receipt.
* First request received, first request processed.

Two implementations are discussed: 
* Array Implementation of Queue.
----- Circular implementation would result in saving space.
----- Current pos = i, Next position: (i+N)%N;
+++++ In Enqueue: if(rear+1)%N == front (return);
+++++ In Enqueue: rear is (rear+1)%N if queue is not empty.
----- In Dequeue: front is (front+1)%N if queue is not empty || front != rear.

* LinkedList Implentation of Queue
- Array implementation does have a lot of space wastage.

++ To add an element to the back of the queue (Enqueue) - Add element to the tail.
-- to dequeue, remove the head, and set head->next = head;
** To get the front: get the head value.
** to get the back:  get the tail value.
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


#define QUEUE_SIZE 10
int front = -1;
int rear = -1;
int queue[QUEUE_SIZE];

bool isEmpty();
bool isFull();
void enqueue(int x);
void dequeue();
void printqueue();	

/*Return true if queue is empty, false if it has elements*/ 
bool isEmpty(){
	return (front == -1 && rear == -1); 
	
}

/*Return true if queue is full, false if it has space to store more elements*/ 
bool isFull(){
	return (rear == QUEUE_SIZE+1); 
}

void enqueue(int x){
	if(isFull()==true) return;  //No space for x in current queue
	
	else if(isEmpty()==true){
		front++;
	}	
	
	rear++;
	queue[rear] = x;
	
}

void dequeue(){
	 if(isEmpty()==true) return;
	 
	 if(front == rear) 
	 {	
		front = -1;
		rear  = -1;
		return;
	 }
	 
	 front++;
		
	
}

void printqueue(){
	int i;
	for(i = front; i <= rear; i++){
		printf("%d ", *(queue +i));
		
		
	}
	printf("\n");
		
	
}

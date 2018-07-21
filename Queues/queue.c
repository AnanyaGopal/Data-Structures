#include "queue.h"

int main(){
	
	enqueue(2);
	enqueue(5);
	enqueue(7);
	
	printqueue(); //2 5 7
	dequeue();    
	printqueue(); // 5 7
	
	enqueue(3);   
	enqueue(1);
	enqueue(9);
	enqueue(10);
	enqueue(4);
	enqueue(6);
	enqueue(6);
	
	printqueue(); // 5 7 3 1 8 10 4 6 6 
	dequeue();    
	printqueue(); // 5 7 3 1 8 10 4 6 
 
	enqueue(2);	
	enqueue(6);
	printqueue(); // 5 7 3 1 8 10 4 6 2 

	return EXIT_SUCCESS;
}
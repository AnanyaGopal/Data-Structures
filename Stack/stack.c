#include "stack.h"

int EvaluatePostFix(char* exp);
bool isOperand(char c);

int EvaluatePostFix(char* exp){
	if(exp == NULL) return 0;
	
	int len  = strlen(exp);
	int i;
	for(i = 0; i<len ;i++){
		
		if(isOperand(exp[i]) == true){
			int a = peek();
			pop();
			int b = peek();
			pop();
			
			if(exp[i] == '*') push(a*b);
			if(exp[i] == '/') push(a/b);
			if(exp[i] == '+') push(a+b);
			if(exp[i] == '-') push(a-b);
			
			
		}
		
		else {
			int res = exp[i] - '0';
			push(res);
			
		}
		
		
	}
	
	
	
	return peek();
	
}

bool isOperand(char c){
	
	return (c == '*' || c == '/' || c == '-' || c == '+');
	
}

int main(){
	
	
	int x = EvaluatePostFix("23+");
	printf("%d\n", x);
	return 0;
}

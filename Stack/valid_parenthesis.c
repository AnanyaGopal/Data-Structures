#include "char_stack.h"
bool is_bracket(char c);
bool isValid(char* exp);


bool is_bracket(char c) {
	return (c == '{' || c == '}' || c == '[' || c == ']' || c == '(' || c == ')');
}

bool isValid(char* exp){
	
	int len = strlen(exp);
	//printf("%s %d\n", exp, len);
	int i;
	for (i = 0; i < len; i++) {
		if (is_bracket(exp[i])) {
			if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(')
				push(exp[i]);
			// opening paranthesis.
			else {
				if (isEmpty()) { return false; }
				char c = peek();
				if (((exp[i] == '}' && c == '{') || (exp[i] == ']' && c == '[') || (exp[i] == ')' && c == '('))) {
					pop();
				}
				else {
					//cout << "Invalid exp";
					return false;
				}
			}
		}
	}
	
	return isEmpty();
	
}
int main (){
	
	char *exp = "(";
	char *result;
	
	result = isValid(exp) ? "Valid" : "Invalid";
	
	printf("\"%s\" is %s\n",exp, result );
	
	return 0;
	
	
}


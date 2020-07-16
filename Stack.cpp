#include<iostream>
#include<string>
#include<fstream>
#include "Stack.h"

Stack::Stack(int stackSize) {	//constructor
	stackArray = new char[stackSize];
	stacksize = stackSize;
}


Stack::~Stack() {}			//destructor


bool Stack::isEmpty() {		//check for empty stack

	if (stackTop == -1)
		return 1;
	else
		return 0;
}


bool Stack::isFull() {		//check for full stack

	if (stackTop == stacksize - 1)
		return 1;
	else
		return 0;
}



void Stack::push(char value) {	//method to push value into stack

	if (Stack::isFull())
		std::cout << "stack overflow";
	else
		stackArray[++stackTop] = value;
}



char Stack::pop() {			//method to pop value from stack
	if (Stack::isEmpty()) {
		std::cout << "stack underflow";
		return 0;
	}
	else
		return stackArray[stackTop--];
}



char Stack::Top() {			//method for top value of stack
	if (Stack::isEmpty()) {
		std::cout << "stack underflow";
		return 0;
	}
	else
		return stackArray[stackTop];
}



int Stack::opPrecedence(char ch) {	  //operator precedence for postfix conversion

	if (ch == '^')
		return 3;
	else if (ch == '*' || ch == '/' || ch == '%')
		return 2;
	else if (ch == '+' || ch == '-')
		return 1;
	else
		return -1;
}



std::string Stack::infixToPostfix(char char_array[], int size)  //infix to postfix conversion
{
	std::ofstream out("maria.txt");		//open file to write

	for (int i = 0; i < size; i++) {

		if (isalpha(char_array[i]) || isdigit(char_array[i]))
			//if operand(alphabet or digit), ouput it
			out << char_array[i];



		else if (char_array[i] == '+' || char_array[i] == '-' || char_array[i] == '*' || char_array[i] == '/' || char_array[i] == '%' || char_array[i] == '^') {	 //if operator


			if (Stack::isEmpty()) {		//check for empty stack
				push(char_array[i]);	//if true, push value
			}




			else if (Stack::opPrecedence(Top()) >= Stack::opPrecedence(char_array[i])) { //operator precedence checks
				out << Stack::pop();
				Stack::push(char_array[i]);
			}



			else if (Stack::opPrecedence(Stack::Top()) < Stack::opPrecedence(char_array[i]))
				Stack::push(char_array[i]);
		}

		else if (char_array[i] == '(')			//checks for brackets
			Stack::push(char_array[i]);

		else if (char_array[i] == ')')
			do {
				if (Stack::Top() == '(')
					Stack::pop();
				else
					out << Stack::pop();

			} while (!Stack::isEmpty());
	}



	while (!Stack::isEmpty()		//pop remaining values
		) {
		out << Stack::pop();
	}
	out.close();			//close file
	return "s";				//return arbitrary string
}




int Stack::evaluatePostfix(std::string str) {

	int size = str.length();
	int result = 0;
	int x, y = 0;;

	for (int i = 0; i < size; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')

			Stack::push((int)str[i] - '0');

		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%') {

			x = Stack::pop();
			y = Stack::pop();

			switch (str[i]) {
			case '%':
				result = y % x;
				break;

			case '/':
				result = y / x;
				break;

			case '*':
				result = y * x;
				break;

			case '+':
				result = y + x;
				break;

			case '-':
				result = y - x;
				break;
			}
			Stack::push(result);
		}
	}
	return result;

}

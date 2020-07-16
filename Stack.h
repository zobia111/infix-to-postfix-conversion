#pragma once
class Stack
{
private:
	int stackTop = -1;
	char *stackArray;
	int stacksize;

public:
	Stack(int stackSize);
	~Stack();

	bool isEmpty();
	bool isFull();

	void push(char value);
	char pop();
	char Top();


	int opPrecedence(char ch);
	std::string infixToPostfix(char char_array[], int size);
	int evaluatePostfix(std::string);
};


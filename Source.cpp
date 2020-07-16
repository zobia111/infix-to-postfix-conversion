#include<iostream>
#include<fstream>
#include<string>
//#include<vld.h>
#include "Stack.h"
using namespace std;

int main() {

	cout << "--------------------------------------------------" << endl;
	cout << "--------------------------------------------------" << endl;
	cout << endl << endl;

	Stack s(40);

	std::string infix;
	ifstream f("zobia.txt");		//open file

	if (!f) {						//if file not opened
		cout << "error" << endl;
	}
	else {
		f >> infix;				//read infix
		cout << "	infix:  " << infix << endl;
	}

	int n = infix.length();
	char* char_array = new char[n + 1];		//string to char array conversion
	strcpy_s(char_array, n + 1, infix.c_str());

	s.infixToPostfix(char_array, n + 1);		//infix to postfix conversion

	cout << endl;

	f.close();		//close file

	std::string postfix;
	ifstream foo("maria.txt");		//open another file to read
	foo >> postfix;					//read
	cout << "	postfix:  " << postfix << endl;;
	cout << endl;


	cout << "	" << "postfix evaluation=  " << s.evaluatePostfix(postfix);		//evaluate postfix method
	cout << endl;

	cout << endl << endl;

	cout << "--------------------------------------------------" << endl;
	cout << "--------------------------------------------------" << endl;



	delete[] char_array;		//free memory

	system("pause");
	return 0;
}

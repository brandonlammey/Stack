/*
 * File Name: main.cpp
 * Author: Brandon Lammey 
 * Description: Main to call on test cases for a stack data structure. 
 */



#include<iostream>

// #include<stdexcept>
// #include<string>
// #include<fstream>

#include "Stack.h"
#include "PreconditionViolationException.h"

int main(int argc, char** argv)
{ 

	// string input = "";
	// std::string fileInput = argv[1];

	// std::ifstream readFile; 
	// readFile.open(fileInput);

	// readFile >> input; 

	std::string testString;
	std::cout << "Enter string: ";
	std::cin >> testString;

	Stack<string> testStack; //stack

	testStack.push(testString);
	std::cout << "Peek: " << testStack.peek() << '\n'; 
	testStack.pop();
	
	// while(!readFile.eof())
	// {
	// 	readFile >> input; //read in next command / name
	// }

	std::cout<< '\n';
	return(0); 
}

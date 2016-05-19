//header - must include in all files when using precompiled headers
#include "stdafx.h"	
//preprocessor directive - allows iostream library access / cmd
#include <iostream>	

void doPrint() { //void is the return type
	std::cout << "called doPrint" << std::endl;
}
int return5() {	// a function that returns the integer 5
	return 5;
}

//main function - must be included - execution starts here
int main() {	
	//std is the standard library called a namespace
	std::cout << "hello world!" << std::endl; //<< is an output operator - output statement
	int x;	//declaration statement
	x = 5;	//assignment statement
	int y = 6; //initialization statement

	//tells the compiler we are using cout from the std namespace
	//if this is inside a function, it applies only to that function
	using std::cout;
	//tells the compiler to use everything from the std namespace (can cause naming collisions)
	using namespace std;
	cout << "Enter a number: "; //you dont need std:: because it's defined above
	std::cin >> x;	//reads user input from the console
	cout << "you entered: " << x << std::endl << std::endl;

	//interrupts main and calls the doPrint function
	doPrint();
	std::cout << return5() << std::endl; //calling the return 5 function

	//if the program ran successfully it will return a 0
	return 0;
}
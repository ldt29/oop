#include <iostream>
#include "Example.h"

using namespace std;

	// (2)
int Example::count =1;
	

Example::Example(int data) {
	// (3)
	this->data = data;
	this->num = count;
	cout << "Example #"<< num <<" is created\n";
	count++;
}

void Example::getData() {
	// (4)
	cout << "The data of Example #"<< num << " is " << data <<endl; 
}

Example::~Example() {
	// (5)
	cout << "Example #" << num <<" is destroyed\n";
}
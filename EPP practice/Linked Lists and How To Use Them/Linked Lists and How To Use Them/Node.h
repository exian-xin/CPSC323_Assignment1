#pragma once

# include <iostream>
using namespace std;
/*A linked list is essentially a group of connected classes, these classe are what you make them to be
and can hold any data values you wish to put in them. This can include but is not limited to:
integers, doubles, other classes, chars and strings. For simplicity sake, this program, we will only be using
integers. In this program, we will also be learning how to initialize functions of a class outside of the header file.

Lets start by first creating the class called Node
*/

class Node
{
public :
	Node() {}; // Constructor
	~Node() {}; // Destructor

	int data;
	Node * nextPtr = NULL;

	void addToList(int num, Node*& head);
	void deleteFromList(int num, Node*& head);
	void displayList(Node* head);
	void sortList(Node *& head);

private:
	

};
//Once we created the class and the functions we are going to use, we will move on to the next portion in the Node.cpp File.



#include "Node.h" // We must make sure to include the Node.h file so we can define the functions

//Now to Define the functions from our class, we must first learn how to call them from the class
//The format will be ******      <Function type> <Name of class> :: <Name of function> (Parameters)       *******



//If if you follow this outline, you may treat the actual body of code within the function normally

void Node::addToList(int num, Node*& head)
{
	// this code will insure that no matter what, we will be able to add an object to the list
	if( head == NULL)
	{
		head = new Node;
		head->data = num;
	}
	else
	{
		Node * currentPtr = new Node;
		currentPtr->data = num;
		currentPtr->nextPtr = head;
		head = currentPtr;
	}
}
void Node::displayList(Node * head)
{ // simply iterates between every object in the list starting with the head and will display the data
	Node* currentPtr = head;
	while (currentPtr != NULL)
	{
		cout << currentPtr->data << " ";
		currentPtr = currentPtr->nextPtr;
	}

	cout << endl << "End of List" << endl;
}
void Node::deleteFromList(int num, Node*& head)
{ // similarly to displaying the list, except we will be using a previous pointer as a place holder incase we need to delete a value
	// if a value is found, then the current pointer will be "forced out" and then deleted
	//if the current pointer is the head, the head will first be redefined then deleted.

	Node * currentPtr = head;
	Node * previousPtr =  currentPtr;

	if(head == NULL)
	{
		cout << "List is empty" << endl;

	}
	else
	{
		while (currentPtr != NULL) // To make sure there are still objects in the list
		{
			if (currentPtr->data == num && currentPtr == head) // to check if values match and we are at the head
			{
				head = currentPtr->nextPtr;
				delete currentPtr;
				currentPtr = head;
			}
			else if (currentPtr->data == num && currentPtr != head) // check if values match but we are within the list
			{
				previousPtr->nextPtr = currentPtr->nextPtr;
				delete currentPtr;
				currentPtr = previousPtr;

			}
			else // if value does not match
			{
				previousPtr = currentPtr;
				currentPtr = currentPtr->nextPtr;
			}
		}
	
	}
}

void Node::sortList(Node*& head)
{
	// Sort the list similarly how we sorted arrays using bubble sort

	Node* currentPtr = head; // start at the head
	int count = 0;

	while (currentPtr != NULL) // test run to get the number of nodes in the list to use as count
	{
		count++;
		currentPtr = currentPtr->nextPtr;
	}
	currentPtr = head;
	
	for (int i = 0; i < count; i++) // exactly like bubble minus except for 1 thing
	{
		for (int j = 0; j < count -1; j++)
		{
			if (currentPtr->data > currentPtr->nextPtr->data)
			{
				int temp = currentPtr->nextPtr->data;
				currentPtr->nextPtr->data = currentPtr->data;
				currentPtr->data = temp;
				currentPtr = currentPtr->nextPtr; //<------------ ***** you must make sure the current pointer is moving after EVERY ITERATION!!!*****
			}
			else
			{
				currentPtr = currentPtr->nextPtr;
			}
		}

		currentPtr = head; // at the end of second loop, currentPtr starts at head again and the first loop starts over.
	}

}
////////Once you have looked through all of this, you can go back to the main program and continue where you left off. 
#include "Node.h"
#include "stdafx.h"

void Node::insertNode(int num)
{
	
	if (head == NULL)
	{
		head = new Node;
		head->data = num;
	}
	else if (head != NULL)
	{
	Node * currentptr;
	currentptr = new Node;
	currentptr->nextptr = head;
	head = currentptr;
	currentptr->data = num;
	}
};
void Node::deleteNode(int num)
{
	
	if (head = NULL)
	{
		std::cout << "List is empty!\n";
	}
	else if (head != NULL)
	{
		Node * currentptr = head;
		Node * previousptr;
		while (currentptr->nextptr != NULL)
		{
			if (currentptr->data == num)
			{
				if (currentptr == head)
				{
					head = currentptr->nextptr;
					delete currentptr;
					currentptr = head;
					cout << "Number successfully deleted!\n";

				}
				else
				{
					previousptr->nextptr = currentptr->nextptr;
					delete currentptr;
					currentptr = previousptr;
					cout << "Number successfully deleted!\n";

				}
			}
			else if (currentptr->data !=  num)
			{
				previousptr = currentptr;
				currentptr = currentptr->nextptr;
			}
			else if (currentptr->data != num && currentptr->nextptr == NULL)
			{
				cout << "Number not found in list!" << endl;
			}
		}
	}
};
#include <iostream>
#include "Node.h"
using namespace std;

/*In this program we will be creating a linked list. We will be creating a switch in order to control what we (the user) want to do.

*****WARNING**********
The coming up segment looks very intimidating!!!! Read everything line by line and very carefully to be able to understand! 
RECOMENDED: DRAW IT OUT TO BETTER GRASP WHAT IS HAPPENING!!!
**********************

at this point, please look to the header File called "Node.h"

*/


//------->>>>>>>>>>>>>> start here after looking at "Node.cpp" <<<<<<<<<<<<<----------------


void DisplayMenu() // simple menu to let user get an idea of what they can do
{
	cout << "Please Make a selection from the menu: " << endl;
	cout << "a.) Add Number to the list" << endl;
	cout << "b.) Delete Number from the list" << endl;
	cout << "c.) Display List" << endl;
	cout << "d.) Sort List" << endl;
	cout << "q.) Quit" << endl << endl;

	cout << "choice: ";

}

int main()
{
	Node* head = NULL;
	Node node;
	char choice;

	do {
		
		DisplayMenu();

		cin >> choice;

		switch (choice)
		{
		case 'a': 
			{ 
			cout << "Input an integer to put in the list: ";
			int num;
			cin >> num;
			node.addToList(num, head);
			node.displayList(head);
			cout << endl;
			break;
			}
		case 'b':
		{
			cout << "Input an integer that you would like to delete from the list: ";
			int num;
			cin >> num;
			node.deleteFromList(num, head);
			node.displayList(head);
			cout << endl;
			break;
		}
		case 'c':
		{
			cout << "Here is the list currently:" << endl;
			node.displayList(head);
			cout << endl;
			break;

		}
		case 'd': 
		{
			cout << "The list is now sorted: " << endl;
			node.sortList(head);
			node.displayList(head);
			cout << endl;
			break;
		}
		case 'q': 
		{
			cout << "Thank you for using this program!" << endl << endl;
			break;
		}
		default: cout << "Please enter a valid selection!" << endl << endl;

		}


	} while (choice != 'q');

	system("pause");
	return 0;
}


//		Once you have completed this, use the information you learned here to create the following program:
//
//	Create a program that will create a linked list that takes the First name and birthday of individual,
//	and add them to a linked list. The program must all for the following features:
//		a.) Must be able to add a first name and birthday to linked list
//		b.) Must be able to delete a node based off name inputted by the user
//		c.) Must be able to sort the users in the list from youngest to oldest and display them (only names)
//		d.) Must be able to display all names with the birthdays in the list. ( Name: Sami  Birthday: 8/13/1994)
//		q.) quit the program

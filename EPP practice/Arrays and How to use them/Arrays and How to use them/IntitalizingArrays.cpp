#include <iostream>
using namespace std;


/*In this section of the program, we will look over how to set up an Array, and create a simple program to intialize each element of the array.*/

int main()
{
	//*there are 2 main ways to intitialize and array: Either through manual input or user input

	int a[5] = { 0, 1, 2 ,3 , 4, }; // This is an example of initializing the program manually within the code

	// To have the user input their own values, you must follow this structure:

	int b[5]; // Initialize an array but dont enter values

	//The most efficient way at this point is to create a for-loop with the number of values you would like to put into the array, in this case 5;

	for (int i = 0; i < 5; i++)
	{
		cout << "Please Enter a value at element " << i << ":";
		cin >> b[i];
	}

	//To display the array, you similarly use a for loop, but instead "cout" the values of each element."

	cout << "Here is Array 'a': " << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl << "Here is Array 'b': " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << b[i] << " ";
	}
	cout << endl << endl;

	/*Now on your own, create a program that will ask the user to input 10 values into an array.
	The program will then display all the values in reverse order:
	example:
	
			User inputs: 10 9 8 7 6 5 4 3 2 1
		The program will display 1 2 3 4 5 6 7 8 9 10
		
	*/
	return 0;

}
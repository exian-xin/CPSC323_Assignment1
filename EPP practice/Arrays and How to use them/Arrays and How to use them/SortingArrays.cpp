#include <iostream>
using namespace std;

/*Next we will cover sorting arrays. This is useful in a couple of situations, for example:
getting the minimum or maximum values in an array or organizing an array by numerical value.*/

int main()
{
//First we will start by creating an array with random values.
	int a[5] = { 2, 5, 1, 10, 3 };
	
	//In order to sort this, we will have to use a combination of nester for-loops and if statements

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5 - 1; j++) //We use "5-1" because once we reach the last element in the array, there would be nothing to compare it to, so 
			// we only look at the 2nd to last values and compare it to that
		{
			if (a[j] > a[j + 1]) // if the current value is greater than the next value then we will continue to the switch
			{
				int temp = a[j + 1]; // this will hold the value we are switching
				a[j + 1] = a[j]; // the value is then exchanged with the previous, higher value
				a[j] = temp; // the previous value is intitalized to the temp variable where we held the smaller value.
			}
		}
	}
	cout << "Array has been organized from least to greatest:" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl << endl;

	/*Now that we went over sorting arrays, create a program that has the user input 5 values and sort them FROM LARGEST TO SMALLEST
	example:
			User Input: 2 8 10 3 5
			Output: 10 8 5 3 2
			
	*/

	return 0;
}
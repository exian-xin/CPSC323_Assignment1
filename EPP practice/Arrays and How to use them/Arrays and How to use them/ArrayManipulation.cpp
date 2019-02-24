#include <iostream>
using namespace std;


/*Since we learned how to initialize arrays, now lets use the values inside them!

In this program we will cover how to use an array to get a running total of values in an array*/

int main()
{
	//Assume we have an array that has initialized values, This array will be array 'a';
	int a[5] = { 1, 2, 3, 4, 5 };

	//We can take the running total of an array by using a for-loop, similarly how did in the previous problem.
	//but we must first intialize a value to hold the sum of the values

	int sum = 0; //We initialize it to 0 since it is empty until we add numbers to it.

	for (int i = 0; i < 5; i++)
	{
		sum = sum + a[i];
		// this will insure to add the current value to the current sum and replace the value in the sum as well
	}
	cout << "The sum of Array 'a' is " << sum << endl;

	// similarly, we can use this same concept for subraction, multiplication, divison, and other mathematical operations.
	// with multiplaction it would be a little different though since you cant divide by or multiply by zero, so we can start the loop
	// with and if statement checking if it is the first iteration of the array and intilaize the product to that.
	int product;
	for (int i = 0; i < 5; i++)
	{
		if (i == 0)
		{
			product = a[i];
		}
		else
		{
			product = product * a[i];
		}
		
		
	}
	cout << "Here is the product of all values in Array 'a': " << product << endl << endl;

	/*Now that we've covered basic operations, Create a program that will take the Grades ( double data-type ) of 5 students 
	and return the average score.
	example:
			User Inputs: 90 75 80 80 68
			The average score of the students was: 78.6
			
	*/

	return 0;

}
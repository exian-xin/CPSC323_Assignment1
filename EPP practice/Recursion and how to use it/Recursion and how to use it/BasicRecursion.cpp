#include <iostream>
using namespace std;



/*As you probably already know, recursion is just an old fashioned way of doing all the loops we already know.
the only thing about it that is truly different is the use of a base case. Since we arent aloud to use normal looping
functions, we must use a combination of recalling the function and if statement to accomplish what we need.*/

// Here we will make a simple recursion function that will return the factorial of a number

int Factorial(int num)
{
	if (num == 0) // Zero being the base case
	{
		return 1; // return 1 becuase 1 * num  =  num
	}
	else
	{
		return num * Factorial(num - 1); // this is the same as  num  * num-1 * num-2 * ... * 1
	}
}
// all principles of recursion will follow this idea of looking for the base case and working your way out from there.
int main()
{
	cout << "Please enter a number you would like to get the factorial of: ";
	int num;
	cin >> num;

	int factorial;
	factorial = Factorial(num);
	cout << "The Factorial of " << num << " is " << factorial << endl;




	system("pause");
	return 0;
}

//Im too tired to think of difficult recursion problems right now! We can discuss them later!
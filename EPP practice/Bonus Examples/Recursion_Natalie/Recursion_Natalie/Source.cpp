#include <iostream>
using namespace std;


int Factorial(int num);


int main()
{
	int num;
	int factorial;
	cout << "Please an input you would like to get the factorial for: ";
	
	cin >> num;

	factorial = Factorial(num);

	cout << "Here is the Factorial: " << factorial << endl;


	system("pause");
	return 0;
}


int Factorial(int num)
{
	int total;
	if (num > 0) //Loop
	{
		total = Factorial(num - 1) * num;
		return total;
	}
	return 1; // base case

	
	
}
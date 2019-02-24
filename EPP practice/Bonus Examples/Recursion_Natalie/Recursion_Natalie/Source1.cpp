#include <iostream>
using namespace std;

void displayArr(int arr[], int);

int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };

	cout << "Here are all the values in the array: ";

	displayArr(arr, 10);

	cout << endl << endl;
	system("pause");
	return 0;
}

void displayArr(int arr[], int num)
{
	
	if (num > 0)
	{
		num--;
		cout << arr[num] << " ";
		displayArr(arr, num);
	}
}
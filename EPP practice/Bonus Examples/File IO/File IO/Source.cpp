#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

	string name;
	string temp;

	cout << "Please enter your name: ";
	getline(cin, name);

	ofstream fileI("Text.txt");

	if (fileI.is_open())
	{
		fileI << name;
		fileI.close();
	}

	cout << "Here is the name on File: " << endl;

	ifstream fileO("Text.txt");

	if (fileO.is_open())
	{
		getline(fileO, temp);

		fileO.close();
		cout << temp << endl;
	}

	system("pause");
	return 0;

}
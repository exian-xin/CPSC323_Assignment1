#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{


	ofstream myFile;

	myFile.open("Text.txt");

	int num1[5] = { 0,1,2,3,4 };

	for (int i = 0; i < 5; i++)
	{
		myFile << num1[i] << endl;

	}

	myFile.close();

	ifstream inFile;
	string line;
	inFile.open("Text.txt");

	for (int i = 0; i < 5; i++)
	{
		getline(inFile, line);
		cout << line << endl;

	}
	inFile.close();
	

	fstream file("Text1.dat", ios::binary | ios::in | ios::out);

	for (int i = 0; i < 5; i++)
	{
		file.write((char*)&num1[i], sizeof(num1[i]));

	}
	file.close();
	file.open("Text1.dat");

	for (int i = 4; i>=0; i--)
	{
		file.read((char*)&num1[i], sizeof(num1[i]));
	}
	file.close();
	for (int i = 0; i < 5; i++)
	{
		cout << num1[i] << endl;
	}

	system("pause");

	return 0;





}
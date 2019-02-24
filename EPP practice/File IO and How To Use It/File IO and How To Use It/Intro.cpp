#include <iostream>
using namespace std;

/*File input and output are very useful tools when you are working with data that you would like to hold on to.
Both of them follow 5 basic steps in order to *read* or *write to/from a file. These basic steps include:
	1.)Includeing the fstream library
	2.)Creating the Object
	3.)Opening the File
	4.)Reading/Writing to the file
	5.)Closing the File
	
In this portion, we will be focusing on Basic reading and writing to files using arrays. You may also use any data
type and arent limited to integers, but for the simplicity of this program, we are going to be using that. Reading and Writing strings
and other data types are very similar to integers or other numerical values because of the way the fstream class grabs the item from the file.

*/

#include <fstream>					// Step 1-> Include fstream library

//We will be writing to file, so we will need to be using *ofstream* in this case

int main()
{
	int num[5] = {1, 2, 3, 4, 5};
	ofstream outFile("Text.txt");	//Step 2-> Create object called outFile with the text file as the paramter
									//this will also allow us to open it later.
	if (outFile.is_open())			//Step 3-> Open the File
	{
		for (int i = 0; i < 5; i++)
		{
			outFile << num[i] << " "; //Step 4 -> write to file **Note: OutFile Works similarly to cout, except instead of displaying
															// on the the screen, it will display it on the file!**
		}
	}
	outFile.close(); //Step 5-> Close the file

	//Now you should have successfully written to a file using this basic ofstream structure.
	//Run This program, To see if it worked!

	//Next we Will cover reading from the file. The structure is roughly 80% identical
	// but we will be using ifstream instead and we will be using inFile similarly to a cin

									//Step 1 was already covered when we created the program, so we will skip it.
	int data[5];
	ifstream inFile("Text.txt");	//Step 2-> Create an object called inFile with the text file as the paramter

	if (inFile.is_open())			//Step 3-> Open the File
	{
		for (int i = 0; i < 5; i++)
		{
			inFile >> data[i];		//Step 4-> Read from file **Note: "inFile >>" does not read spaces or escape keys, so this is good for reading 
																// one item at a time, and not an entire line at a time(we will cover that later)**
		}
	}
	inFile.close();					//Step 5-> Close File

	//To insure we have properly Read the items from the File, Lets run the program again, and use a for-loop to cout the array;

	for (int i = 0; i < 5; i++)
	{
		cout << data[i] << " ";
	}
	//If all worked out, it will display "1 2 3 4 5" in the command prompt
	cout << endl << endl;


	//This Concludes this portion of File IO, you now should have a basic understanding, Move on to Reading and writing lines

	system("pause");
	return 0;
}

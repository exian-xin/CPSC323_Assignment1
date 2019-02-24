#include <iostream>
using namespace std;
#include <fstream>
#include <string>

/*Since we covered the 5 basic steps in the previous .cpp, i will only go over them briefly. In this Portion we will be Covering Reading and writing lines
to and from a file. Keep in mind that a linked list is very useful when dealing with multiple data types patterns in a file

In this portion we will be using the Lines.txt instead of the Text.txt

Since we are also dealing with strings, be sure to include the string libary

*/

int main()
{

	string lineToFile = "This is a line";
	string lineToFile2 = "This is another line";

	//We will use the 5 steps of writing to a file almost identically as before in order to write this to the file.

	ofstream outFile("Lines.txt");
	if (outFile.is_open())
	{
		outFile << lineToFile << endl; // The endl is crucial in this segment because the outFile opperator will read it and start at the
										// next line for the second output.
		outFile << lineToFile2 << endl;
	}
	outFile.close();
	//Now that we Have written both of those lines to the file. lets run it and check if it worked.
	//Simple right? All File io follow the general basic structure as we covered before

	//Now this is when it gets a litte different, since we inputed a string, and ther are spaces within the string,
	// we must be sure to capture them, so we can't use out regular inFile. Instead we will be using getline!
	// Pay close attention to how to grab an entire line from the file.

	string lineFromFile;
	ifstream inFile("Lines.txt");
	if (inFile.is_open())
	{
		//we must insure to use a while loop to continue grabbing from the file until there is nothing left
		// the getline function uses this format *** getline(<name of ifstream object> , <name of variable that will hold the line>)
		//Dont stress out about the name of the variable you use
		//its essnetially a temp variable and will be useless after we are done displaying
		cout << "Here are the lines from the File: " << endl;
		while (getline(inFile, lineFromFile)) 
		{
			cout << lineFromFile << endl;
		}
		cout << endl << "End of File! " << endl;
	}

	// If all goes well, then your output should look like 
	/*
	
			Here are the lines from the File:
			This is a line
			this is another line

			End of File!
	
	If it looks like that, then you have succesfully read a line from the file!
	*/



	system("pause");
	return 0;
}
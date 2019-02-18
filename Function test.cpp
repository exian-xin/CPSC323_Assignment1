=#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <ctype.h>

using namespace std;

string KEYWORDS[20] = { "int", "float", "bool", "if", "else", "then",
						"do", "while", "whileend", "do", "doend",
						"for", "and", "or" , "function" };


char Ops_Seps_list[22] = { '*','+','-','=','/','>','<','%',							
							'\'','(',')','{','}','[',']',',','.',':',';','$','!',' '};


int testChar(char ch, int state)
{
	int currentState = state;
	int i = 0;

	if (currentState != 4)
	{
		for (i = 0; i < 8; i++)
		{
			if (ch == Ops_Seps_list[i])
			{
				currentState = 3;
				return currentState;
			}
		}
		for (i = 8; i < 22; i++)
		{
			if (ch == Ops_Seps_list[i])
			{
				if (ch == '!')
				{
					currentState = 4;
					return currentState;
				}
				currentState = 2;
				return currentState;
			}
		}
	}
	else
	{
		currentState = 4;
		return currentState;
	}
	currentState = 1;
	return currentState;

}
int testInput(char ch, string temp, int currentState);


int main()
{
	string input = "! Find largest value between two numbers!int num1, num2, large$ if (num1 > num2){ large = num1$;} else {large = num2$;}";
	string temp;
	bool comment = 0;
	char ch = input[0];
	char chType;
	int currentState = 0;
	int lengthofString = input.length();

	//for (int i = 0; i < lengthofString; i++)
	//{
	//	ch = input[i];
	//	currentState = testChar(ch, currentState);
	//	cout << currentState;
	//}
	//cout << endl << endl;

	for (int i = 0; i < lengthofString; i++)
	{
		ch = input[i];



		if (ch != '!' && currentState !=4)
		{
			currentState = testChar(ch, currentState);

			switch (currentState)
			{
			case 0 || 1:
				temp += ch;
				break;
			case 2: //  Seperator Detected
				//currentState = testInput(ch, temp, currentState);
				if ((currentState == 2) && temp != "")
				{

					cout << "String\t\t=\t" << temp << endl;
					cout << "Seperators\t=\t" << ch << endl;
					temp = "";

				}
				else if ((currentState == 2) && temp == "")
				{
					cout << "Seperators\t=\t" << ch << endl;
					temp = "";
				}
				break;
			case 3:
				//currentState = testInput(ch, temp, currentState);
				if ((currentState == 3) && temp != "")
				{

					cout << "String\t\t=\t" << temp << endl;
					cout << "Operators\t=\t" << ch << endl;
					temp = "";

				}
				else if ((currentState == 3) && temp == "")
				{

					cout << "Operators\t=\t" << ch << endl;
					temp = "";
				}
				break;
			case 4:
				//currentState = testInput(ch, temp, currentState);
				//currentState = 4;
				//if ((currentState == 4) && temp != "")
				//{

				//	//cout << "String\t\t=\t" << temp << endl;
				//	//cout << "Seperators\t=\t" << ch << endl;
				//	temp = "";

				//}
				//else if ((currentState == 4 ) && temp == "")
				//{
				//	//cout << "Seperators\t=\t" << ch << endl;
				//	temp = "";
				//}
				//else if (currentState == 4 && temp == "" && ch == ' ')
				//{
				//	//display nothing
				//}
				//else if (currentState == 4 && temp == "" && ch == '!')
				//{
				//	currentState = 0;
				//}
				break;
			}
		}
		else if (ch == '!' && currentState != 4)
		{
				currentState = 4;

		}
		else if (ch == '!' && currentState == 4)
		{
			currentState = 0;

		}

		/*if (currentState == 0 || currentState == 1)
		{
			temp += ch;
		}*/
		


	}
	cout << endl << endl;

	//for (int i = 0; i < lengthofString; i++)
	//{
	//	ch = input[i];



	//	currentState = testChar(ch, currentState);
	//	if (currentState == 0 || currentState == 1)
	//	{
	//		temp += ch;
	//	}
	//	else if (currentState == 2 && temp != "")
	//	{
	//		cout << "String = " << temp << endl;
	//		cout << "Sep/op = " << ch << endl;
	//		temp = "";

	//	}
	//	else if (currentState == 2 && temp == "")
	//	{
	//		cout << "Sep/op = " << ch << endl;
	//		temp = "";
	//	}


	//}

	cout << endl;
	system("pause");
	return 0;
}

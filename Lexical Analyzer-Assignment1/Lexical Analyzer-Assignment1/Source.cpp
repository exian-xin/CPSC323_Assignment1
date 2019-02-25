/*------------------
Name1: Sami Halwani
Name2: Ah-hyun Shin

Assignment1 : Lexical Analyzer

Date of Completion: 2/23/19

------------Project Description--------------
Create the beginnings of a compiler. This program must be
able to:
	-Identify Keywords, Integers, Floats, and Invalid Inputs
	-Skip Comment blocks defined as the area between two '!'
	-Skip white spaces

The Tokens Type and Lexemes must be displayed in a table.
*/

//---------------------Beginning of Program---------------
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>


using namespace std;


//List of Keywords Defined by language requirements
string KEYWORDS[20] = { "int", "float", "bool", "if", "else", "then",
						"do", "while", "whileend", "do", "doend",
						"for", "and", "or" , "function" };



//List of Operators and Separators Defined by Language requirments

char Ops_Seps_list[21] =
{
				'*','+','-','=','/','>','<','%',							//0-7 = Ops	
				'\'','(',')','{','}','[',']',',','.',':',';','!',' '//8-21 = Seps
};

//Finite State Machine Matrix
int FSM[6][7] = { 
				/*0*/	1,2,4,0,0,0,0,
				/*1*/	1,1,4,0,0,0,0,
				/*2*/	5,2,4,0,3,0,0,
				/*3*/	5,3,4,0,5,0,0,
				/*4*/	4,4,0,4,4,4,4,
				/*5*/	0,0,0,0,0,0,0
};


//Function Signatures -- Reference Discription Below main()
int testChar(char ch, int state);
void displayTemp(string temp);
void displayChar(char ch);

//------------------------main() Begin------------------
int main()
{
	string filename;
	string input = ""; //"! Find largest value between two numbers!int num1, num2, large$ if (num1 > num2){ large = num1$;} else {large = num2$;}"; //Test String
	string temp;
	char ch;
	int currentState = 0;
	int lengthofString = 0;

	//Input Variable for to pull information from file
	cout << "What is the file name?: ";
	cin >> filename;
	ifstream inFile(filename);

	//Open File
	if (!inFile.is_open()) {
		cout << "Cannot open file" << endl;
		return 1;
	}
	cout << endl << endl;

	cout << "Token\t\t\tLexeme" << endl << "------------------------------------" << endl;

	//Loop until there is no more available lines to read from the file.
	while (getline(inFile, input))
	{
		
		lengthofString = input.length(); // Get length of 'input'


		for (int i = 0; i < lengthofString; i++) //test character by character in the 'input'
		{
			ch = input[i];

			if (currentState != 4) //Comment Break if current state == 4
			{
				currentState = testChar(ch, currentState); //State Transition Call

				switch (currentState) 
				{
				case 0:					 //Once Seperator || Operator is entered. Display temp and ch
					displayTemp(temp);
					displayChar(ch);
					temp = "";
					break;

				case 1 || 2 || 3:		//Continue to Concatanate So long as valid input
					temp += ch;
					break;
				case 4:					//Display temp Immediately Before comment block
					displayTemp(temp);
					temp = "";
					break;
				case 5:					//Invalid Inputs, Display Invalid
					displayTemp(temp);
					displayChar(ch);
					temp = "";
					break;
				}

			}
			else if (ch == '!' && currentState == 4)	//Comment break if current state == 4
			{
				currentState = FSM[currentState][2];

			}


		}
		displayTemp(temp);						//Ignore and clear temp --  Start of new line
		temp = "";
	}
	inFile.close();	//Finished Reading File -> Close File


	cout << endl << endl;

	system("pause");
	return 0;
}
//-------------------------main() End---------------------


/*------------------testChar() Begin----------------------
This Function is designed to navigate through the State Transition table.
Given the specific character being currently read from the file, the state will
change according to the table. Table is initialized in global scope but can be
referenced as such:
				 char num  '!' sep '.' ops  '\n'
	new(0)			1,	2,	4,	0,	0,	0,  0
	string(1)		1,	1,	4,	0,	0,	0,  0
	int(2)			5,	2,	4,	0,	3,	0,  0
	float(3)		5,	3,	4,	0,	5,	0,  0
	comment(4)		4,	4,	0,	4,	4,	4,  4
	invalid(5)		0,	0,	0,	0,	0,	0   0
*/
int testChar(char ch, int state)
{
	int currentState = state;

	if (isalpha(ch))
	{
		currentState = FSM[currentState][0];
		return currentState;
	}
	else if (isdigit(ch) || ch == '$')
	{
		currentState = FSM[currentState][1];
		return currentState;
	}
	else if (ch == Ops_Seps_list[19]) //[20] == '!'
	{
		currentState = FSM[currentState][2];
		return currentState;
	}
	else if (ch == Ops_Seps_list[15]) // [16] == '.'
	{
		currentState = FSM[currentState][4];
		return currentState;
	}
	else if (isspace(ch))
	{
		currentState = FSM[currentState][6];
	}
	else
	{
		int i = 0;
		for (i = 0; i < 8; i++)
		{
			if (ch == Ops_Seps_list[i] || isspace(ch))
			{
				currentState = FSM[currentState][5];
				return currentState;
			}
		}
		for (i = 8; i < 22; i++)
		{
			if (ch == Ops_Seps_list[i] || isspace(ch))
			{
				currentState = FSM[currentState][3];
				return currentState;
			}
		}
	}
}
//---------------testChar() End-----------------------------



/*-----------------displayTemp() Begin----------------------
This function is called when ever a seperator, operator, or invalid word
is entered. Once entered, displayTemp() will test the variable input and decide
whether it is a keyword, identifier, integer, float, or default to invalid
if all others are not found.
*/
void displayTemp(string temp)
{
	//Display Temp as long as Temp is not Empty
	if (temp != "")
	{
		bool is_keyword = 0;
		//----------------Test for Keyword
		for (int i = 0; i < 20; i++) {

			if (KEYWORDS[i] == temp)
			{
				cout << "Keyword:\t=\t" << temp << endl;
				return;
			}
		}
		is_keyword = 1;
		//---------------Test for Identifier
		if (isalpha(temp[0]) && is_keyword == 1)
		{
			cout << "Identifier:\t=\t" << temp << endl;
			return;
		}
		//---------------Test for Int vs Float
		int test_float = 0;
		for (int i = 0; i < temp.length(); i++)
		{
			if (temp[i] == '.')
			{
				test_float = 1;
				break;
			}
		}
		if (test_float == 0)		// Int
		{
			cout << "Integer:\t=\t" << temp << endl;
			return;
		}
		else if (test_float == 1)	// Float
		{
			cout << "Float:\t=\t" << temp << endl;
			return;
		}
		//---------------Defualt to Invalid if all Other cases Fail
		cout << "Invalid\t=\t" << temp << endl;
		return;
	}
}
//------------------displayTemp() End-------------------------



/*---------------displayChar() Begin--------------------------
This function is called when ever a seperator, operator, or invalid word
is entered. Once entered, displayChar() will test the variable to see whether
the input was a Separator or Operator WITH EXCEPTION to special character
which inlcude: '!' and ' '(white space)*/
void displayChar(char ch)
{
	//---------------Display Separator or Operator


		for (int i = 0; i < 8; i++)
		{
			if (ch == Ops_Seps_list[i])
			{
				cout << "Operator\t=\t" << ch << endl;
			}
		}
		for (int i = 8; i < 22; i++)
		{
			if (ch == Ops_Seps_list[i] && ch != '!' && !isspace(ch))
			{
				cout << "Separator\t=\t" << ch << endl;
			}
		}
	
}
//-------------------displayChar() End------------------------

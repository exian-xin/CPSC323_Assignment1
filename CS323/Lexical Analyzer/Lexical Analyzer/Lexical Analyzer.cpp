#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <ctype.h>

using namespace std;
//-------------------------------------------------------------------------
string KEYWORDS[20] = { "int", "char", "string","float","void",
						"if", "for","while", "return", "else",
						"using", "namespace", "switch", "const", "default",
						"do", "break", "cout", "cin", "case"};
//--------------------------------------------------------------------------
char Ops_Seps_list[19] = {'<', '>','=','+', '-','%','/','*', //0-7 =  Operators
						'.','!', // 8-9 Special Seperators
						' ','(', ')', '{', '}', ',', ';', '[', ']' }; //10-18 Seperators


//[0-7] == Operators
//[8] ==  Special Seperator '.'
//[9] ==  Special Seperator ' '
//[10] == Special Sperator '!'
//[11] == Seperators
//--------------------------------------------------------------------------
char SEPERATORS[8] = {'(', ')', '{', '}', ',', ';', '[', ']'};
//---------------------------------------------------------------------------



int testChar(char ch, int state, int type);
int getType(string temp);
void displayType(int type, string temp);
int getCharType(char ch);
void displayChType(char ch);


int main()
{
	int startState = 0;
	int type = 0;
	int currentState = startState;
	string input;
	char ch;
	bool comment = 0;
	string temp;
	int temp_count = 0;
	ifstream iFile("program.txt");
	int size = 0;
	int i;
	if (!iFile.is_open())
	{
		cout << "Error, Could not open File" << endl;
		return 1;
	}

	while (!iFile.eof())
	{
		i = 0;
		getline(iFile, input);
		size = sizeof(input) / sizeof(char);


		while (i < size)
		{
			ch = input[i];
			if(comment == 0)
			{
			currentState = testChar(ch, currentState);

			switch (currentState)
			{
			case 0:				
				temp += ch;
				break;
			case 1:
				temp += ch;
				break;
			case 2:
				type = getType(temp);
				if(type == 0)
				{
					displayType(temp);
					chType = getCharType(ch);
					if(chType == 0)
					{
						displayChType(ch);
					}
					else if(chType == 1)
					{
						//Comments
						if(comment == 0)
							comment = 1;
						if(comment == 1)
							comment = 0;
					}
				else if(type == 1 )
				{
					chType = getCharType(ch);
					if(chType == 2 )
					{
					temp += ch;	
					}
				}
					
				break;
				}
				else if(comment == 1)
				{
				chType = getCharType(ch);
				if(chType == 1)
				{
					//Comments
					if(comment == 0)
						comment = 1;
					if(comment == 1)
						comment = 0;
				}
			}
		i++;
		}
		
				
	}
	
	iFile.close();

	return 0;
}


/*-----------------TestChar()-----------------------------------
currentState = 0 -- Beginning of new word
currentState = 1 -- middle of word
currentState = 2 -- end of word -- seperator -- operator-- '!' --  ' '
---------------------------------------------
*/
int testChar(char ch, int state)
{
	int currentState = state;
	int i = 0;
	 
	for (i = 0; i < 8; i++)
	{
		if (ch == Ops_Seps_list[i])
		{
			currentState = 2;
			return currentState;
		}
	}
	for (i = 8; i < 19; i++)
	{
		if (ch == Ops_Seps_list[i])
		{
			currentState = 2;
			return currentState;
		}
	}

}

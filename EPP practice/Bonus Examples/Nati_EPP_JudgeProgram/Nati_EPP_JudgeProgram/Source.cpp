#include <iostream>

using namespace std;

double average(int judges)
{
	double total = 0;							//Initializes total to 0
	double scores[10];							// Create an array with 10 spaces

	if (judges < 3)								
	{
		cout << "not enough judges " << endl;
		return 1;
	}
	else if (judges > 10)
	{
		cout << "Too many judges " << endl;
		return 1;
	}
	else
	{
		for (int i = 0; i < judges; i++)		//intializes scores to the array
		{
			cin >> scores[i];
		}
		for (int i = 0; i < judges; i++)		//Bubble sort
		{
			for (int j = 0; j < judges - 1 - i ; j++)
			{
				if (scores[j] > scores[j + 1])
				{
					int temp = scores[j+1];
					scores[j + 1] = scores[j];
					scores[j] = temp;
				}
			}
		}

		scores[0] = 0;						//taking out minimum score
		scores[judges - 1] = 0;				//taking out maximum score

		/*for (int i = 0; i < judges; i++)
		{
			cout << scores[i] << " ";
		}*/
		for (int i = 0; i < judges; i++)	//running sum of total
		{
			total += scores[i];
		}
		/*cout << total << endl;*/
		double avg;
		avg = total / (judges - 2);				// Get average of scores

		return avg;
	}
}

int main()
{
	int judges;
	double avg_Score;
	int temp_contestant_number = 0;		//holds contestant number to be tested
	double max = 0;						//Holds max average score to be tested
	cout << "Number of Judges: ";
	cin >> judges;
	int contestant_number;				//Final Product after testing

	while (true)
	{
		cout << "Contestant: ";
		cin >> temp_contestant_number;
		if (temp_contestant_number == -1)
		{
			break;
		}
		avg_Score = average(judges);
		cout << avg_Score << endl;

		if (avg_Score > max)
		{
			max = avg_Score;
			contestant_number = temp_contestant_number;
		}
	}

	cout << "Contestant " << contestant_number << " had the highest score!" << endl << endl;
	system("pause");

	return 0;
}
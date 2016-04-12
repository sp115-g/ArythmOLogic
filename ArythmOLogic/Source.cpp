#include "BaseLogic.h"

bool CheckString(char* input, int len)
{
	int i = 0;
	bool min_found = false, dot_found = false;
	if (!isdigit(input[0]) && input[0] != '-') return false;
	if (input[0] == '-') min_found = true;
	if (min_found) i++;
	for (i; i < len; i++)
	{
		if (isdigit(input[i])) continue;
		else if (!dot_found && isdigit(input[i-1]) && input[i] == '.')
			dot_found = true;
		else if (input[i] == '\0' && input[i-1] != '.') return true;
		else return false;
	}

	return false;
}

bool Enter(BaseLogic& number)
{
	char number1[100];
	cin >> number1;
	if (CheckString(number1, sizeof number1))
	{
		number.ReadNumber(number1, sizeof(number1));
		return true;
	}
	else
	{
		cerr << "Error in input" << endl;
		return false;
	}
}

void Menu()
{
	BaseLogic number1, number2, rez;
	while (true) // bad idea
	{
		system("CLS");
		cout << "============================ARYTHMOLOGIC MENU============================" << endl << endl;
		cout << "--> 1 <--  Entering numbers. " << endl;
		cout << "--> 2 <--  Entering numbers from file. " << endl;
		cout << "--> 3 <--  Operation a+b. " << endl;
		cout << "--> 4 <--  Operation a-b. " << endl;
		cout << "--> 5 <--  Operation a*b. " << endl;
		cout << "--> 6 <--  Operation a/b. " << endl;
		cout << "--> 7 <--  Operation x^n  (n - integer). " << endl;
		cout << "--> 8 <--  Operation 1/x. " << endl;
		cout << "--> 9 <--  Writing data to a file. " << endl;
		cout << "--> i <--  Display the result on the screen. " << endl;
		cout << "--> e <--  Exit. " << endl;
		cout << "\n>>> ";
		char wMode[1], last_action, nullstr[2] = "\0";
		cin >> wMode;
		switch (wMode[0])
		{
			case '1':
				rez.ReadNumber(nullstr, 1); // �������� ���������
				cout << "\nEnter number #1: ";
				if (!Enter(number1)) break;
				cout << "\nEnter number #2: ";
				Enter(number2);
				break;
			case '2':
				break;
			case '3':
				if (number1.isEmpty() == false && number2.isEmpty() == false)
				{
					rez.setDotPos(-1);
					rez.setNegative(0);
					rez.set_length(0);
					rez.Summ(number1, number2);
					last_action = '+';
				}
				else
				{
					cout << "Incorrect numbers. " << endl;
					system("PAUSE");
				}
				break;
			case '4':
				if (number1.isEmpty() == false && number2.isEmpty() == false)
				{
					rez.setDotPos(-1);
					rez.setNegative(0);
					rez.set_length(0);
					rez.Minus(number1, number2);
					last_action = '-';
				}
				else
				{
					cout << "Incorrect numbers. " << endl;
					system("PAUSE");
				}
				break;
			case '5': 
				if (!(number1.isEmpty() && number2.isEmpty()))
					rez = rez.Karatsuba_Mul(number1, number2);
				else
					cout << "Incorrect numbers" << endl;
				break;
			case '6': 
				break;
			case '7': 
				break;
			case '8': 
				break;
			case '9': 
				break;
			case 'i': 
				if (number1.isEmpty() == false && number2.isEmpty() == false && rez.isEmpty() == false)
				{
					number1.PrintNumbers();
					cout << last_action;
					number2.PrintNumbers();
					cout << "=============================================================";
					rez.PrintNumbers(); 
				}
				else
					cout << "Incorrect numbers or result. " << endl;
				system("PAUSE");
					break;
			case 'e': 
				return;
			default: 
				cout << "Incorrect work mode! "; 
				system("PAUSE");
		}
	}
}

int main()
{
	Menu();
	return 0;
}
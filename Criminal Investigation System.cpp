#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

//Defining Structs
//**********************************************
struct Login
{
	string Username;
	string Password;
};

struct date
{
	int d;
	int m;
	int y;
};

struct criminal
{
	int id;
	string name;
	string crime;
	date caught;
};
//**********************************************
//Functions
//**********************************************

void delay(unsigned int mseconds)//function ÚÏÇÏ
{
	clock_t goal = mseconds + clock();
	while (goal > clock());
}
// 6- Exit Program
void callExit()//function for exiting the program
{
	int process = 0;
	system("cls");
	cout << "\n\n\n\n\n";
	cout << "\n\tTaking You Out of The System";
	for (process = 0; process < 25; process++)
	{
		delay(150);
		cout << ".";
	}
	system("cls");
	cout << "\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t";
	cout << "You are out of the System.\n";
	cout << "\t\t\t\t\t\t";
	cout << "Thank You !";
	cout << "\n\n";
	cout << "\t\t\t\t\t";
	system("pause");
	exit(0);
}


int mainpage()
{
	int back = 0;
	string choise;
	cout << "\n\n\n\n";
	cout << "\t\t\t\t\t";
	cout << "1-Admin " << endl;
	cout << "\t\t\t\t\t";
	cout << "2-Officer " << endl;
	cout << "\t\t\t\t\t";
	cout << "Please enter your choise [1/2] : ";
	cin >> choise;
	if (choise == "1")
	{
		return 0;
	}
	else if (choise == "2")
	{
		cout << "\n\n";
		cout << "\t\t\t\t\t";
		cout << "You are accessed to enter the system as [Officer]" << endl;
		cout << "\n\n";
		cout << "\t\t\t\t\t";
		system("pause");
		system("cls");
		return 1;
	}
	else return 2;
}

int log(Login x) //function for login page
{
	int Try = 0;
	int true1 = 1;
	do {
		cout << "\n\n\n\n\n";
		cout << "\t\t\t\t\t  -------------------------------\n";
		cout << "\t\t\t\t\t  |CRIMINAL INVESTIGATING SYSTEM|\n";
		cout << "\t\t\t\t\t  -------------------------------\n";
		cout << "\n\n";
		cout << "\t\t\t\t\t  ";
		cout << "Username : ";
		cin >> x.Username;
		cout << "\t\t\t\t\t  ";
		cout << "\n";
		cout << "\t\t\t\t\t  ";
		cout << "Password : ";
		cin >> x.Password;
		if (x.Username == "ADMIN" && x.Password == "2003")
		{
			cout << "\n\n";
			cout << "\t\t\t\t\t";
			cout << "You are accessed to the system!\n\n";
			cout << "\t\t\t\t\t";
			system("pause");
			system("cls");//Ïí ÈÊæÏíäí ÕÝÍÉ ÌÏíÏÉ
			true1 = 0;
			return 1;
		}
		else
		{
			system("cls");
			Try += 1;
			cout << "\n\n\n";
			cout << "\t\t\t\t\t";
			cout << "No. of attempts remain: " << 3 - Try;
			cout << "\n\n";
			cout << "\t\t\t\t";
			system("pause");
			if (Try >= 3)
			{

				cout << "\t\t\t\t\t\t";
				cout << "\n";
				cout << "\t\t\t\t";
				cout << "No permission to enter the system!\n\n";
				cout << "\t\t\t\t";
				system("pause");
				callExit();
			}
		}

	} while (Try < 3);
}

// 1*- Search For Index
int id_index(criminal* thefts, int* size, int id)
{
	for (int i = 0; i < *size; i++)
	{
		if (thefts[i].id == id)
		{
			return i;
			break;
		}
	}
}


// Check Input
// byt2akd en el user da5lo sa7
string check_input(string entered, string desired)
{
	while (entered != desired)
	{
		cout << "Wrong Input Entered" << endl;
		cout << "Please Re-enter: ";
		cin >> entered;
	}
	return entered;
}

// 1- Add Record
criminal create_criminal(int* size, int* id_alloc)
{
	criminal* temp = new criminal;

	int d_temp = -1;
	int m_temp = -1;
	int y_temp = -1;

	// Criminal ID Allocation

	temp->id = *id_alloc;

	// Entering Criminal Name

	cout << "Enter The Name Criminal: ";
	getline(cin, temp->name);

	// Entering Crime Commited

	cout << "Enter Crime: ";
	getline(cin, temp->crime);

	// Entering Date Of Caught

	cout << "Enter Date" << endl;

	cout << "Day: ";
	while (!(cin >> d_temp))
	{
		cout << "Error: Please Enter A Valid Number: ";
		cin.clear();
		cin.ignore(123, '\n');
	}
	cin.ignore();

	while (d_temp > 31 || d_temp < 1)
	{
		cout << "Error: Enter A Day Between (1 & 31)!" << endl;
		cout << "Day: ";
		cin >> d_temp;
		cin.ignore();
	}

	cout << "Month: ";
	while (!(cin >> m_temp))
	{
		cout << "Error: Please Enter A Valid Number: ";
		cin.clear();
		cin.ignore(123, '\n');
	}
	cin.ignore();

	while (m_temp > 12 || m_temp < 1)
	{
		cout << "Error: Enter A Month Between (1 & 12)!" << endl;
		cout << "Month: ";
		cin >> m_temp;
		cin.ignore();
	}

	cout << "Year: ";
	while (!(cin >> y_temp))
	{
		cout << "Error: Please Enter A Valid Number: ";
		cin.clear();
		cin.ignore(123, '\n');
	}
	cin.ignore();

	while (y_temp > 2023 || y_temp < 1930)
	{
		cout << "Error: Enter A Year Between (1930 & 2023)!" << endl;
		cout << "Year: ";
		cin >> y_temp;
		cin.ignore();
	}
	temp->caught.d = d_temp;
	temp->caught.m = m_temp;
	temp->caught.y = y_temp;

	cout << "Criminal ID is: " << temp->id << endl;
	delay(150);


	return *temp;
}
void add_criminal(criminal*& thefts, int& size, const criminal temp)
{
	criminal* new_thefts = new criminal[size + 1];

	if (new_thefts == NULL)
	{
		cout << "Memory allocation error for add_criminal!" << endl;
		exit(-1);
	}

	for (int i = 0; i < size; i++)
	{
		new_thefts[i] = thefts[i];
	}

	if (size)
	{
		delete[] thefts;
	}

	new_thefts[size] = temp;
	size++;
	thefts = new_thefts;
	return;
}

// 2- Delete Record
void delete_criminal(criminal*& thefts, int& size, int id)
{
	int index = id_index(thefts, &size, id);
	for (int i = index; i < size - 1; i++)
	{
		thefts[i] = thefts[i + 1];
	}
	size--;
}

// 3- Modify Record
void modify_record(criminal& thefts, int size, int id)
{
	criminal* arr = &thefts;
	int index = id_index(arr, &size, id);
	int cont_mod = -1;
	do
	{
		int choice_mod = -1;
		cout << "1- Modify Name" << endl;
		cout << "2- Modify Crime" << endl;
		cout << "3- Modify Date" << endl << endl;
		cout << "Choose [1/2/3]: ";
		while (!(cin >> choice_mod))
		{
			cout << "Error: Please Enter A Valid Number: ";
			cin.clear();
			cin.ignore(123, '\n');
		}
		cin.ignore();

		while (choice_mod != 1 && choice_mod != 2 && choice_mod != 3)
		{
			cout << "Wrong Input Entered" << endl;
			cout << "Please Re-enter: ";
			cin >> choice_mod;
			cin.ignore();
		}


		switch (choice_mod)
		{
		case 1:
		{
			// Modify Criminal Name
			cout << "Enter The Name Criminal: ";
			getline(cin, arr[index].name);
			break;
		}
		case 2:
		{
			// Modify Crime
			cout << "Enter The Crime: ";
			getline(cin, arr[index].crime);
			break;
		}
		case 3:
		{
			int d_temp = -1;
			int m_temp = -1;
			int y_temp = -1;

			// Modify Date

			cout << "Enter Date" << endl;

			cout << "Day: ";
			while (!(cin >> d_temp))
			{
				cout << "Error: Please Enter A Valid Number: ";
				cin.clear();
				cin.ignore(123, '\n');
			}
			cin.ignore();

			while (d_temp > 31 || d_temp < 1)
			{
				cout << "Error: Enter A Day Between (1 & 31)!" << endl;
				cout << "Day: ";
				cin >> d_temp;
				cin.ignore();
			}

			cout << "Month: ";
			while (!(cin >> m_temp))
			{
				cout << "Error: Please Enter A Valid Number: ";
				cin.clear();
				cin.ignore(123, '\n');
			}
			cin.ignore();

			while (m_temp > 12 || m_temp < 1)
			{
				cout << "Error: Enter A Month Between (1 & 12)!" << endl;
				cout << "Month: ";
				cin >> m_temp;
				cin.ignore();
			}

			cout << "Year: ";
			while (!(cin >> y_temp))
			{
				cout << "Error: Please Enter A Valid Number: ";
				cin.clear();
				cin.ignore(123, '\n');
			}
			cin.ignore();

			while (y_temp > 2023 || y_temp < 1930)
			{
				cout << "Error: Enter A Year Between (1930 & 2023)!" << endl;
				cout << "Year: ";
				cin >> y_temp;
				cin.ignore();
			}

			arr[index].caught.d = d_temp;
			arr[index].caught.m = m_temp;
			arr[index].caught.y = y_temp;
			break;
		}
		}

		cout << "Do You Want To Make Another Modification? [Yes = 1 , No = 0]: ";
		while (!(cin >> cont_mod))
		{
			cout << "Error: Please Enter A Valid Number: ";
			cin.clear();
			cin.ignore(123, '\n');
		}
		cin.ignore();

		while (cont_mod != 1 && cont_mod != 0)
		{
			cout << "Error: Wrong Number Entered!" << endl;
			cout << "Do You Want To Make Another Modification? [Yes = 1 , No = 0]: ";
			cin >> cont_mod;
			cin.ignore();
		}

		if (cont_mod == 0)
		{
			break;
		}
	} while (1);



}

// 4- Search Record
void search_record(criminal& thefts, int size, int id)
{
	criminal* arr = &thefts;
	int index = id_index(arr, &size, id);
	cout << "\n\n";
	cout << "------------------------" << endl;
	cout << "Criminal ID: " << arr[index].id << endl;
	cout << "Criminal Name: " << arr[index].name << endl;
	cout << "Crime Commited: " << arr[index].crime << endl;
	cout << "Date: " << arr[index].caught.d << "/" << arr[index].caught.m << "/" << arr[index].caught.y << endl;
	cout << "------------------------" << endl;
	cout << "\n\n";
}

//Admin User

int menu_1(void)
{
	int size = 2;
	criminal* thefts = new criminal[size];
	criminal temp;

	//Hard Coded Records
	thefts[0] = { {0}, {"Mark"}, {"Murder"}, {{25}, {02}, {2010}} };
	thefts[1] = { {1}, {"Jack"}, {"Kidnap"}, {{12}, {05}, {2015}} };
	int id_alloc = 2;

	do
	{
		int choice = -1;
		cout << "\n\n\n\n";
		cout << "\t\t\t\t\t"; cout << "1- Add Criminal" << endl;
		cout << "\t\t\t\t\t"; cout << "2- Delete Criminal" << endl;
		cout << "\t\t\t\t\t"; cout << "3- Modify Criminal" << endl;
		cout << "\t\t\t\t\t"; cout << "4- Search Criminal" << endl;
		cout << "\t\t\t\t\t"; cout << "5- Display All Criminals" << endl;
		cout << "\t\t\t\t\t"; cout << "6- Exit Program" << endl << endl;
		cout << "\t\t\t\t\t"; cout << "Choose [1/2/3/4/5/6]: ";
		cout << "\n\n\n";
		while (!(cin >> choice) || choice > 6 || choice < 1)
		{
			cout << "Error: Please Enter A Valid Number: ";
			cin.clear();
			cin.ignore(123, '\n');
		}
		cin.ignore();


		switch (choice)
		{
		case 1:
		{
			while (choice == 1)
			{
				// Add A Criminal
				add_criminal(thefts, size, create_criminal(&size, &id_alloc));
				cout << "Criminal Added Successfuly!" << endl;
				cout << "Do you want to add another record? [Yes = 1 , No = 0]" << endl;
				while (!(cin >> choice) || choice > 1 || choice < 0)
				{
					cout << "Error: Please Enter A Valid Number: ";
					cin.clear();
					cin.ignore(123, '\n');
				}
				cin.ignore();
				id_alloc++;
			}
			break;
		}
		case 2:
		{
			int id_delete;
			cout << "Enter ID: ";
			while (!(cin >> id_delete))
			{
				cout << "Error: Please Enter A Valid Number: ";
				cin.clear();
				cin.ignore(123, '\n');
			}
			cin.ignore();
			delete_criminal(thefts, size, id_delete);
			break;
		}
		case 3:
		{
			int id_mod;
			cout << "Enter ID: ";
			while (!(cin >> id_mod))
			{
				cout << "Error: Please Enter A Valid Number: ";
				cin.clear();
				cin.ignore(123, '\n');
			}
			cin.ignore();

			if (id_mod < size - 2 || id_mod > size)
			{
				cout << "ID NOT FOUND!";
				delay(2000);
				break;
			}
			modify_record(*thefts, size, id_mod);
			break;
		}
		case 4:
		{
			int id_search;
			int cont_search = 1;
			while (cont_search == 1)
			{
				cout << "Enter ID: ";
				while (!(cin >> id_search))
				{
					cout << "Error: Please Enter A Valid Number: ";
					cin.clear();
					cin.ignore(123, '\n');
				}
				cin.ignore();

				if (id_search < id_alloc - 2 || id_search >= id_alloc)
				{
					cout << "ID NOT FOUND!" << endl;
					delay(2000);
					break;
				}
				else
				{
					search_record(*thefts, size, id_search);
				}

				cout << "Do You Want To Search For Another Record? [Yes = 1 , No = 0]: ";
				while (!(cin >> cont_search))
				{
					cout << "Error: Please Enter A Valid Number: ";
					cin.clear();
					cin.ignore(123, '\n');
				}
				cin.ignore();

				while (cont_search != 1 && cont_search != 0)
				{
					cout << "Error: Wrong Number Entered!" << endl;
					cout << "Do You Want To Search For Another Record? [Yes = 1 , No = 0]: ";
					while (!(cin >> cont_search))
					{
						cout << "Error: Please Enter A Valid Number: ";
						cin.clear();
						cin.ignore(123, '\n');
					}
					cin.ignore();

				}
			}
			break;
		}
		case 5:
		{
			string display = "1";
			cout << "\t\t\t";
			cout << "Criminal ID" << "\t";
			cout << "Criminal Name" << "\t" << "Crime Committed" << "\t\t";
			cout << "Date" << endl;
			cout << "\t\t\t";
			cout << "-----------------------------------------------------------------" << endl;
			for (int i = 0; i < size; i++)
			{
				cout << "\t\t\t";
				cout << thefts[i].id << "\t\t";
				cout << thefts[i].name << "\t\t" << thefts[i].crime << "\t\t\t";
				cout << thefts[i].caught.d << "/" << thefts[i].caught.m << "/" << thefts[i].caught.y << endl;
			}
			cout << endl << endl;
			cout << "\t\t\t\t\t";
			cout << "To Return To Mainpage Press [0]";
			getline(cin, display);

			display = check_input(display, "0");
			break;
		}
		case 6:
		{
			callExit();
		}
		}
		system("cls");
	} while (1);

	//Free Allocated Memory
	delete[] thefts;
}

int menu_2(void)
{
	system("cls");
	int id_alloc = 2;
	int size = 2;
	criminal* thefts = new criminal[size];
	criminal temp;
	thefts[0] = { {0}, {"Mark"}, {"Murder"}, {{25}, {02}, {2010}} };
	thefts[1] = { {1}, {"Jack"}, {"Kidnap"}, {{12}, {05}, {2015}} };
	do
	{
		int choice = -1;
		cout << "\n\n\n\n";
		cout << "\t\t\t\t\t"; cout << "1- Search Criminal" << endl;
		cout << "\t\t\t\t\t"; cout << "2- Display All Criminals" << endl;
		cout << "\t\t\t\t\t"; cout << "3- Exit Program" << endl << endl;
		cout << "\t\t\t\t\t"; cout << "Choose [1/2/3]: ";
		while (!(cin >> choice))
		{
			cout << "Error: Please Enter A Valid Number: ";
			cin.clear();
			cin.ignore(123, '\n');
		}
		cin.ignore();

		switch (choice)
		{
		case 1:
		{
			int id_search;
			int cont_search = 1;
			while (cont_search == 1)
			{
				cout << "Enter ID: ";
				while (!(cin >> id_search))
				{
					cout << "Error: Please Enter A Valid Number: ";
					cin.clear();
					cin.ignore(123, '\n');
				}
				cin.ignore();

				if (id_search >= id_alloc)
				{
					cout << "ID NOT FOUND!" << endl;
					delay(2000);
					break;
				}
				else
				{
					search_record(*thefts, size, id_search);
				}


				cout << "Do You Want To Search For Another Record? [Yes = 1 , No = 0]: ";
				while (!(cin >> cont_search))
				{
					cout << "Error: Please Enter A Valid Number: ";
					cin.clear();
					cin.ignore(123, '\n');
				}
				cin.ignore();

				while (cont_search != 1 && cont_search != 0)
				{
					cout << "Error: Wrong Number Entered!" << endl;
					cout << "Do You Want To Search For Another Record? [Yes = 1 , No = 0]: ";
					while (!(cin >> cont_search))
					{
						cout << "Error: Please Enter A Valid Number: ";
						cin.clear();
						cin.ignore(123, '\n');
					}
					cin.ignore();

				}
			}
			break;
		}
		case 2:
		{
			string display = "1";
			cout << left << "Criminal ID" << "\t";
			cout << "Criminal Name" << "\t" << "Crime Committed" << "\t\t";
			cout << right << "Date" << endl;
			cout << "-----------------------------------------------------------------" << endl;
			for (int i = 0; i < size; i++)
			{
				cout << left << thefts[i].id << "\t\t";
				cout << thefts[i].name << "\t\t" << thefts[i].crime << "   \t\t";
				cout << right << thefts[i].caught.d << "/" << thefts[i].caught.m << "/" << thefts[i].caught.y << endl;
			}
			cout << endl << endl;
			cout << "To Return To Mainpage Press [0]";
			getline(cin, display);

			display = check_input(display, "0");
			break;
		}
		case 3:
		{
			callExit();
		}
		}
		system("cls");
	} while (1);
	//Free Allocated Memory
	delete[] thefts;
}
//**********************************************
//main
//**********************************************
int main()
{
	int n;
	Login x;
	int B;
	do
	{
		B = mainpage();
		if (B == 0)
		{
			log(x);
			menu_1();
			//han7ot function 2smha menu1//han3ml ba2et el 7agat 2ly hya el menu 2ly fe kol 7aga zay (add,delet,....)
		}
		else if (B == 1)
		{
			menu_2();
			//han7ot function 2smha menu2//han3ml el menu el tanya bta3t officer
		}
	} while (B == 2);
}
//*******************
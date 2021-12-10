#include "database.h"

void readinFile(database tasks[], int &taskCount)
{
	ifstream inputFile;
	inputFile.open("tasks.txt");
	if(inputFile) {
		while (!inputFile.eof() && taskCount < TOTAL){
		inputFile.get(tasks[taskCount].itemName, 200, '\n');
		inputFile.ignore(200, '\n');
		inputFile.get(tasks[taskCount].itemDesc, 200, '\n');
		inputFile >> tasks[taskCount].month;
		inputFile >> tasks[taskCount].day;
		inputFile >> tasks[taskCount].year;
		inputFile.ignore(200, '\n');
		inputFile >> ws;
		taskCount++;
		}
	}
	
	inputFile.close();
}

void mainMenu(int taskCount)
{
	cout << endl << "********TASK MANAGER**********\n"
		<< "***** Numer of Tasks: " << taskCount << " *****" << endl
		<< "1 - Add Task\n"
		<< "2 - Print All Task\n"
		<< "3 - Print Today's Schedule\n"
		<< "4 - Modify Task\n"
		<< "5 - Quit\n" << endl
		<< "Enter Choice: ";
}

void addTask(database tasks[], int &taskCount)
{
	cin.ignore();
	cout << "Enter name of task: ";
	cin.getline(tasks[taskCount].itemName, 200, '\n');
	cout << "Enter a short description: ";
	cin.getline(tasks[taskCount].itemDesc, 200, '\n');
	cout << "Enter a month (1 to 12): ";
	cin >> tasks[taskCount].month;
	cout << "Enter a day (1 to 31): ";
	cin >> tasks[taskCount].day;
	cout << "Enter a year (must be larger than or equal to 2017): ";
	cin >> tasks[taskCount].year;
	taskCount++;
}

void printAllTasks(database tasks[], int taskCount)
{
	cout << taskCount << endl;
	cout << "%%%%%%%%%% TASKS %%%%%%%%%%% \n" << endl;
	for (int i = 0; i < taskCount; i++)
	{
		cout << "Name: " << tasks[i].itemName << endl;
		cout << "Description: " << tasks[i].itemDesc << endl;
		cout << "Due Date: " << tasks[i].month << "/" << tasks[i].day << "/" 
			 << tasks[i].year << endl;
		cout << "-------------------------------------" << endl;
	}
}
void printSchedule(database tasks[], int taskCount)
{
	int temp_month = 0, temp_day = 0, temp_year = 0;
	cout << "Enter the current month (1 to 12): ";
	cin >> temp_month;
	cout << "Enter the current day (1 to 31): ";
	cin >> temp_day;
	cout << "Enter the current year (must be larger than or equal to 2017): ";
	cin >> temp_year;
	cout << endl << endl << "!!!! PAST DUE !!!!" << endl << endl;
	for (int i = 0; i < taskCount; i++)
	{
		if ((tasks[i].year < temp_year) || ((tasks[i].year == temp_year) && (tasks[i].month < temp_month)) || ((tasks[i].year == temp_year) && (tasks[i].month == temp_month) && (tasks[i].day < temp_day)))
		{
				cout << "Name: " << tasks[i].itemName << endl;
				cout << "Description: " << tasks[i].itemDesc << endl;
				cout << "Due Date: " << tasks[i].month << "/" << tasks[i].day << "/" << tasks[i].year << endl;
				cout << "-------------------------------------" << endl;
		}	
	}
	cout << endl << endl << "-- Today's Tasks --" << endl << endl;
	for (int i = 0; i < taskCount; i++)
	{
		if ((tasks[i].year == temp_year) && (tasks[i].month == temp_month) && (tasks[i].day == temp_day))
		{
			cout << "Name: " << tasks[i].itemName << endl;
			cout << "Description: " << tasks[i].itemDesc << endl;
			cout << "Due Date: " << tasks[i].month << "/" << tasks[i].day << "/" << tasks[i].year << endl;
			cout << "-------------------------------------" << endl;
		}
	}
	cout << endl << endl << "--!Coming up soon!--"<< endl << endl;
	for (int i = 0; i < taskCount; i++)
	{
		if ((tasks[i].year > temp_year) || ((tasks[i].year == temp_year) && (tasks[i].month > temp_month)) || ((tasks[i].year == temp_year) && (tasks[i].month == temp_month) && (tasks[i].day > temp_day)))
		{
				cout << "Name: " << tasks[i].itemName << endl;
				cout << "Description: " << tasks[i].itemDesc << endl;
				cout << "Due Date: " << tasks[i].month << "/" << tasks[i].day << "/" << tasks[i].year << endl;
				cout << "-------------------------------------" << endl;
		}
	}
}

void modifymenu()
{
	cout << endl << "====>MODIFY " << endl
		<< "1 Name\n"
		<< "2 Description\n"
		<< "3 Due Date\n"
		<< "4 Quit\n"
		<< "Enter Choice: ";
}

void itemName(database tasks[], int i)
{
	cin.ignore();
	cout << "Enter new name of task: ";
	cin.getline(tasks[i].itemName, 200, '\n');
}

void itemDesc(database tasks[], int i)
{
	cin.ignore();
	cout << "Enter a short description: ";
	cin.getline(tasks[i].itemDesc, 200, '\n');
}

void dueDate(database tasks[], int i)
{
	int month, day, year;
	cout << "Enter a month (1 to 12): ";
	cin >> month;
	while (month > 12 || month < 1)
	{
		cout << "Invalid month. Enter a month (1 to 12): ";
		cin >> month;
	}
	tasks[i].month = month;
	cout << "Enter a day (1 to 31): ";
	cin >> day;
	while (day > 31 || day < 1)
	{
		cout << "Invalid day. Enter a day (1 to 31): ";
		cin >> day;
	}
	tasks[i].day = day;
	cout << "Enter a year (must be larger than or equal to 2017: ";
	cin >> year;
	while (year < 2017)
	{
		cout << "Invalid year. Enter a year (must be larger than or equal to 2017: ";
		cin >> year;
	}
	tasks[i].year = year;
}

void modifyTask(database tasks[], int taskCount)
{
	int choice;
	bool condition = true;
	char searchName[TOTAL];
	cout << "Enter task name to modify: ";
	cin.ignore();
	cin.getline(searchName, 200, '\n');
	for (int i = 0; i < taskCount; i++)
	{
		if (strcmp(searchName, tasks[i].itemName) == 0)
		{
			while (condition) 
			{
				modifymenu();
				cin >> choice;
				switch (choice)
				{
				case 1:
					itemName(tasks, i);
					break;
				case 2:
					itemDesc(tasks, i);
					break;
				case 3:
					dueDate(tasks, i);
					break;
				case 4:
					condition = false;
					break;
				default:
					cout << endl << "Incorrect Choice. Returning to Menu.\n";
				}
			}
		}
	}
}

void writeToFile(database tasks[], int taskCount)
{
	ofstream outFile;
	if(taskCount >= 1){
		outFile.open("tasks.txt");
		for (int i = 0; i < taskCount; i++)
		{
			outFile << tasks[i].itemName << endl;
			outFile << tasks[i].itemDesc << endl;
			outFile << tasks[i].month << endl;
			outFile << tasks[i].day << endl;
			outFile << tasks[i].year << endl;
		}
		outFile.close();
	}
}
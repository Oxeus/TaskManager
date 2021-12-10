#include "task_list.h"

void mainMenu(int &taskCount);
void addTask(TaskList &tasklist, int &taskCount);
void delTask(TaskList &tasklist, int &taskCount);
void printAll(TaskList &tasklist, int &taskCount);
void printToday(TaskList &tasklist, int &taskCount); \
void modifyTask(TaskList &tasklist, int &taskCount);

int main()
{
	TaskList tasklist;
	int taskCount = 0;
	tasklist.readinFile(taskCount);
	int choice;
	bool condition = true;
	while (condition) {
		mainMenu(taskCount);
		cin >> choice;
		switch (choice)
		{
		case 1:
			addTask(tasklist, taskCount);
			break;
		case 2:
			delTask(tasklist, taskCount);
			break;
		case 3:
			printAll(tasklist, taskCount);
			break;
		case 4:
			printToday(tasklist, taskCount);
			break;
		case 5:
			modifyTask(tasklist, taskCount);
			break;
		case 6:
			tasklist.writetoFile(taskCount);
			condition = false;
			break;
		default:
			cout << endl;
			cout << "Incorrect Choice. Returning to Menu.\n";
		}
	}
	cout << "*** THANK YOU FOR USING OUR TASK MANAGER ***" << endl;
	return 0;
}

void mainMenu(int &taskCount)
{
	cout << endl << "********TASK MANAGER**********\n"
		<< "***** Numer of Tasks: " << taskCount << " *****" << endl
		<< "1 - Add Task\n"
		<< "2 - Delete Task\n"
		<< "3 - Print All Task\n"
		<< "4 - Print Today's Schedule\n"
		<< "5 - Modify Task\n"
		<< "6 - Quit\n" << endl
		<< "Enter Choice: ";
}

void addTask(TaskList &tasklist, int &taskCount)
{
	char tempName[TOTAL], tempDesc[TOTAL];
	int temp_month = 0, temp_day = 0, temp_year = 0;
	bool check;
	int i = 0;
	cin.ignore();
	cout << "Enter name of task: ";
	cin.getline(tempName, 200, '\n');
	check = tasklist.taskCompare(tempName, taskCount);
	if (check)
	{ 
		cout << "Enter a short description: ";
		cin.getline(tempDesc, 200, '\n');
		cout << "Enter the current month (1 to 12): ";
		cin >> temp_month;
		while (temp_month > 12 || temp_month < 1)
		{
			cout << "Invalid month. Enter a month (1 to 12): ";
			cin >> temp_month;
		}
		cout << "Enter the current day (1 to 31): ";
		cin >> temp_day;
		while (temp_day > 31 || temp_day < 1)
		{
			cout << "Invalid day. Enter a day (1 to 31): ";
			cin >> temp_day;
		}
		cout << "Enter the current year (must be larger than or equal to 2017): ";
		cin >> temp_year;
		while (temp_year < 2017)
		{
			cout << "Invalid year. Enter a year (must be larger than or equal to 2017: ";
			cin >> temp_year;
		}
		tasklist.addTask(tempName, tempDesc, temp_month, temp_day, temp_year, taskCount);
	}
	else
	{
		cout << endl << "That task is already in the list." << endl;
	}
}

void delTask(TaskList &tasklist, int &taskCount)
{
	char tempName[TOTAL];
	cout << "What is the name of the task that you want to delete: ";
	cin.ignore();
	cin.getline(tempName, 200, '\n');
	tasklist.delTask(tempName, taskCount);
}

void printAll(TaskList &tasklist, int &taskCount)
{
	tasklist.printAll(taskCount);
}

void printToday(TaskList &tasklist, int &taskCount)
{
	int temp_month = 0, temp_day = 0, temp_year = 0;
	cout << "Enter the current month (1 to 12): ";
	cin >> temp_month;
	while (temp_month > 12 || temp_month < 1)
	{
		cout << "Invalid month. Enter a month (1 to 12): ";
		cin >> temp_month;
	}
	cout << "Enter the current day (1 to 31): ";
	cin >> temp_day;
	while (temp_day > 31 || temp_day < 1)
	{
		cout << "Invalid day. Enter a day (1 to 31): ";
		cin >> temp_day;
	}
	cout << "Enter the current year (must be larger than or equal to 2017): ";
	cin >> temp_year;
	while (temp_year < 2017)
	{
		cout << "Invalid year. Enter a year (must be larger than or equal to 2017: ";
		cin >> temp_year;
	}
	tasklist.printToday(temp_month, temp_day, temp_year, taskCount);
}

void functempName(TaskList &tasklist, char checkName[], char tempName[], int &taskCount)
{
	cin.ignore();
	cout << "Enter new name of task: ";
	cin.getline(tempName, 200, '\n');
	tasklist.modifyName(checkName, tempName, taskCount);
}

void functempDesc(TaskList &tasklist, char checkName[], char tempDesc[], int &taskCount)
{
	cin.ignore();
	cout << "Enter a short description: ";
	cin.getline(tempDesc, 200, '\n');
	tasklist.modifyDesc(checkName, tempDesc, taskCount);
}

void functiontempDate(TaskList &tasklist, char checkName[], int temp_month, int temp_day, int temp_year, int &taskCount)
{
	cout << "Enter the current month (1 to 12): ";
	cin >> temp_month;
	while (temp_month > 12 || temp_month < 1)
	{
		cout << "Invalid month. Enter a month (1 to 12): ";
		cin >> temp_month;
	}
	cout << "Enter the current day (1 to 31): ";
	cin >> temp_day;
	while (temp_day > 31 || temp_day < 1)
	{
		cout << "Invalid day. Enter a day (1 to 31): ";
		cin >> temp_day;
	}
	cout << "Enter the current year (must be larger than or equal to 2017): ";
	cin >> temp_year;
	while (temp_year < 2017)
	{
		cout << "Invalid year. Enter a year (must be larger than or equal to 2017: ";
		cin >> temp_year;
	}
	tasklist.modifyDate(checkName, temp_month, temp_day, temp_year, taskCount);
}

void modifyTask(TaskList &tasklist, int &taskCount)
{
	char tempName[TOTAL], checkName[TOTAL], tempDesc[TOTAL];
	int temp_month = 0, temp_day = 0, temp_year = 0, choice;
	bool check, condition = true;
	cout << "Enter task name to modify: ";
	cin.ignore();
	cin.getline(checkName, 200, '\n');
	check = tasklist.taskCompare(checkName, taskCount);
	if (!check)
	{
		while (condition)
		{
			cout << endl << "====>MODIFY " << endl
				<< "1 Name\n"
				<< "2 Description\n"
				<< "3 Due Date\n"
				<< "4 Quit\n"
				<< "Enter Choice: ";
			cin >> choice;
			switch (choice)
			{
			case 1:
				functempName(tasklist, checkName, tempName, taskCount);
				break;
			case 2:
				functempDesc(tasklist, checkName, tempDesc, taskCount);
				break;
			case 3:
				functiontempDate(tasklist, checkName, temp_month, temp_day, temp_year, taskCount);
				break;
			case 4:
				condition = false;
				break;
			default:
				cout << endl << "Incorrect Choice. Returning to Menu.\n";
			}
		}
	}
	else
	{
		cout << endl << "That task is already in the list." << endl;
	}
}


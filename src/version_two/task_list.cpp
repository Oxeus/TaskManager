#include "task_list.h"

void TaskList::readinFile(int &taskCount)
{
	char itemName[TOTAL], itemDesc[TOTAL];
	int day, month, year;
	ifstream inputFile;
	inputFile.open("tasks.txt");
	if (inputFile)
	{
		while (inputFile.good() && taskCount < TOTAL)
		{
			inputFile.get(itemName, 200, '\n');
			inputFile.ignore(200, '\n');
			inputFile.get(itemDesc, 200, '\n');
			inputFile >> month;
			inputFile >> day;
			inputFile >> year;
			inputFile.ignore(200, '\n');
			inputFile >> ws;
			list[taskCount] = Task(itemName, itemDesc, month, day, year);
			taskCount++;
		}
		inputFile.close();
	}
	else
	{
		cout << "The file does not exist, loading program with 0 tasks." << endl;
	}
}

bool TaskList::taskCompare(char checkName[], int &taskCount)
{
	bool answer = true;
	for (int i = 0; i < taskCount; i++)
	{
		if (strcmp(checkName, list[i].get_itemName()) == 0)
		{
			answer = false;
			
		}
	}
	return answer;
}

void TaskList::addTask(char tempName[], char tempDesc[], int temp_month, int temp_day, int temp_year, int &taskCount)
{
		list[taskCount] = Task(tempName, tempDesc, temp_month, temp_day, temp_year);
		taskCount++;
}

void TaskList::delTask(char tempName[], int &taskCount)
{
	bool answer = false;
	int j;
	{
		for (int i = 0; i < taskCount; i++)
		{
			if (strcmp(tempName, list[i].get_itemName()) == 0)
			{
				answer = true;
				j = i;
			}
		}
		if (answer)
		{
			list[j] = Task();
			for (int i = j; i < taskCount; ++i)
			{
				list[i] = list[i + 1];
			}
			taskCount--;
		}
		else
		{
			cout << endl << "That name is not in the list." << endl;
		}
	}
}

void TaskList::printAll(int &taskCount)
{
	
	for(int i = 0; i < taskCount; i++)
	{
		list[i].print();
	}
}

void TaskList::printToday(int temp_month, int temp_day, int temp_year, int &taskCount)
{
	
	cout << endl << endl << "!!!! PAST DUE !!!!" << endl << endl;
	for (int i = 0; i < taskCount; i++)
	{
		if ((list[i].get_year() < temp_year) || ((list[i].get_year() == temp_year) && (list[i].get_month() < temp_month)) || ((list[i].get_year() == temp_year) && (list[i].get_month() == temp_month) && (list[i].get_day() < temp_day)))
		{
			list[i].print();
		}
	}
	cout << endl << endl << "-- Today's Tasks --" << endl << endl;
	for (int i = 0; i < taskCount; i++)
	{
		if ((list[i].get_year() == temp_year) && (list[i].get_month() == temp_month) && (list[i].get_day() == temp_day))
		{
			list[i].print();
		}
	}
	cout << endl << endl << "--!Coming up soon!--�" << endl << endl;
	for (int i = 0; i < taskCount; i++)
	{
		if ((list[i].get_year() > temp_year) || ((list[i].get_year() == temp_year) && (list[i].get_month() > temp_month)) || ((list[i].get_year() == temp_year) && (list[i].get_month() == temp_month) && (list[i].get_day() > temp_day)))
		{
			list[i].print();
		}
	}
}

void TaskList::modifyName(char checkName[], char tempName[], int &taskCount)
{
	for (int i = 0; i < taskCount; i++)
	{
		if (strcmp(checkName, list[i].get_itemName()) == 0)
		{
			list[i].set_itemName(tempName);
		}
	}
}

void TaskList::modifyDesc(char checkName[], char tempDesc[], int &taskCount)
{
	for (int i = 0; i < taskCount; i++)
	{
		if (strcmp(checkName, list[i].get_itemName()) == 0)
		{
			list[i].set_itemDesc(tempDesc);
		}
	}
}

void TaskList::modifyDate(char checkName[], int temp_month, int temp_day, int temp_year, int &taskCount)
{
	for (int i = 0; i < taskCount; i++)
	{
		if (strcmp(checkName, list[i].get_itemName()) == 0)
		{
			list[i].set_month(temp_month);
			list[i].set_day(temp_day);
			list[i].set_year(temp_year);
		}
	}
	
}

void TaskList::writetoFile(int &taskCount)
{
	ofstream outFile;
	if(taskCount >= 1) {
		outFile.open("tasks.txt");
		for (int i = 0; i < taskCount; i++)
		{	
			outFile << list[i].get_itemName() << endl;
			outFile << list[i].get_itemDesc() << endl;
			outFile << list[i].get_month() << endl;
			outFile << list[i].get_day() << endl;
			outFile << list[i].get_year() << endl;
		}
		outFile.close();
	}	
}
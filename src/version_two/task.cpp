#include "task.h"

//Constructors
Task::Task()
{
	itemName[0] = '\0';
	itemDesc[0] = '\0';
	month = 0;
	day = 0;
	year = 0;
}

Task::Task(char in[], char id[], int tempmonth, int tempday, int tempyear)
{
	strcpy(itemName, in);
	strcpy(itemDesc, id);
	month = tempmonth;
	day = tempday;
	year = tempyear;
}

//Setters
void Task::set_itemName(char in[])
{
	strcpy(itemName, in);
}

void Task::set_itemDesc(char id[])
{
	strcpy(itemDesc, id);
}

void Task::set_month(int m)
{
	month = m;
}

void Task::set_day(int d)
{
	day = d;
}

void Task::set_year(int y)
{
	year = y;
}

//Getters
char * Task::get_itemName()
{
	return itemName;
}

char * Task::get_itemDesc()
{
	return itemDesc;
}

int Task::get_month()
{
	return month;
}

int Task::get_day()
{
	return day;
}

int Task::get_year()
{
	return year;
}

//Functions
void Task::print()
{
	cout << "Name: " << itemName << endl;
	cout << "Description: " << itemDesc << endl;
	cout << "Due Date: " << month << "/" << day << "/"
		<< year << endl;
	cout << "-------------------------------------" << endl;
}
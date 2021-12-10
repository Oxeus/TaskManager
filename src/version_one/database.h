#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

const int TOTAL = 200;

struct database
{
	char itemName[TOTAL];
	char itemDesc[TOTAL];
	int month;
	int day;
	int year;
};

void readinFile(database tasks[], int &taskCount);
void mainMenu(int taskCount);
void addTask(database tasks[], int &taskCount);
void printAllTasks(database tasks[], int taskCount);
void printSchedule(database tasks[], int taskCount);
void modifyTask(database tasks[], int taskCount);
void writeToFile(database tasks[], int taskCount);

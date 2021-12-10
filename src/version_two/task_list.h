#include "task.h"

class TaskList 
{
public:
	void readinFile(int &taskCount);
	bool taskCompare(char checkName[], int &taskCount);
	void addTask(char tempName[], char tempDesc[], int temp_month, int temp_day, int temp_year, int &taskCount);
	void delTask(char tempName[], int &taskCount);
	void printAll(int &taskCount);
	void printToday(int temp_month, int temp_day, int temp_year, int &taskCount);
	void modifyName(char checkName[], char tempName[], int &taskCount);
	void modifyDesc(char checkName[], char tempDesc[], int &taskCount);
	void modifyDate(char checkName[], int temp_month, int temp_day, int temp_year, int &taskCount);
	void writetoFile(int &taskCount);
	

private:
	int taskCount;
	Task list[TOTAL];
};

#include "database.h"

int main()
{
	database tasks[TOTAL];
	int taskCount = 0;
	readinFile(tasks, taskCount);
	int choice;
	bool condition = true;
	while (condition) {
		mainMenu(taskCount);
		cin >> choice;
		switch (choice)
		{
			case 1:
				addTask(tasks, taskCount);
				break;
			case 2:
				printAllTasks(tasks, taskCount);
				break;
			case 3: 
				printSchedule(tasks, taskCount);
				break;
			case 4: 
				modifyTask(tasks, taskCount);
				break;
			case 5:
				writeToFile(tasks, taskCount);
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
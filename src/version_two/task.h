#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

#ifndef TASK_H
#define TASK_H

const int TOTAL = 200;

class Task
{
public:

	//Constructors
	Task();
	Task(char in[], char id[], int tempmonth, int tempday, int tempyear);
	
	//Setters
	void set_itemName(char in[]);
	void set_itemDesc(char id[]);
	void set_day(int d);
	void set_month(int m);
	void set_year(int y);
	
	//Getters
	char * get_itemName();
	char * get_itemDesc();
	int get_month();
	int get_day();
	int get_year();

	//Functions
	void print();

private: 
	char itemName[TOTAL];
	char itemDesc[TOTAL];
	int month;
	int day;
	int year;
}; 

#endif
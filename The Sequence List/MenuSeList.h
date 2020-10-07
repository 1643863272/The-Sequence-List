#pragma once
#include "SequenceList.h"
#include "SequenceList.cpp"
#include "Student.h"
#include <iostream>
using namespace std;

class MenuSeList
{
private:
	SequenceList<int> seListInt;
	SequenceList<Student> seListStu;

public:
	

	void Menu();
	void MenuInt();

	void IntInsert();
	void IntErase();
	void IntSearch();
};


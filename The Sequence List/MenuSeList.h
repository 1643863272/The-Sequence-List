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
	

	void Menu();    //���˵�

	//-----Int Begin----
	void MenuInt(); //Int�˵�

	void IntInsert();    //Int����˵�
	void IntErase();     //Intɾ���˵�
	void IntSearch();    //Int��ѯ�˵�
	void IntReadFile();  //Int���ļ�
	void IntWriteFile(); //Intд�ļ�
	//-----Int Over----

	//-----Stu Begin---
	void MenuStu();

	void StuInsert();    //Int����˵�
	void StuErase();     //Intɾ���˵�
	void StuSearch();    //Int��ѯ�˵�
	void StuReadFile();  //Int���ļ�
	void StuWriteFile(); //Intд�ļ�
	//-----Stu Over----
};


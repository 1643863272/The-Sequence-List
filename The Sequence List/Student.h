#pragma once
#include <iostream>
#include <string>
using namespace std;

/// <summary>
/// ѧ����
/// </summary>
class Student
{
private:
	string name;   //����
	long ID;       //ѧ��
	int age;       //����
public:
	Student(string name = "����", long ID = 1, int age = 18);
	friend ostream& operator<<(ostream& os, const Student& s);
	friend istream& operator>>(istream& is, Student& s);
};


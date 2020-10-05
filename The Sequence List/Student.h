#pragma once
#include <iostream>
#include <string>
using namespace std;

/// <summary>
/// 学生类
/// </summary>
class Student
{
private:
	string name;   //姓名
	long ID;       //学号
	int age;       //年龄
public:
	Student(string name = "无名", long ID = 1, int age = 18);
	friend ostream& operator<<(ostream& os, const Student& s);
	friend istream& operator>>(istream& is, Student& s);
};


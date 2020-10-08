#include "Student.h"

Student::Student(string name, long ID, int age)
{
	this->name = name;
	this->ID = ID;
	this->age = age;
}

bool Student::operator==(const Student& other)
{
	return (this->ID == other.ID);
}

bool Student::operator>(const Student& other)
{
	return (this->ID > other.ID);
}

bool Student::operator<(const Student& other)
{
	return (this->ID < other.ID);
}

void Student::Input()
{
	cout << "输入姓名:"; cin >> this->name;
	cout << "输入ID:"; cin >> this->ID;
	cout << "输入年龄:"; cin >> this->age;
}


ostream& operator<<(ostream& os, const Student& s)
{
	os << s.name << " " << s.ID << " " << s.age << endl;
	// TODO: 在此处插入 return 语句
	return os;
}

istream& operator>>(istream& is, Student& s)
{
	is >> s.name >> s.ID >> s.age;
	// TODO: 在此处插入 return 语句
	return is;
}

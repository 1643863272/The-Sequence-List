#include "Student.h"

Student::Student(string name, long ID, int age)
{
	this->name = name;
	this->ID = ID;
	this->age = age;
}


ostream& operator<<(ostream& os, const Student& s)
{
	os << s.name << " " << s.ID << " " << s.age << endl;
	// TODO: �ڴ˴����� return ���
	return os;
}

istream& operator>>(istream& is, Student& s)
{
	is >> s.name >> s.ID >> s.age;
	// TODO: �ڴ˴����� return ���
	return is;
}

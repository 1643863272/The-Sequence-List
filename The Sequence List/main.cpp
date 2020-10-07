#include <iostream>
#include <vector>
#include "SequenceList.h"
#include "SequenceList.cpp"
#include "Student.h"
using namespace std;

int main() {

	int i = 0;
	SequenceList<int> a;
	a.PushBack(12);
	a.PushBack(123);
	a.PushBack(1215);
	a.Display();
	a.Insert(4, 6);
	a.Insert(2, 230);
	a.Insert(4, 6);
	a.Display();
	cout << a.Search(6) << endl;
	cout << a.Search(120) << endl;

	cout << a.Locate(6) << endl;
	cout << a.Locate(120) << endl;

	a.Erase(6);
	a.Display();
	a.Erase(6);
	a.Display();

	cout << a.EraseByPos(-1) << endl;
	cout << a.EraseByPos(4) << endl;

	a.Display();
	cout << a.InsertAfter(12, 6) << endl;
	a.Display();
	cout << a.InsertBefore(12, 356) << endl;
	a.Display();

	a.Clear();
	a.Display();
	a.PushBack(145);
	a.PushBack(12);
	cout << "size" << a.Size() << endl;
	a.Display();

	a.Modify(1, 489);
	a.Display();

	a.WirteFile("a.txt");

	SequenceList<int> s;
	s.PushBack(15);
	s.PushBack(5616);
	s.PushBack(133);

	s.WirteFile("s.txt");

	s.ReadFile("a.txt");
	s.Display();

	//Student s1("1", 1561656l, 18);
	//cout << s1;
	//cin >> s1;
	//cout << s1;

	SequenceList<Student> stuSL01;
	stuSL01.PushBack(Student("fzy", 6319070l, 26));
	stuSL01.PushBack(Student("lhs", 6365070l, 16));
	stuSL01.Display();
	stuSL01.WirteFile("stu01.txt");

	SequenceList<Student> stuSL02;
	stuSL02.ReadFile("stu01.txt");
	stuSL02.Display();
	stuSL02.PushBack(Student("58", 1112l, 12));
	stuSL02.Display();

	SequenceList<int> ss1;
	ss1.PushBack(415);
	ss1.PushBack(415);
	ss1.PushBack(415);
	ss1.PushBack(415);
	ss1.Erase(415);
	ss1.Display();
	cout <<"size:"<< ss1.Size() << endl;
	cout << ss1.isEmpty() << endl;
	ss1.PushBack(12);
	ss1.Display();
	cout << "size:" << ss1.Size() << endl;
	cout << ss1.isEmpty() << endl;
	ss1.PushBack(12);
	ss1.PushBack(20);
	ss1.PushBack(12);
	ss1.Erase(12);
	ss1.Display();
	cout << "size:" << ss1.Size() << endl;
	cout << ss1.isEmpty() << endl;

	ss1.Display();
	ss1.PushBack(45);
	ss1.PushBack(13);
	ss1.PushBack(5);
	ss1.PushBack(63);
	ss1.PushBack(45);
	ss1.Display();
	ss1.Sort();
	ss1.Display();


	SequenceList<Student> stuSL03;
	stuSL03.PushBack(Student("aa", 4564l, 12));
	stuSL03.PushBack(Student("aa", 454l, 18));
	stuSL03.PushBack(Student("cx", 7921l, 32));
	stuSL03.PushBack(Student("666", 645l, 46));
	stuSL03.Display();
	stuSL03.Sort();
	stuSL03.Display();
	Student se01("56", 454l, 64);
	cout<<stuSL03.Search(se01);
	return 0;
}


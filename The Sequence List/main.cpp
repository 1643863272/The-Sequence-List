#include <iostream>
#include <vector>
#include "SequenceList.h"
#include "SequenceList.cpp"
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

	cout << a.Erase(6) << endl;
	a.Display();
	cout << a.Erase(6) << endl;
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

	SequenceList<int> s(a);
	s.Display();
	return 0;
}
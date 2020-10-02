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
	return 0;
}
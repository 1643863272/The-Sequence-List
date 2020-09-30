#include <iostream>
#include <vector>
using namespace std;

int main() {
	cout << "..." << endl;
	int* a = new int[10];
	for (int i = 0; i < sizeof(a); i++) {
		a[i] = (i + 1) * (i + 2);
	}
	cout << "a:" << endl;
	cout << "sizeof a :" << sizeof(a) << endl;
	for (int i = 0; i < sizeof(a); i++) {
		cout << a[i] << "   ";
	}
	cout << endl;
	int* b = new int[16];
	for (int i = 0; i < sizeof(a); i++)
		b[i] = a[i];
	
	delete[]a;
	a = b;
	cout << "a:" << endl;
	cout << "sizeof a :" << sizeof(a) << endl;
	for (int i = 0; i < sizeof(a); i++) {
		cout << a[i] << "   ";
	}
	cout << endl;
	
	return 0;
}
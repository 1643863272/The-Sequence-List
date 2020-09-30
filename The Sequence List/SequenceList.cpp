#include "SequenceList.h"


template<class T>
void SequenceList<T>::resize()
{
	T* newDate = new T[maxSize + sizeToAdd];
	if (newDate == NULL) {
		cerr << "ÄÚ´æ·ÖÅäÊ§°Ü!" << endl;
		exit(1);
	}
	T* header = data;
	T* newHeader = newDate;
	while (header) {
		*newHeader++ = *header++;
	}
	delete[] data;
	data = newDate;
}

template<class T>
SequenceList<T>::SequenceList(int size)
{
	data = new T[size];
	if (data == NULL) {
		cerr << "ÄÚ´æ·ÖÅäÊ§°Ü£¡" << endl;
		exit(1);
	}
	maxSize = size;
	length = 0;
	sizeToAdd = 2;
}

template<class T>
SequenceList<T>::~SequenceList()
{
	delete[] data;
}

template<class T>
bool SequenceList<T>::Insert(int pos, T ele)
{
	if (pos<0 || pos >length) {
		return false;
	}
	for (int i = pos; i < length; i++) {
		data[i + 1] = data[i];
	}
}

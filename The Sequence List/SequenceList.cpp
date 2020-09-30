#include "SequenceList.h"


template<class T>
void SequenceList<T>::resize()
{
	T* newDate = new T[maxSize + sizeToAdd];
	if (newDate == NULL) {
		cerr << "�ڴ����ʧ��!" << endl;
		exit(1);
	}
	//����
	for (int i = 0; i < length; i++)
		newDate[i] = data[i];

	delete[] data;
	data = newDate;
	maxSize += sizeToAdd;
	sizeToAdd *= 2;       //ÿ�����ݸ���
}

template<class T>
SequenceList<T>::SequenceList(int size)
{
	data = new T[size];
	if (data == NULL) {
		cerr << "�ڴ����ʧ�ܣ�" << endl;
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

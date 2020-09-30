#pragma once
#include <iostream>
using namespace std;
template<class T>
class SequenceList
{
private:
	T* data;     //����ĺ�������
	int length;  //Ŀǰ����
	int maxSize; //�������
	const int static defaultSize = 64;  //Ĭ������
	int sizeToAdd;  //ÿ��resize���ӵ�����(2��4��8��16....)

	void resize();

public:
	/// <summary>
	/// ���캯��
	/// </summary>
	/// <param name="size">Ĭ���ڴ��С</param>
	SequenceList(int size = defaultSize);
	~SequenceList();  //��������

	bool Insert(int pos, T ele);

};


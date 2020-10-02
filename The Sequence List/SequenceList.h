#pragma once
#include <iostream>
using namespace std;
/// <summary>
/// ˳���
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
class SequenceList
{
private:
	T* data;     //����ĺ�������
	int length;  //Ŀǰ����
	int maxSize; //�������
	const int static defaultSize = 64;  //Ĭ������
	int sizeToAdd;  //ÿ��resize���ӵ�����(2��4��8��16....)

	void resize();  //����

public:

	SequenceList(int size = defaultSize);  //���캯��
	~SequenceList();  //��������

	bool Insert(int pos, T ele);  //����
	bool PushBack(T ele);         //��������
	int Search(T ele) const;      //����
	int Locate(T ele) const;      //��λ      
	void Display() const;         //��ʾ����Ԫ��

};

#pragma once
#include <iostream>
#include <string>
using namespace std;

/// <summary>
/// ��������
/// </summary>
enum SortType {
	None,      //�ǵ����ݼ�������0Ԫ�أ�
	Increase,  //����
	Decrease,  //�ݼ�
	Both       //�����ݼ�(1��Ԫ�� ���� ȫ����ȵ�Ԫ��)
};

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
	int sizeToAdd;       //ÿ��resize���ӵ�����(2��4��8��16....)
	SortType sortType;   //��������

	void resize();  //����

	void judgeSortType();  //�ж���������
	bool isAllEqual();     //�ж��Ƿ�����Ԫ�����(��Ԫ��Ϊfalse)
	bool isIncrease();     //�ж��Ƿ�Ϊ����
	bool isDecrease();     //�ж��Ƿ�Ϊ�ݼ�

	void judgeSortAfterInsert(int pos);  //������ж���������

	int binarySearch(T ele) const;    //���ַ�����

public:

	SequenceList(int size = defaultSize);  //���캯��
	SequenceList(SequenceList<T>& L);      //���ƹ��캯��
	~SequenceList();  //��������

	bool Insert(int pos, T ele);  //����
	bool InsertBefore(T eleBefore,T ele);     //��ָ��Ԫ��ǰ����
	bool InsertAfter(T eleAfter, T ele);      //��ָ��Ԫ�غ����
	bool PushBack(T ele);         //��������

	int Search(T ele) const;      //����
	int Locate(T ele) const;      //��λ
	void Display() const;         //��ʾ����Ԫ��

	void Erase(T ele);            //ɾ��ָ��Ԫ�أ����У�
	bool EraseByPos(int pos);     //ɾ��ָ��λ��Ԫ��

	bool Modify(int pos, T ele);  //�޸�ָ��λ�õ�Ԫ��
	void ModifyAToB(T A, T B);    //�����е�Ԫ��A��ΪԪ��B

	void Sort();   //����Ĭ��Ϊ������

	T At(int pos) const;     //����ָ��λ��Ԫ��
	int Size() const;        //����Ԫ�ظ���
	int Capacity() const;    //����Ŀǰ�������ɵ�Ԫ������
	bool isEmpty() const;    //�Ƿ�Ϊ��
	void Clear();            //���˳���
	int FindCount(T ele) const;    //����Ԫ�ظ���

	void ReadFile(string fileName);   //��ȡ�ļ�����ԭ�����ݻ�Ϊ�ļ�����
	void WirteFile(string fileName);  //������д���ļ�(����)

};

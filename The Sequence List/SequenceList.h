#pragma once
#include <iostream>
using namespace std;
/// <summary>
/// 顺序表
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
class SequenceList
{
private:
	T* data;     //储存的核心数据
	int length;  //目前容量
	int maxSize; //最大容量
	const int static defaultSize = 64;  //默认容量
	int sizeToAdd;  //每次resize增加的容量(2、4、8、16....)

	void resize();  //扩容

public:

	SequenceList(int size = defaultSize);  //构造函数
	~SequenceList();  //析构函数

	bool Insert(int pos, T ele);  //插入
	bool PushBack(T ele);         //在最后插入
	int Search(T ele) const;            //查找
	void Display() const;       //显示所有元素

};










/// <summary>
/// 扩容
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
void SequenceList<T>::resize()
{
	T* newDate = new T[maxSize + sizeToAdd];
	if (newDate == NULL) {
		cerr << "内存分配失败!" << endl;
		exit(1);
	}
	//复制
	for (int i = 0; i < length; i++)
		newDate[i] = data[i];

	delete[] data;
	data = newDate;
	maxSize += sizeToAdd;
	sizeToAdd *= 2;       //每次扩容更多
}

/// <summary>
/// 构造函数
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="size">默认容量</param>
template<class T>
SequenceList<T>::SequenceList(int size)
{
	data = new T[size];
	if (data == NULL) {
		cerr << "内存分配失败！" << endl;
		exit(1);
	}
	maxSize = size;
	length = 0;
	sizeToAdd = 2;
}

/// <summary>
/// 析构函数
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
SequenceList<T>::~SequenceList()
{
	if (data != NULL)
		delete[] data;
}

/// <summary>
/// 插入数据
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="pos">插入位置(下标)</param>
/// <param name="ele">插入元素</param>
/// <returns>是否插入成功(bool)</returns>
template<class T>
bool SequenceList<T>::Insert(int pos, T ele)
{
	if (pos<0 || pos >length) {  //超出范围，插入失败
		return false;
	}
	if (maxSize == length)   //容量不足，扩容
		resize();

	for (int i = length - 1; i >= pos; i--)  //后移
		data[i + 1] = data[i];

	data[pos] = ele;
	length++;
}

/// <summary>
/// 在最后插入元素
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="ele">要插入的元素</param>
/// <returns>是否插入成功</returns>
template<class T>
bool SequenceList<T>::PushBack(T ele)
{
	return Insert(length, ele);
}

/// <summary>
/// 查找
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="ele">查找的元素</param>
/// <returns>找到则返回相应位置（下标），未找到返回-1</returns>
template<class T>
int SequenceList<T>::Search(T ele) const
{
	for (int i = 0; i < length; i++)
		if (ele == data[i])
			return i;
	return -1;
}

template<class T>
void SequenceList<T>::Display() const
{
	for (int i = 0; i < length; i++)
		cout << data[i] << " ";
	cout << endl;
}
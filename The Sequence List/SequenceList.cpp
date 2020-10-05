#include "SequenceList.h"
#include <fstream>
using namespace std;

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
	if (size <= 0) {
		cerr << "内存分配大小错误!" << endl;
		return;
	}
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
/// 复制构造函数
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="L"></param>
template<class T>
SequenceList<T>::SequenceList(SequenceList<T>& L)
{
	this->length = L.length;
	this->maxSize = L.maxSize;
	this->data = new T[length];
	if (this->data == NULL) {
		cerr << "内存分配失败" << endl;
		exit(1);
	}
	for (int i = 0; i < length; i++)
		this->data[i] = L.data[i];
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
	return true;
}

/// <summary>
/// 在指定元素前插入元素
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="eleBefore">指定元素</param>
/// <param name="ele">要插入的元素</param>
/// <returns>是否插入成功</returns>
template<class T>
bool SequenceList<T>::InsertBefore(T eleBefore,T ele)
{
	int pos = Search(eleBefore);
	if (pos == -1)
		return false;
	return Insert(pos, ele);
}

/// <summary>
/// 在指定元素后插入元素
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="eleAfter">指定元素</param>
/// <param name="ele">插入元素</param>
/// <returns>是否插入成功</returns>
template<class T>
bool SequenceList<T>::InsertAfter(T eleAfter, T ele)
{
	int pos = Search(eleAfter);
	if (pos == -1)
		return false;
	return Insert(pos + 1, ele);
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

/// <summary>
/// 定位序号（下标+1)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="ele">定位的元素</param>
/// <returns>返回序号（下标+1）,不存在则返回0</returns>
template<class T>
int SequenceList<T>::Locate(T ele) const
{
	return Search(ele)+1;
}

template<class T>
void SequenceList<T>::Display() const
{
	for (int i = 0; i < length; i++)
		cout << data[i] << " ";
	cout << endl;
}

/// <summary>
/// 删除指定元素
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="ele">删除的元素</param>
/// <returns>是否删除成功</returns>
template<class T>
bool SequenceList<T>::Erase(T ele) 
{
	int pos = Search(ele);
	if (pos == -1)
		return false;
	for (int i = pos; i < length - 1; i++)
		data[i] = data[i + 1];
	length--;
	return true;
}

/// <summary>
/// 删除指定位置元素
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="pos">元素位置</param>
/// <returns>是否删除成功</returns>
template<class T>
bool SequenceList<T>::EraseByPos(int pos)
{
	if (pos < 0 || pos >= length)
		return false;
	for (int i = pos; i < length - 1; i++)
		data[i] = data[i + 1];
	length--;
	return true;
}

/// <summary>
/// 修改指定位置的元素
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="pos">指定位置</param>
/// <param name="ele">修改后的元素</param>
/// <returns>是否修改成功</returns>
template<class T>
bool SequenceList<T>::Modify(int pos, T ele)
{
	if (pos < 0 || pos >= length)
		return false;
	data[pos] = ele;
	return true;
}

/// <summary>
/// 将所有元素A改为元素B
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="A">改之前元素</param>
/// <param name="B">改之后元素</param>
template<class T>
void SequenceList<T>::ModifyAToB(T A, T B)
{
	for (int i = 0; i < length; i++)
		if (data[i] == A)
			data[i] = B;
}

/// <summary>
/// 
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="pos"></param>
/// <returns>指定位置元素</returns>
template<class T>
T SequenceList<T>::At(int pos) const
{
	if (pos < 0 || pos >= length) {
		cerr << "下标越界" << endl;
		exit(1);
	}
	return data[pos];
}

/// <summary>
/// 
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns>元素个数</returns>
template<class T>
int SequenceList<T>::Size() const
{
	return length;
}

/// <summary>
/// 
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns>目前所能容纳元素个数</returns>
template<class T>
int SequenceList<T>::Capacity() const
{
	return maxSize;
}

/// <summary>
/// 
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns>是否为空</returns>
template<class T>
bool SequenceList<T>::isEmpty() const
{
	return (length == 0);
}

/// <summary>
/// 清空顺序表
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
void SequenceList<T>::Clear()
{
	delete[] data;
	data = new T[maxSize];
	if (data == NULL) {
		cerr << "内存分配失败" << endl;
		exit(1);
	}
	length = 0;
}

/// <summary>
/// 查找元素个数
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="ele">要查询的元素</param>
/// <returns>元素个数</returns>
template<class T>
int SequenceList<T>::FindCount(T ele) const
{
	int count = 0;
	for (int i = 0; i < length; i++)
		if (data[i] == ele)
			count++;
	return count;
}

template<class T>
void SequenceList<T>::ReadFile(string fileName)
{
	ifstream f;
	f.open(fileName, ios::in);
	if (!f.is_open()) {
		cerr << "文件打开失败!" << endl;
		return;
	}

	int num = 0;   //文件数据个数(文件第一排)
	f >> num;

	T* newData = new T[num + sizeToAdd];
	if (newData == NULL) {
		cerr << "内存分配失败！" << endl;
		exit(1);
	}

	//读文件数据
	for (int i = 0; i < num; i++)
		f >> newData[i];

	f.close();

	delete[] data;
	data = newData;
	length = num;
	maxSize = num + sizeToAdd;
	sizeToAdd *= 2;
}

template<class T>
void SequenceList<T>::WirteFile(string fileName)
{
	ofstream f;
	f.open(fileName, ios::out);

	if (!f.is_open()) {
		cerr << "文件打开失败!" << endl;
		return;
	}

	f << length << endl;

	for (int i = 0; i < length; i++)
		f << data[i] << endl;

	f.close();
}


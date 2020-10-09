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
/// 判断排序类型
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
void SequenceList<T>::judgeSortType()
{
	if (length == 0) {
		sortType = SortType::None;
	}
	else if ((length == 1) || isAllEqual()) {  //元素为1 或者 所有元素相等
		sortType = SortType::Both;
	}
	else if (isIncrease()) {
		sortType = SortType::Increase;
	}
	else if (isDecrease()) {
		sortType = SortType::Decrease;
	}
	else {
		sortType = SortType::None;
	}
}

/// <summary>
/// 
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns>是否所有元素相等</returns>
template<class T>
bool SequenceList<T>::isAllEqual()
{
	if (length == 0)
		return false;

	for (int i = 1; i < length; i++)
		if (!(data[0] == data[i]))
			return false;
	return true;
}

/// <summary>
/// 
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns>是否为递增</returns>
template<class T>
bool SequenceList<T>::isIncrease()
{
	if (length == 0)
		return false;

	for (int i = 1; i < length; i++)
		if (data[i] < data[i - 1])
			return false;
	return true;
}

/// <summary>
/// 
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns>是否为递减</returns>
template<class T>
bool SequenceList<T>::isDecrease()
{
	if (length == 0)
		return false;

	for (int i = 1; i < length; i++)
		if (data[i] > data[i - 1])
			return false;
	return true;
}

/// <summary>
/// 插入后判断排序类型
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="pos"></param>
template<class T>
void SequenceList<T>::judgeSortAfterInsert(int pos)
{
	if (length == 1)
		sortType = SortType::Both;
	else if (sortType == SortType::None)  //原本无序，插入任然无序
		return;
	else if (isAllEqual())
		sortType = SortType::Both;
	else if (sortType = SortType::Increase) {   //递增时插入
		if ((pos == 0 && data[0] > data[1]) || (pos == length - 1 && data[pos] < data[pos - 1]))
			sortType = SortType::None;
		else if (data[pos] > data[pos + 1] || data[pos] < data[pos - 1])
			sortType = SortType::None;
		else
			return;
	}
	else if (sortType = SortType::Decrease) {   //递减时插入
		if ((pos == 0 && data[0] < data[1]) || (pos == length - 1 && data[pos] > data[pos - 1]))
			sortType = SortType::None;
		else if (data[pos] < data[pos + 1] || data[pos] > data[pos - 1])
			sortType = SortType::None;
		else
			return;
	}
}

/// <summary>
/// 二分法查找
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="ele"></param>
/// <returns></returns>
template<class T>
int SequenceList<T>::binarySearch(T ele) const
{
	if (sortType == SortType::Both) {
		if (data[0] == ele)
			return 0;
		else
			return -1;
	}
	if (sortType == SortType::Increase) {
		int left = 0, right = length - 1;
		int mid;
		while (left <= right) {
			mid = (left + right) / 2;
			if (ele == data[mid])
				return mid;
			if (ele > data[mid])
				left = mid + 1;
			else
				right = mid - 1;
		}
	}
	else if (sortType == SortType::Decrease) {
		int left = 0, right = length - 1;
		int mid;
		while (left < right) {
			mid = (left + right) / 2;
			if (ele == data[mid])
				return mid;
			if (ele > data[mid])
				right = mid + 1;
			else
				left = mid - 1;
		}
	}
	return -1;
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
	sortType = SortType::None;
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
	this->sortType = L.sortType;
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
	judgeSortAfterInsert(pos);  //判断排序类型
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
bool SequenceList<T>::InsertBefore(T eleBefore, T ele)
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
	if (length == 0)
		return -1;
	//有序时，使用二分法查找
	if (sortType == SortType::Increase || sortType == SortType::Decrease)
		return binarySearch(ele);

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
	return Search(ele) + 1;
}

template<class T>
void SequenceList<T>::Display() const
{
	if (length == 0) {
		cout << "元素为0" << endl;
		return;
	}
	for (int i = 0; i < length; i++)
		cout << data[i] << " ";
	cout << endl;
}

/// <summary>
/// 删除指定元素(所有)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="ele">删除的元素</param>
template<class T>
void SequenceList<T>::Erase(T ele)
{
	for (int i = 0; i < length; i++)
		if (data[i] == ele) {
			for (int j = i; j < length - 1; j++)
				data[j] = data[j + 1];
			length--;
			i--;
		}
	judgeSortType();
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

	if (length == 1 || length == 0 || isAllEqual() || sortType == SortType::None)
		judgeSortType();
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
	if (isAllEqual() || sortType == SortType::None)
		judgeSortType();
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
	if (isAllEqual() || sortType == SortType::None)
		judgeSortType();
}

/// <summary>
/// 排序（递增）
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
void SequenceList<T>::Sort()
{
	if (length == 0 || length == 1)
		return;
	T temp;
	for (int i = 0; i < length - 1; i++)
		for (int j = 0; j < length - 1; j++)
			if (data[j] > data[j + 1]) {
				temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
	if (isAllEqual())
		sortType = SortType::Both;
	else
		sortType = SortType::Increase;
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
	sortType = SortType::None;
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

/// <summary>
/// 读文件
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="fileName">文件名</param>
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
	judgeSortType();
}

/// <summary>
/// 写文件
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="fileName">文件名</param>
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


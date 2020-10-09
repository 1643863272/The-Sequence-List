#include "SequenceList.h"
#include <fstream>
using namespace std;

/// <summary>
/// ����
/// </summary>
/// <typeparam name="T"></typeparam>
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

/// <summary>
/// �ж���������
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
void SequenceList<T>::judgeSortType()
{
	if (length == 0) {
		sortType = SortType::None;
	}
	else if ((length == 1) || isAllEqual()) {  //Ԫ��Ϊ1 ���� ����Ԫ�����
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
/// <returns>�Ƿ�����Ԫ�����</returns>
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
/// <returns>�Ƿ�Ϊ����</returns>
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
/// <returns>�Ƿ�Ϊ�ݼ�</returns>
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
/// ������ж���������
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="pos"></param>
template<class T>
void SequenceList<T>::judgeSortAfterInsert(int pos)
{
	if (length == 1)
		sortType = SortType::Both;
	else if (sortType == SortType::None)  //ԭ�����򣬲�����Ȼ����
		return;
	else if (isAllEqual())
		sortType = SortType::Both;
	else if (sortType = SortType::Increase) {   //����ʱ����
		if ((pos == 0 && data[0] > data[1]) || (pos == length - 1 && data[pos] < data[pos - 1]))
			sortType = SortType::None;
		else if (data[pos] > data[pos + 1] || data[pos] < data[pos - 1])
			sortType = SortType::None;
		else
			return;
	}
	else if (sortType = SortType::Decrease) {   //�ݼ�ʱ����
		if ((pos == 0 && data[0] < data[1]) || (pos == length - 1 && data[pos] > data[pos - 1]))
			sortType = SortType::None;
		else if (data[pos] < data[pos + 1] || data[pos] > data[pos - 1])
			sortType = SortType::None;
		else
			return;
	}
}

/// <summary>
/// ���ַ�����
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
/// ���캯��
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="size">Ĭ������</param>
template<class T>
SequenceList<T>::SequenceList(int size)
{
	if (size <= 0) {
		cerr << "�ڴ�����С����!" << endl;
		return;
	}
	data = new T[size];
	if (data == NULL) {
		cerr << "�ڴ����ʧ�ܣ�" << endl;
		exit(1);
	}
	maxSize = size;
	length = 0;
	sizeToAdd = 2;
	sortType = SortType::None;
}

/// <summary>
/// ���ƹ��캯��
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
		cerr << "�ڴ����ʧ��" << endl;
		exit(1);
	}
	for (int i = 0; i < length; i++)
		this->data[i] = L.data[i];
}

/// <summary>
/// ��������
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
SequenceList<T>::~SequenceList()
{
	if (data != NULL)
		delete[] data;
}

/// <summary>
/// ��������
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="pos">����λ��(�±�)</param>
/// <param name="ele">����Ԫ��</param>
/// <returns>�Ƿ����ɹ�(bool)</returns>
template<class T>
bool SequenceList<T>::Insert(int pos, T ele)
{
	if (pos<0 || pos >length) {  //������Χ������ʧ��
		return false;
	}
	if (maxSize == length)   //�������㣬����
		resize();

	for (int i = length - 1; i >= pos; i--)  //����
		data[i + 1] = data[i];

	data[pos] = ele;
	length++;
	judgeSortAfterInsert(pos);  //�ж���������
	return true;
}

/// <summary>
/// ��ָ��Ԫ��ǰ����Ԫ��
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="eleBefore">ָ��Ԫ��</param>
/// <param name="ele">Ҫ�����Ԫ��</param>
/// <returns>�Ƿ����ɹ�</returns>
template<class T>
bool SequenceList<T>::InsertBefore(T eleBefore, T ele)
{
	int pos = Search(eleBefore);
	if (pos == -1)
		return false;
	return Insert(pos, ele);
}

/// <summary>
/// ��ָ��Ԫ�غ����Ԫ��
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="eleAfter">ָ��Ԫ��</param>
/// <param name="ele">����Ԫ��</param>
/// <returns>�Ƿ����ɹ�</returns>
template<class T>
bool SequenceList<T>::InsertAfter(T eleAfter, T ele)
{
	int pos = Search(eleAfter);
	if (pos == -1)
		return false;
	return Insert(pos + 1, ele);
}

/// <summary>
/// ��������Ԫ��
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="ele">Ҫ�����Ԫ��</param>
/// <returns>�Ƿ����ɹ�</returns>
template<class T>
bool SequenceList<T>::PushBack(T ele)
{
	return Insert(length, ele);
}

/// <summary>
/// ����
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="ele">���ҵ�Ԫ��</param>
/// <returns>�ҵ��򷵻���Ӧλ�ã��±꣩��δ�ҵ�����-1</returns>
template<class T>
int SequenceList<T>::Search(T ele) const
{
	if (length == 0)
		return -1;
	//����ʱ��ʹ�ö��ַ�����
	if (sortType == SortType::Increase || sortType == SortType::Decrease)
		return binarySearch(ele);

	for (int i = 0; i < length; i++)
		if (ele == data[i])
			return i;
	return -1;
}


/// <summary>
/// ��λ��ţ��±�+1)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="ele">��λ��Ԫ��</param>
/// <returns>������ţ��±�+1��,�������򷵻�0</returns>
template<class T>
int SequenceList<T>::Locate(T ele) const
{
	return Search(ele) + 1;
}

template<class T>
void SequenceList<T>::Display() const
{
	if (length == 0) {
		cout << "Ԫ��Ϊ0" << endl;
		return;
	}
	for (int i = 0; i < length; i++)
		cout << data[i] << " ";
	cout << endl;
}

/// <summary>
/// ɾ��ָ��Ԫ��(����)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="ele">ɾ����Ԫ��</param>
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
/// ɾ��ָ��λ��Ԫ��
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="pos">Ԫ��λ��</param>
/// <returns>�Ƿ�ɾ���ɹ�</returns>
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
/// �޸�ָ��λ�õ�Ԫ��
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="pos">ָ��λ��</param>
/// <param name="ele">�޸ĺ��Ԫ��</param>
/// <returns>�Ƿ��޸ĳɹ�</returns>
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
/// ������Ԫ��A��ΪԪ��B
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="A">��֮ǰԪ��</param>
/// <param name="B">��֮��Ԫ��</param>
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
/// ���򣨵�����
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
/// <returns>ָ��λ��Ԫ��</returns>
template<class T>
T SequenceList<T>::At(int pos) const
{
	if (pos < 0 || pos >= length) {
		cerr << "�±�Խ��" << endl;
		exit(1);
	}
	return data[pos];
}

/// <summary>
/// 
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns>Ԫ�ظ���</returns>
template<class T>
int SequenceList<T>::Size() const
{
	return length;
}

/// <summary>
/// 
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns>Ŀǰ��������Ԫ�ظ���</returns>
template<class T>
int SequenceList<T>::Capacity() const
{
	return maxSize;
}

/// <summary>
/// 
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns>�Ƿ�Ϊ��</returns>
template<class T>
bool SequenceList<T>::isEmpty() const
{
	return (length == 0);
}

/// <summary>
/// ���˳���
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
void SequenceList<T>::Clear()
{
	delete[] data;
	data = new T[maxSize];
	if (data == NULL) {
		cerr << "�ڴ����ʧ��" << endl;
		exit(1);
	}
	length = 0;
	sortType = SortType::None;
}

/// <summary>
/// ����Ԫ�ظ���
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="ele">Ҫ��ѯ��Ԫ��</param>
/// <returns>Ԫ�ظ���</returns>
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
/// ���ļ�
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="fileName">�ļ���</param>
template<class T>
void SequenceList<T>::ReadFile(string fileName)
{
	ifstream f;
	f.open(fileName, ios::in);
	if (!f.is_open()) {
		cerr << "�ļ���ʧ��!" << endl;
		return;
	}

	int num = 0;   //�ļ����ݸ���(�ļ���һ��)
	f >> num;

	T* newData = new T[num + sizeToAdd];
	if (newData == NULL) {
		cerr << "�ڴ����ʧ�ܣ�" << endl;
		exit(1);
	}

	//���ļ�����
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
/// д�ļ�
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="fileName">�ļ���</param>
template<class T>
void SequenceList<T>::WirteFile(string fileName)
{
	ofstream f;
	f.open(fileName, ios::out);

	if (!f.is_open()) {
		cerr << "�ļ���ʧ��!" << endl;
		return;
	}

	f << length << endl;

	for (int i = 0; i < length; i++)
		f << data[i] << endl;

	f.close();
}


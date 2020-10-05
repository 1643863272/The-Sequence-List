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
bool SequenceList<T>::InsertBefore(T eleBefore,T ele)
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
/// ɾ��ָ��Ԫ��
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="ele">ɾ����Ԫ��</param>
/// <returns>�Ƿ�ɾ���ɹ�</returns>
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
}

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


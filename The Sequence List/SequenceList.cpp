#include "SequenceList.h"

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
/// ��λλ�ã��±�+1)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="ele">��λ��Ԫ��</param>
/// <returns>����λ�ã��±�+1��,�������򷵻�0</returns>
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

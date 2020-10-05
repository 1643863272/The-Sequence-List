#pragma once
#include <iostream>
#include <string>
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
	SequenceList(SequenceList<T>& L);    //复制构造函数
	~SequenceList();  //析构函数

	bool Insert(int pos, T ele);  //插入
	bool InsertBefore(T eleBefore,T ele);     //在指定元素前插入
	bool InsertAfter(T eleAfter, T ele);      //在指定元素后插入
	bool PushBack(T ele);         //在最后插入

	int Search(T ele) const;      //查找
	int Locate(T ele) const;      //定位
	void Display() const;         //显示所有元素

	void Erase(T ele);            //删除指定元素（所有）
	bool EraseByPos(int pos);     //删除指定位置元素

	bool Modify(int pos, T ele);  //修改指定位置的元素
	void ModifyAToB(T A, T B);    //将所有的元素A改为元素B

	T At(int pos) const;     //返回指定位置元素
	int Size() const;        //返回元素个数
	int Capacity() const;    //返回目前所能容纳的元素数量
	bool isEmpty() const;    //是否为空
	void Clear();            //清空顺序表
	int FindCount(T ele) const;    //查找元素个数

	void ReadFile(string fileName);   //读取文件，将原本数据换为文件数据
	void WirteFile(string fileName);  //将数据写入文件(覆盖)

};

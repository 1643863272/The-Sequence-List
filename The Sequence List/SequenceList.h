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
	int Search(T ele) const;      //查找
	int Locate(T ele) const;      //定位      
	void Display() const;         //显示所有元素

};

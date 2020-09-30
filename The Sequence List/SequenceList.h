#pragma once
#include <iostream>
using namespace std;
template<class T>
class SequenceList
{
private:
	T* data;     //储存的核心数据
	int length;  //目前容量
	int maxSize; //最大容量
	const int static defaultSize = 64;  //默认容量
	int sizeToAdd;  //每次resize增加的容量(2、4、8、16....)

	void resize();

public:
	/// <summary>
	/// 构造函数
	/// </summary>
	/// <param name="size">默认内存大小</param>
	SequenceList(int size = defaultSize);
	~SequenceList();  //析构函数

	bool Insert(int pos, T ele);

};


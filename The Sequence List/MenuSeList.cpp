#include "MenuSeList.h"

void MenuSeList::Menu()
{
	while (true) {
		cout << "选择顺序表的类型" << endl;
		cout << "1. int类型" << endl;
		cout << "2. Student类型" << endl;
		cout << "0. 退出" << endl;
		cout << "输入你的选择:";

		char choice;
		cin >> choice;
		switch (choice)
		{
		case '0':
			exit(0);
			break;
		case '1':
			system("cls");
			MenuInt();
			break;
		case '2':
			system("cls");
			MenuStu();
			break;
		default:
			cout << "输入错误，请重新输入！" << endl;
			break;
		}
		system("pause");
		system("cls");
	}
}

void MenuSeList::MenuInt()
{
	while (true) {
		cout << "---int顺序表---" << endl;
		cout << "|1. 显示数据--|" << endl;
		cout << "|2. 插入数据--|" << endl;
		cout << "|3. 删除数据--|" << endl;
		cout << "|4. 搜索数据--|" << endl;
		cout << "|5. 递增排序--|" << endl;
		cout << "|6. 读取数据--|" << endl;
		cout << "|7. 储存数据--|" << endl;
		cout << "|0. 返回    --|" << endl;
		cout << "输入你的选择: ";
		char choice;
		cin >> choice;
		switch (choice)
		{
		case '0':
			return;
			break;
		case '1':
			system("cls");
			seListInt.Display();
			break;
		case '2':
			system("cls");
			IntInsert();
			break;
		case '3':
			system("cls");
			IntErase();
			break;
		case '4':
			system("cls");
			IntSearch();
			break;
		case '5':
			system("cls");
			seListInt.Sort();
			cout << "排序成功！" << endl;
			break;
		case '6':
			system("cls");
			IntReadFile();
			break;
		case '7':
			system("cls");
			IntWriteFile();
			break;
		default:
			system("cls");
			cout << "输入错误，请重新输入！" << endl;
			break;
		}
		system("pause");
		system("cls");
	}
}

void MenuSeList::IntInsert()
{
	while (true) {
		cout << "int 插入数据" << endl;
		cout << "1. 在指定元素前插入数据" << endl;
		cout << "2. 在指定元素后插入数据" << endl;
		cout << "3. 在指定位置插入数据" << endl;
		cout << "4. 添加元素（默认为最后位置)" << endl;
		cout << "0. 返回" << endl;
		cout << "输入你的选择：";

		char choice;
		cin >> choice;
		switch (choice)
		{
		case '0':
			return;
			break;
		case '1': {
			int beforeEle, insertEle;
			cout << "输入你想要插入前元素："; cin >> beforeEle;
			cout << "输入你想要插入元素："; cin >> insertEle;
			bool flag01 = seListInt.InsertBefore(beforeEle, insertEle);
			if (flag01 == true)
				cout << "插入成功!" << endl;
			else
				cout << "插入失败!" << endl;
			break;
		}
		case '2': {
			int afterEle, eleInsert;
			cout << "输入你想要插入后元素："; cin >> afterEle;
			cout << "输入你想要插入元素："; cin >> eleInsert;
			bool flag02 = seListInt.InsertAfter(afterEle, eleInsert);
			if (flag02 == true)
				cout << "插入成功!" << endl;
			else
				cout << "插入失败!" << endl;
			break;
		}
		case '3': {
			int pos, ele;
			cout << "输入你想要插入的位置(从1开始)："; cin >> pos;
			cout << "输入你想要插入元素："; cin >> ele;
			pos--;
			bool flag03 = seListInt.Insert(pos, ele);
			if (flag03 == true)
				cout << "插入成功!" << endl;
			else
				cout << "插入失败!" << endl;
			break;
		}
		case '4': {
			int elee;
			cout << "输入你要添加的元素:"; cin >> elee;
			bool flag04 = seListInt.PushBack(elee);
			if (flag04 == true)
				cout << "插入成功!" << endl;
			else
				cout << "插入失败!" << endl;
			break;
		}
		default:
			cout << "输入错误，请重新输入！" << endl;
			break;
		}
		system("pause");
		system("cls");
		if (choice == '1' || choice == '2' || choice == '3')
			return;
	}
}

void MenuSeList::IntErase()
{
	while (true) {
		cout << "int 删除数据" << endl;
		cout << "1. 删除指定元素(所有)" << endl;
		cout << "2. 删除指定位置元素" << endl;
		cout << "0. 返回" << endl;
		cout << "输入你的选择：";

		char choice;
		cin >> choice;
		switch (choice)
		{
		case '0':
			return;
			break;
		case '1': {
			int eleErase;
			cout << "输入你想要删除的元素:"; cin >> eleErase;
			seListInt.Erase(eleErase);
			cout << "删除成功！（无该元素则不删除)" << endl;
			break;
		}
		case '2': {
			int poss;
			cout << "输入你想删除的元素序号(从1开始):"; cin >> poss;
			poss--;
			bool flag01 = seListInt.EraseByPos(poss);
			if (flag01 == true)
				cout << "删除成功！" << endl;
			else
				cout << "删除失败！" << endl;
			break;
		}
		default:
			cout << "输入错误，请重新输入！" << endl;
			break;
		}
		system("pause");
		system("cls");
		if (choice == '1' || choice == '2')
			return;
	}
}

void MenuSeList::IntSearch()
{
	while (true) {
		cout << "int 查询数据" << endl;
		cout << "1. 查找某元素位置" << endl;
		cout << "2. 修改指定位置元素" << endl;
		cout << "3. 将所有元素A改为B" << endl;
		cout << "0. 返回" << endl;
		cout << "输入你的选择：";

		char choice;
		cin >> choice;
		switch (choice)
		{
		case '0':
			return;
			break;
		case '1': {
			int ele;
			cout << "输入你想查询的元素:"; cin >> ele;
			int pos = seListInt.Locate(ele);
			if (pos == 0)
				cout << "未找到该元素" << endl;
			else
				cout << "该元素位置为:" << pos << endl;
			break;
		}
		case '2': {
			int posToMo;
			int eleAfterMo;
			cout << "输入你要修改的元素位置:"; cin >> posToMo;
			cout << "输入你要修改为的元素:"; cin >> eleAfterMo;
			bool flag01 = seListInt.Modify(posToMo, eleAfterMo);
			if (flag01 == true)
				cout << "修改成功" << endl;
			else
				cout << "修改失败" << endl;
			break;
		}
		case '3': {
			int eleA, eleB;
			cout << "输入修改前的元素A:"; cin >> eleA;
			cout << "输入修改后的元素B:"; cin >> eleB;
			seListInt.ModifyAToB(eleA, eleB);
			cout << "修改成功!(无A元素则不修改)" << endl;
			break;
		}
		default:
			cout << "输入错误，请重新输入！" << endl;
			break;
		}
		system("pause");
		system("cls");
		if (choice == '1' || choice == '2' || choice == '3')
			return;
	}
}

void MenuSeList::IntReadFile()
{
	string fileName;
	cout << "输入你要读取的文件名（绝对路径):"; cin >> fileName;
	seListInt.ReadFile(fileName);
	cout << "读取成功（请确认文件里为int数据)" << endl;
}

void MenuSeList::IntWriteFile()
{
	string fileName;
	cout << "输入你要写入的文件名（绝对路径):"; cin >> fileName;
	seListInt.WirteFile(fileName);
	cout << "写入成功" << endl;
}

void MenuSeList::MenuStu()
{
	while (true) {
		cout << "---Stu顺序表---" << endl;
		cout << "|1. 显示数据--|" << endl;
		cout << "|2. 插入数据--|" << endl;
		cout << "|3. 删除数据--|" << endl;
		cout << "|4. 搜索数据--|" << endl;
		cout << "|5. 递增排序--|" << endl;
		cout << "|6. 读取数据--|" << endl;
		cout << "|7. 储存数据--|" << endl;
		cout << "|0. 返回    --|" << endl;
		cout << "输入你的选择: ";
		char choice;
		cin >> choice;
		switch (choice)
		{
		case '0':
			return;
			break;
		case '1':
			system("cls");
			cout << "一共有" << seListStu.Size() << "名学生" << endl;
			cout << "姓名  学号  年龄" << endl;
			seListStu.Display();
			break;
		case '2':
			system("cls");
			StuInsert();
			break;
		case '3':
			system("cls");
			StuErase();
			break;
		case '4':
			system("cls");
			StuSearch();
			break;
		case '5':
			system("cls");
			seListStu.Sort();
			cout << "排序成功！" << endl;
			break;
		case '6':
			system("cls");
			StuReadFile();
			break;
		case '7':
			system("cls");
			StuWriteFile();
			break;
		default:
			system("cls");
			cout << "输入错误，请重新输入！" << endl;
			break;
		}
		system("pause");
		system("cls");
	}
}

void MenuSeList::StuInsert()
{
	while (true) {
		cout << "Stu 插入数据" << endl;
		cout << "1. 在指定元素前插入数据" << endl;
		cout << "2. 在指定元素后插入数据" << endl;
		cout << "3. 在指定位置插入数据" << endl;
		cout << "4. 添加元素（默认为最后位置）" << endl;
		cout << "0. 返回" << endl;
		cout << "输入你的选择：";

		char choice;
		cin >> choice;
		switch (choice)
		{
		case '0':
			return;
			break;
		case '1': {
			Student beforeEle("11"), insertEle("11");
			Student s();
			cout << "输入你想要插入的前元素：" << endl; beforeEle.Input();
			cout << "输入你想要插入元素：" << endl; insertEle.Input();;
			bool flag01 = seListStu.InsertBefore(beforeEle, insertEle);
			if (flag01 == true)
				cout << "插入成功!" << endl;
			else
				cout << "插入失败!" << endl;
			break;
		}
		case '2': {
			Student afterEle(""), eleInsert("");
			cout << "输入你想要插入后元素：" << endl; afterEle.Input();
			cout << "输入你想要插入元素：" << endl; eleInsert.Input();
			bool flag02 = seListStu.InsertAfter(afterEle, eleInsert);
			if (flag02 == true)
				cout << "插入成功!" << endl;
			else
				cout << "插入失败!" << endl;
			break;
		}
		case '3': {
			int pos;
			Student	ele("");
			cout << "输入你想要插入的位置(从1开始)："; cin >> pos;
			cout << "输入你想要插入元素：" << endl; ele.Input();
			pos--;
			bool flag03 = seListStu.Insert(pos, ele);
			if (flag03 == true)
				cout << "插入成功!" << endl;
			else
				cout << "插入失败!" << endl;
			break;
		}
		case '4': {
			Student elee("");
			cout << "输入你要添加的元素:" << endl; elee.Input();
			bool flag04 = seListStu.PushBack(elee);
			if (flag04 == true)
				cout << "添加成功" << endl;
			else
				cout << "添加失败" << endl;
			break;
		}
		default:
			cout << "输入错误，请重新输入！" << endl;
			break;
		}
		system("pause");
		system("cls");
		if (choice == '1' || choice == '2' || choice == '3')
			return;
	}
}

void MenuSeList::StuErase()
{
	while (true) {
		cout << "Stu 删除数据" << endl;
		cout << "1. 删除指定元素(所有)" << endl;
		cout << "2. 删除指定位置元素" << endl;
		cout << "0. 返回" << endl;
		cout << "输入你的选择：";

		char choice;
		cin >> choice;
		switch (choice)
		{
		case '0':
			return;
			break;
		case '1': {
			Student eleErase("");
			cout << "输入你想要删除的元素:" << endl; eleErase.Input();
			seListStu.Erase(eleErase);
			cout << "删除成功！（无该元素则不删除)" << endl;
			break;
		}
		case '2': {
			int poss;
			cout << "输入你想删除的元素序号(从1开始):"; cin >> poss;
			poss--;
			bool flag01 = seListStu.EraseByPos(poss);
			if (flag01 == true)
				cout << "删除成功！" << endl;
			else
				cout << "删除失败！" << endl;
			break;
		}
		default:
			cout << "输入错误，请重新输入！" << endl;
			break;
		}
		system("pause");
		system("cls");
		if (choice == '1' || choice == '2')
			return;
	}
}

void MenuSeList::StuSearch()
{
	while (true) {
		cout << "Stu 查询数据" << endl;
		cout << "1. 查找某元素位置" << endl;
		cout << "2. 修改指定位置元素" << endl;
		cout << "3. 将所有元素A改为B" << endl;
		cout << "0. 返回" << endl;
		cout << "输入你的选择：";

		char choice;
		cin >> choice;
		switch (choice)
		{
		case '0':
			return;
			break;
		case '1': {
			Student ele("");
			cout << "输入你想查询的元素:" << endl; ele.Input();
			int pos = seListStu.Locate(ele);
			if (pos == 0)
				cout << "未找到该元素" << endl;
			else
				cout << "该元素位置为:" << pos << endl;
			break;
		}
		case '2': {
			int posToMo;
			Student eleAfterMo("");
			cout << "输入你要修改的元素位置:"; cin >> posToMo;
			cout << "输入你要修改为的元素:" << endl; eleAfterMo.Input();
			bool flag01 = seListStu.Modify(posToMo, eleAfterMo);
			if (flag01 == true)
				cout << "修改成功" << endl;
			else
				cout << "修改失败" << endl;
			break;
		}
		case '3': {
			Student eleA(""), eleB("");
			cout << "输入修改前的元素A:" << endl; eleA.Input();
			cout << "输入修改后的元素B:" << endl; eleB.Input();
			seListStu.ModifyAToB(eleA, eleB);
			cout << "修改成功!(无A元素则不修改)" << endl;
			break;
		}
		default:
			cout << "输入错误，请重新输入！" << endl;
			break;
		}
		system("pause");
		system("cls");
		if (choice == '1' || choice == '2' || choice == '3')
			return;
	}
}

void MenuSeList::StuReadFile()
{
	string fileName;
	cout << "输入你要读取的文件名（绝对路径):"; cin >> fileName;
	seListStu.ReadFile(fileName);
	cout << "读取成功（请确认文件里为Student数据)" << endl;
}

void MenuSeList::StuWriteFile()
{
	string fileName;
	cout << "输入你要写入的文件名（绝对路径):"; cin >> fileName;
	seListStu.WirteFile(fileName);
	cout << "写入成功" << endl;
}

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

			break;
		case '2':

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
	SequenceList<int> seListInt;
	while (true) {
		cout << "---int顺序表---" << endl;
		cout << "|1. 显示数据--|" << endl;
		cout << "|2. 插入数据--|" << endl;
		cout << "|3. 删除数据--|" << endl;
		cout << "|4. 搜索数据--|" << endl;
		cout << "|5. 读取数据--|" << endl;
		cout << "|6. 储存数据--|" << endl;
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
			seListInt.Display();
			break;
		case '2':
			IntInsert();
			break;
		case '3':
			IntErase();
			break;
		case '4':

			break;
		case '5':

			break;
		case '6':

			break;
		default:
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
		cout << "0. 返回" << endl;
		cout << "输入你的选择：";

		char choice;
		cin >> choice;
		switch (choice)
		{
		case '0':
			return;
			break;
		case '1':
			int beforeEle, insertEle;
			cout << "输入你想要插入前元素："; cin >> beforeEle;
			cout << "输入你想要插入元素："; cin >> insertEle;
			bool flag01 = seListInt.InsertBefore(beforeEle, insertEle);
			if (flag01 == true)
				cout << "插入成功!" << endl;
			else
				cout << "插入失败!" << endl;
			break;
		case '2':
			int afterEle, eleInsert;
			cout << "输入你想要插入后元素："; cin >> afterEle;
			cout << "输入你想要插入元素："; cin >> eleInsert;
			bool flag02 = seListInt.InsertAfter(afterEle, eleInsert);
			if (flag02 == true)
				cout << "插入成功!" << endl;
			else
				cout << "插入失败!" << endl;
			break;
		case '3':
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
		case '1':
			int eleErase;
			cout << "输入你想要删除的元素:"; cin >> eleErase;
			seListInt.Erase(eleErase);
			cout << "删除成功！（无该元素则不删除)" << endl;
			break;
		case '2':
			int poss;
			cout << "输入你想删除的元素序号(从1开始):"; cin >> poss;
			poss--;
			bool flag01 = seListInt.EraseByPos(poss);
			if (flag01 == true)
				cout << "删除成功！" << endl;
			else
				cout << "删除失败！" << endl;
			break;
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
		case '1':
			int eleErase;
			cout << "输入你想要删除的元素:"; cin >> eleErase;
			seListInt.Erase(eleErase);
			cout << "删除成功！（无该元素则不删除)" << endl;
			break;
		case '2':
			int poss;
			cout << "输入你想删除的元素序号(从1开始):"; cin >> poss;
			poss--;
			bool flag01 = seListInt.EraseByPos(poss);
			if (flag01 == true)
				cout << "删除成功！" << endl;
			else
				cout << "删除失败！" << endl;
			break;
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

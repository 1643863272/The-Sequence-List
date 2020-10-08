#include "MenuSeList.h"

void MenuSeList::Menu()
{
	while (true) {
		cout << "ѡ��˳��������" << endl;
		cout << "1. int����" << endl;
		cout << "2. Student����" << endl;
		cout << "0. �˳�" << endl;
		cout << "�������ѡ��:";

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
			cout << "����������������룡" << endl;
			break;
		}
		system("pause");
		system("cls");
	}
}

void MenuSeList::MenuInt()
{
	while (true) {
		cout << "---int˳���---" << endl;
		cout << "|1. ��ʾ����--|" << endl;
		cout << "|2. ��������--|" << endl;
		cout << "|3. ɾ������--|" << endl;
		cout << "|4. ��������--|" << endl;
		cout << "|5. ��������--|" << endl;
		cout << "|6. ��ȡ����--|" << endl;
		cout << "|7. ��������--|" << endl;
		cout << "|0. ����    --|" << endl;
		cout << "�������ѡ��: ";
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
			cout << "����ɹ���" << endl;
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
			cout << "����������������룡" << endl;
			break;
		}
		system("pause");
		system("cls");
	}
}

void MenuSeList::IntInsert()
{
	while (true) {
		cout << "int ��������" << endl;
		cout << "1. ��ָ��Ԫ��ǰ��������" << endl;
		cout << "2. ��ָ��Ԫ�غ��������" << endl;
		cout << "3. ��ָ��λ�ò�������" << endl;
		cout << "4. ���Ԫ�أ�Ĭ��Ϊ���λ��)" << endl;
		cout << "0. ����" << endl;
		cout << "�������ѡ��";

		char choice;
		cin >> choice;
		switch (choice)
		{
		case '0':
			return;
			break;
		case '1': {
			int beforeEle, insertEle;
			cout << "��������Ҫ����ǰԪ�أ�"; cin >> beforeEle;
			cout << "��������Ҫ����Ԫ�أ�"; cin >> insertEle;
			bool flag01 = seListInt.InsertBefore(beforeEle, insertEle);
			if (flag01 == true)
				cout << "����ɹ�!" << endl;
			else
				cout << "����ʧ��!" << endl;
			break;
		}
		case '2': {
			int afterEle, eleInsert;
			cout << "��������Ҫ�����Ԫ�أ�"; cin >> afterEle;
			cout << "��������Ҫ����Ԫ�أ�"; cin >> eleInsert;
			bool flag02 = seListInt.InsertAfter(afterEle, eleInsert);
			if (flag02 == true)
				cout << "����ɹ�!" << endl;
			else
				cout << "����ʧ��!" << endl;
			break;
		}
		case '3': {
			int pos, ele;
			cout << "��������Ҫ�����λ��(��1��ʼ)��"; cin >> pos;
			cout << "��������Ҫ����Ԫ�أ�"; cin >> ele;
			pos--;
			bool flag03 = seListInt.Insert(pos, ele);
			if (flag03 == true)
				cout << "����ɹ�!" << endl;
			else
				cout << "����ʧ��!" << endl;
			break;
		}
		case '4': {
			int elee;
			cout << "������Ҫ��ӵ�Ԫ��:"; cin >> elee;
			bool flag04 = seListInt.PushBack(elee);
			if (flag04 == true)
				cout << "����ɹ�!" << endl;
			else
				cout << "����ʧ��!" << endl;
			break;
		}
		default:
			cout << "����������������룡" << endl;
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
		cout << "int ɾ������" << endl;
		cout << "1. ɾ��ָ��Ԫ��(����)" << endl;
		cout << "2. ɾ��ָ��λ��Ԫ��" << endl;
		cout << "0. ����" << endl;
		cout << "�������ѡ��";

		char choice;
		cin >> choice;
		switch (choice)
		{
		case '0':
			return;
			break;
		case '1': {
			int eleErase;
			cout << "��������Ҫɾ����Ԫ��:"; cin >> eleErase;
			seListInt.Erase(eleErase);
			cout << "ɾ���ɹ������޸�Ԫ����ɾ��)" << endl;
			break;
		}
		case '2': {
			int poss;
			cout << "��������ɾ����Ԫ�����(��1��ʼ):"; cin >> poss;
			poss--;
			bool flag01 = seListInt.EraseByPos(poss);
			if (flag01 == true)
				cout << "ɾ���ɹ���" << endl;
			else
				cout << "ɾ��ʧ�ܣ�" << endl;
			break;
		}
		default:
			cout << "����������������룡" << endl;
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
		cout << "int ��ѯ����" << endl;
		cout << "1. ����ĳԪ��λ��" << endl;
		cout << "2. �޸�ָ��λ��Ԫ��" << endl;
		cout << "3. ������Ԫ��A��ΪB" << endl;
		cout << "0. ����" << endl;
		cout << "�������ѡ��";

		char choice;
		cin >> choice;
		switch (choice)
		{
		case '0':
			return;
			break;
		case '1': {
			int ele;
			cout << "���������ѯ��Ԫ��:"; cin >> ele;
			int pos = seListInt.Locate(ele);
			if (pos == 0)
				cout << "δ�ҵ���Ԫ��" << endl;
			else
				cout << "��Ԫ��λ��Ϊ:" << pos << endl;
			break;
		}
		case '2': {
			int posToMo;
			int eleAfterMo;
			cout << "������Ҫ�޸ĵ�Ԫ��λ��:"; cin >> posToMo;
			cout << "������Ҫ�޸�Ϊ��Ԫ��:"; cin >> eleAfterMo;
			bool flag01 = seListInt.Modify(posToMo, eleAfterMo);
			if (flag01 == true)
				cout << "�޸ĳɹ�" << endl;
			else
				cout << "�޸�ʧ��" << endl;
			break;
		}
		case '3': {
			int eleA, eleB;
			cout << "�����޸�ǰ��Ԫ��A:"; cin >> eleA;
			cout << "�����޸ĺ��Ԫ��B:"; cin >> eleB;
			seListInt.ModifyAToB(eleA, eleB);
			cout << "�޸ĳɹ�!(��AԪ�����޸�)" << endl;
			break;
		}
		default:
			cout << "����������������룡" << endl;
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
	cout << "������Ҫ��ȡ���ļ���������·��):"; cin >> fileName;
	seListInt.ReadFile(fileName);
	cout << "��ȡ�ɹ�����ȷ���ļ���Ϊint����)" << endl;
}

void MenuSeList::IntWriteFile()
{
	string fileName;
	cout << "������Ҫд����ļ���������·��):"; cin >> fileName;
	seListInt.WirteFile(fileName);
	cout << "д��ɹ�" << endl;
}

void MenuSeList::MenuStu()
{
	while (true) {
		cout << "---Stu˳���---" << endl;
		cout << "|1. ��ʾ����--|" << endl;
		cout << "|2. ��������--|" << endl;
		cout << "|3. ɾ������--|" << endl;
		cout << "|4. ��������--|" << endl;
		cout << "|5. ��������--|" << endl;
		cout << "|6. ��ȡ����--|" << endl;
		cout << "|7. ��������--|" << endl;
		cout << "|0. ����    --|" << endl;
		cout << "�������ѡ��: ";
		char choice;
		cin >> choice;
		switch (choice)
		{
		case '0':
			return;
			break;
		case '1':
			system("cls");
			cout << "һ����" << seListStu.Size() << "��ѧ��" << endl;
			cout << "����  ѧ��  ����" << endl;
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
			cout << "����ɹ���" << endl;
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
			cout << "����������������룡" << endl;
			break;
		}
		system("pause");
		system("cls");
	}
}

void MenuSeList::StuInsert()
{
	while (true) {
		cout << "Stu ��������" << endl;
		cout << "1. ��ָ��Ԫ��ǰ��������" << endl;
		cout << "2. ��ָ��Ԫ�غ��������" << endl;
		cout << "3. ��ָ��λ�ò�������" << endl;
		cout << "4. ���Ԫ�أ�Ĭ��Ϊ���λ�ã�" << endl;
		cout << "0. ����" << endl;
		cout << "�������ѡ��";

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
			cout << "��������Ҫ�����ǰԪ�أ�" << endl; beforeEle.Input();
			cout << "��������Ҫ����Ԫ�أ�" << endl; insertEle.Input();;
			bool flag01 = seListStu.InsertBefore(beforeEle, insertEle);
			if (flag01 == true)
				cout << "����ɹ�!" << endl;
			else
				cout << "����ʧ��!" << endl;
			break;
		}
		case '2': {
			Student afterEle(""), eleInsert("");
			cout << "��������Ҫ�����Ԫ�أ�" << endl; afterEle.Input();
			cout << "��������Ҫ����Ԫ�أ�" << endl; eleInsert.Input();
			bool flag02 = seListStu.InsertAfter(afterEle, eleInsert);
			if (flag02 == true)
				cout << "����ɹ�!" << endl;
			else
				cout << "����ʧ��!" << endl;
			break;
		}
		case '3': {
			int pos;
			Student	ele("");
			cout << "��������Ҫ�����λ��(��1��ʼ)��"; cin >> pos;
			cout << "��������Ҫ����Ԫ�أ�" << endl; ele.Input();
			pos--;
			bool flag03 = seListStu.Insert(pos, ele);
			if (flag03 == true)
				cout << "����ɹ�!" << endl;
			else
				cout << "����ʧ��!" << endl;
			break;
		}
		case '4': {
			Student elee("");
			cout << "������Ҫ��ӵ�Ԫ��:" << endl; elee.Input();
			bool flag04 = seListStu.PushBack(elee);
			if (flag04 == true)
				cout << "��ӳɹ�" << endl;
			else
				cout << "���ʧ��" << endl;
			break;
		}
		default:
			cout << "����������������룡" << endl;
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
		cout << "Stu ɾ������" << endl;
		cout << "1. ɾ��ָ��Ԫ��(����)" << endl;
		cout << "2. ɾ��ָ��λ��Ԫ��" << endl;
		cout << "0. ����" << endl;
		cout << "�������ѡ��";

		char choice;
		cin >> choice;
		switch (choice)
		{
		case '0':
			return;
			break;
		case '1': {
			Student eleErase("");
			cout << "��������Ҫɾ����Ԫ��:" << endl; eleErase.Input();
			seListStu.Erase(eleErase);
			cout << "ɾ���ɹ������޸�Ԫ����ɾ��)" << endl;
			break;
		}
		case '2': {
			int poss;
			cout << "��������ɾ����Ԫ�����(��1��ʼ):"; cin >> poss;
			poss--;
			bool flag01 = seListStu.EraseByPos(poss);
			if (flag01 == true)
				cout << "ɾ���ɹ���" << endl;
			else
				cout << "ɾ��ʧ�ܣ�" << endl;
			break;
		}
		default:
			cout << "����������������룡" << endl;
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
		cout << "Stu ��ѯ����" << endl;
		cout << "1. ����ĳԪ��λ��" << endl;
		cout << "2. �޸�ָ��λ��Ԫ��" << endl;
		cout << "3. ������Ԫ��A��ΪB" << endl;
		cout << "0. ����" << endl;
		cout << "�������ѡ��";

		char choice;
		cin >> choice;
		switch (choice)
		{
		case '0':
			return;
			break;
		case '1': {
			Student ele("");
			cout << "���������ѯ��Ԫ��:" << endl; ele.Input();
			int pos = seListStu.Locate(ele);
			if (pos == 0)
				cout << "δ�ҵ���Ԫ��" << endl;
			else
				cout << "��Ԫ��λ��Ϊ:" << pos << endl;
			break;
		}
		case '2': {
			int posToMo;
			Student eleAfterMo("");
			cout << "������Ҫ�޸ĵ�Ԫ��λ��:"; cin >> posToMo;
			cout << "������Ҫ�޸�Ϊ��Ԫ��:" << endl; eleAfterMo.Input();
			bool flag01 = seListStu.Modify(posToMo, eleAfterMo);
			if (flag01 == true)
				cout << "�޸ĳɹ�" << endl;
			else
				cout << "�޸�ʧ��" << endl;
			break;
		}
		case '3': {
			Student eleA(""), eleB("");
			cout << "�����޸�ǰ��Ԫ��A:" << endl; eleA.Input();
			cout << "�����޸ĺ��Ԫ��B:" << endl; eleB.Input();
			seListStu.ModifyAToB(eleA, eleB);
			cout << "�޸ĳɹ�!(��AԪ�����޸�)" << endl;
			break;
		}
		default:
			cout << "����������������룡" << endl;
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
	cout << "������Ҫ��ȡ���ļ���������·��):"; cin >> fileName;
	seListStu.ReadFile(fileName);
	cout << "��ȡ�ɹ�����ȷ���ļ���ΪStudent����)" << endl;
}

void MenuSeList::StuWriteFile()
{
	string fileName;
	cout << "������Ҫд����ļ���������·��):"; cin >> fileName;
	seListStu.WirteFile(fileName);
	cout << "д��ɹ�" << endl;
}

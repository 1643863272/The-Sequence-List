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

			break;
		case '2':

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
	SequenceList<int> seListInt;
	while (true) {
		cout << "---int˳���---" << endl;
		cout << "|1. ��ʾ����--|" << endl;
		cout << "|2. ��������--|" << endl;
		cout << "|3. ɾ������--|" << endl;
		cout << "|4. ��������--|" << endl;
		cout << "|5. ��ȡ����--|" << endl;
		cout << "|6. ��������--|" << endl;
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
		cout << "0. ����" << endl;
		cout << "�������ѡ��";

		char choice;
		cin >> choice;
		switch (choice)
		{
		case '0':
			return;
			break;
		case '1':
			int beforeEle, insertEle;
			cout << "��������Ҫ����ǰԪ�أ�"; cin >> beforeEle;
			cout << "��������Ҫ����Ԫ�أ�"; cin >> insertEle;
			bool flag01 = seListInt.InsertBefore(beforeEle, insertEle);
			if (flag01 == true)
				cout << "����ɹ�!" << endl;
			else
				cout << "����ʧ��!" << endl;
			break;
		case '2':
			int afterEle, eleInsert;
			cout << "��������Ҫ�����Ԫ�أ�"; cin >> afterEle;
			cout << "��������Ҫ����Ԫ�أ�"; cin >> eleInsert;
			bool flag02 = seListInt.InsertAfter(afterEle, eleInsert);
			if (flag02 == true)
				cout << "����ɹ�!" << endl;
			else
				cout << "����ʧ��!" << endl;
			break;
		case '3':
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
		case '1':
			int eleErase;
			cout << "��������Ҫɾ����Ԫ��:"; cin >> eleErase;
			seListInt.Erase(eleErase);
			cout << "ɾ���ɹ������޸�Ԫ����ɾ��)" << endl;
			break;
		case '2':
			int poss;
			cout << "��������ɾ����Ԫ�����(��1��ʼ):"; cin >> poss;
			poss--;
			bool flag01 = seListInt.EraseByPos(poss);
			if (flag01 == true)
				cout << "ɾ���ɹ���" << endl;
			else
				cout << "ɾ��ʧ�ܣ�" << endl;
			break;
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
		case '1':
			int eleErase;
			cout << "��������Ҫɾ����Ԫ��:"; cin >> eleErase;
			seListInt.Erase(eleErase);
			cout << "ɾ���ɹ������޸�Ԫ����ɾ��)" << endl;
			break;
		case '2':
			int poss;
			cout << "��������ɾ����Ԫ�����(��1��ʼ):"; cin >> poss;
			poss--;
			bool flag01 = seListInt.EraseByPos(poss);
			if (flag01 == true)
				cout << "ɾ���ɹ���" << endl;
			else
				cout << "ɾ��ʧ�ܣ�" << endl;
			break;
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

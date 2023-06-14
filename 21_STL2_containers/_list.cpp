#include <iostream>
#include <list>
using namespace std;
typedef list<int> ourList;
void ShowLists(ourList &l1, ourList &l2)
{
	//������� ��������.
	ourList::iterator iter;
	cout << "list1: ";
	for (iter = l1.begin(); iter != l1.end(); iter++)
	{
		//������� ������� �� ������� ��������� ��������
		cout << *iter << " ";
	}
	cout << endl
		 << "list2: ";
	for (iter = l2.begin(); iter != l2.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl
		 << endl;
}
void main()
{
	//�������� ���� ������ �������
	ourList list1, list2;
	//���������� ����� ������� ����������
	for (int i = 0; i < 6; ++i)
	{
		list1.push_back(i);
		list2.push_front(i);
	}
	//����� ������� �� �����
	ShowLists(list1, list2);
	//�� ������ ������ �����������
	//������� �������� � �����
	list2.splice(list2.end(),	//������� � ��������
				 list2,			 //��������
				 list2.begin()); //������� � ���������
	//"��������������" ������ ������
	list1.reverse();
	ShowLists(list1, list2);
	//���������� ����� �������
	list1.sort();
	list2.sort();
	ShowLists(list1, list2);
	//������� ��� ��������������� ������
	//� ������ �������
	list1.merge(list2);
	ShowLists(list1, list2);
	//������� ��������� �� ������� ������
	list1.unique();
	ShowLists(list1, list2);
}
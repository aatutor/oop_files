#include <iostream>
#include <map> //map,multimap -- ����������,
//����������������� (�����������
//� ������������)
#include <string>
using namespace std;
//��������� ������� ��� ������ ����������� ����������
//��� ����������������� �� �����
template <class container>
void show(container col)
{
	for (container::const_iterator i = col.begin();
		 i != col.end(); ++i)
	{
		cout << i->first << '\t' << i->second << endl;
	}
	cout << endl
		 << endl;
}
void main()
{
	cout << "map\n\n";
	//������� ������ ��������� (�����������)
	map<string, int> cont;
	//������� ������ ��������� (�����������������)
	multimap<string, int> multicont;
	//��������� ��� ���� � �����������
	cont.insert(pair<string, int>("Ivanov", 10));
	cont.insert(pair<string, int>("Petrov", 20));
	//��������� ���� "Sidorov, 30"
	cont["Sidorov"] = 30;
	show(cont);
	//��������� �������� � ���� � ������ "Ivanov"
	cont["Ivanov"] = 50;
	show(cont);
	//������� �� ���������, �.�. ����
	//� ������ "Ivanov" ��� ����������
	cont.insert(pair<string, int>("Ivanov", 100));
	show(cont);
	/////////////////////////////////////////////////
	cout << "------------------------\nmultimap\n\n";
	multicont.insert(pair<string, int>("Ivanov", 10));
	multicont.insert(pair<string, int>("Petrov", 20));
	multicont.insert(pair<string, int>("Sidorov", 20));
	//��� ������ ����������� �� ��������� �������� "[]"
	//multicont["Sidorov"] = 30; //Error
	show(multicont);
	//��������� ���� ("Ivanov",100)
	multicont.insert(pair<string, int>("Ivanov", 100));
	show(multicont);
	//���� ������ ��������� �������� � ������ "Petrov"
	multimap<string, int>::iterator iter =
		multicont.find("Petrov");
	cout << iter->first << '\t' << iter->second
		 << endl
		 << endl;
	cout << "Count of key \"Ivanov\" in multimap = "
		 << multicont.count("Ivanov") << endl;
	//���������� ��������, ����������� �� ������ ���������
	//������� ����� ��� �� ����� �����������
	//� ������ ����������
	iter = multicont.lower_bound("Ivanov");
	for (; iter != multicont.upper_bound("Ivanov") && iter != multicont.end(); iter++)
	{
		cout << iter->first << '\t' << iter->second << endl;
	}
	cout << endl << endl;
}
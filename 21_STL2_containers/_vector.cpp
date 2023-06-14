#include <iostream>
#include <vector>
using namespace std;

void main()
{
	//������� ������
	vector<int> vect;
	cout << "\nNumber of elements that could be
		stored in the vector without "
		 << "allocating more storage --> "
		 << vect.capacity();
	cout << "\n-----------------------------------";
	//��������� ����� size() �������� ������� ���-��
	//��������� � �������.
	cout << "\nThe number of elements in the vector --> " << vect.size();
	cout << "\n-----------------------------------";
	vect.resize(4, 0); //�������� ������, �����
	//�������� ���������� ������
	cout << "\nResizing...\n";
	cout << "The number of elements in
			the vector-- >
		" << vect.size() << endl;
			cout
			<< "\nvector -->\t";
	for (int i = 0; i < vect.size(); i++)
	{
		cout << vect[i] << '\t';
	}
	cout << "\n-----------------------------------";
	//������������ ������ �������.
	//����� max_size() ���������� ���-�� ����.
	cout << "\nThe maximum possible length of the
			vector-- >
		"
			<< vect.max_size() / 4;
	cout << "\n-----------------------------------";
	vect.push_back(1); //��������� �������
	//� ����� �������
	cout << "\npush_back\nvector -->\t";
	for (int i = 0; i < vect.size(); i++)
	{
		cout << vect[i] << '\t';
	}
	cout << "\n-----------------------------------";
	//������� ��������� �������� � ���������
	//��� �� ����� �������
	vector<int>::reverse_iterator i_riterator =
		vect.rbegin();
	cout << "\nreverse_iterator\nvector -->\t";
	//������� ���������� �������� �� ����� ���������
	//��������� ��������
	for (int i = 0; i < vect.size(); i++)
	{
		cout << *(i_riterator + i) << '\t';
	}
	cout << "\n-----------------------------------";
	//������� ������� �������� � ��������� ���
	//�� ����� �������
	vector<int>::iterator i_iterator = vect.end();
	//������� �������� "-1" ����� ��������� ���������
	vect.insert(i_iterator - 1, -1);
	cout << "\ninsert\nvector -->\t";
	//������� ���������� �������� �� �����
	//��������� ������� ��������
	for (i_iterator = vect.begin();
		 i_iterator != vect.end(); i_iterator++)
	{
		cout << *(i_iterator) << '\t';
	}
	cout << "\n-----------------------------------";
	i_iterator = vect.end();		   //�������� ����� �������
	vect.insert(i_iterator - 1, 2, 4); //������� ����
	//�������� �����
	//���������
	//���������
	cout << "\ninsert\nvector -->\t";
	for (int i = 0; i < vect.size(); i++)
	{
		cout << vect[i] << '\t';
	}
	cout << "\n-------------------------------\n\n";
}
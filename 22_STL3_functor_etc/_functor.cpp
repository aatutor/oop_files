#include <algorithm>
#include <iostream>
#include <list>
using namespace std;
/*
	�������������� ������, ���������� ��� ����:
	1. ��� �������� �������� ���������� (delta)
	2. ��� �������� �������� ������������� ����� (current)
*/
class addNumberFrom
{
	int delta;
	int current;
/*
	����������� ������ �������������� �������� ����������
	� ������� ��������.
	��������� ����� ���� �������, � ����� ��� �����
	��������� ������ 0
*/
  public:
	addNumberFrom(int number, int from = 0) 
			: delta(number), current(from) {}
/*
	������ �������� � ������������� �������� ������
	������� � ���������� �������� ����������
	� �������� ������������� �����
*/
	int operator()()
	{
		return current += delta;
	}
};
void main()
{
	//����� ��������� ��� ������� ���������.
	cout << "TABLE:"
		 << "\n\n";
	cout << "----------"
		 << "\n\n";
	for (int i = 1; i <= 10; i++)
	{
		//C������� ����������-������.
		list<int> l(10);
/*
	����� ��������� generate_n. �����������,
	��� �� �� ����� ������ ������������,
	������ ��������������� ���������� ��������,
	�������� ������� ����� ���������
	���������� � ����������� ��������� ������.
	��� ������ ����� � ������ �������� ����������
	�������, �� ������� ��������� ������ ��������:
*/
		generate_n(l.begin(), l.size(), addNumberFrom(i));
/*
	�� �� ������ ������� ����������� �������������
	�������� ������ ������� � ������ addNumberFrom.
	���� ����� ���������� �������, �� ����������
	����������� �������. �� �������������� ����
	delta ��������� ���������� i,� ���� current -
	��������� �� ��������� ������� ���������
	������������, �. �. 0.
	����� �������, ���������-������ �����������
	�������������� ����� � ���������� i �
	����������� �� 1 �� 10. � ��������� generate_n
	������������ ����� size(), ������� ����������
	���������� ��������� � ������.
	���� ������� ��������� � �������� ���������,
	����� ����� ��������������� ����������
	generate.
*/
		//���������� ����� ����� �� ����������-������
		copy(l.begin(), l.end(), ostream_iterator<int>(cout, "\t"));
	}
}

/*
	1. �������������� ��������:
		plus �������� x + y;
		minus ��������� x � y;
		multiplies ��������� x ? y;
		divides ������� x / y;
		modulus ������ ������� x % y;
		negate ��������� ����� �x;
	2. �������� ���������:
		equal_to ����� x == y;
		not_equal_to �� ����� x != y;
		greater ������ x > y;
		less ������ x < y;
		greater_equal ������ ��� ����� x => y;
		less_equal ������ ��� ����� x <= y;
	3. ���������� ��������:
		logical_and ���������� �� x && y;
		logical_or ���������� ���� x || y;
		logical_not ���������� ��� ! x.
*/
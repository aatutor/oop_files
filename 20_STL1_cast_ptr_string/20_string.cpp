// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
// int main(int argc, char *argv[])
{
	string w1 = "Hello";
	string w2 = "world";

	string s = w1 + ' ' + w2;

	s.append("!");

	cout << s << endl;

	// �������� ������ ����� � ������
	int nWordEnd = s.find(' ');
	string sub_string = s.substr(0, nWordEnd);

	cout << "1st word: " << sub_string << endl;

	return 0;
}

// ������ �������� ����� ������������ ������� ������ string.
//	operator[] � ������ � ���������� �������� � ������ ��� ������ ��� ������
//	c_str() � ����������� ������ � const char* ��� ������������� � ��������, �� ������� �������� �� string
//	append � ���������� �������� � ����� ������
//	operator= � ������������ ������ ������ �����, ���������� �������� � ���� �����
//	insert � ������� �������� ��� ������ ����� � ���������� ���� string
//	erase � �������� ������ ��� ����� �������� �� �������� ������ � �������� �������
//	replace � ��������� ������ ��� ����� �������� � �������� �������
//	length(��� size) � ����������� ���������� �������� � ������
//	empty � �����������, ���� �� � ������ �������
//	find � ���������� ������� ��������� ������� ��� ��������� � ������ ������
//	rfind � ������ find, �� ������������ ����� � ����� ������ �����
//	find_first_of � ���������� ������� ��������� �������� �� ������ � ������
//	substr � ����������� ��������� 
//	find_first_not_of � ���������� ������� ������� � ������, �� ��������� � �������� �����
//	compare � ��������� ������ (����� �������������� ��������� !=, <, >)

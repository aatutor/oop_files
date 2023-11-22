// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//��������� �� ������ �������� �����������,
//�������������, ����� ���� �������� ��������
//������� ������
void test_pow(const int& v)
{
	//������� ����������� const
	//� ������ ����� �������� ������
	int* temp = const_cast<int*>(&v);
	// int& temp = const_cast<int>(v);  //error: invalid use of const_cast with type 'int', which is not a pointer, reference, nor a pointer-to-data-member type

	//��������� �������
	*temp = v * v;
}

int main ()
// int main(int argc, char *argv[])
{
	int x=10; 
	cout<<"Before - "<<x<<"\n\n";	//�� ������ � 10
	test_pow(x); 
	cout<<"After - "<<x<<"\n\n";	//�� ������ � 100
	return 0;
}

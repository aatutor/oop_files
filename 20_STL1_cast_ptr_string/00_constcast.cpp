// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//��������� �� ������ �������� �����������,
//�������������, ����� ���� �������� ��������
//������� ������
void test_pow(const int* v){
	int*temp;
	//������� ����������� const
	//� ������ ����� �������� ������
	temp = const_cast<int*>(v);
	//��������� �������
	*temp= *v * *v;
}

int main ()
// int main(int argc, char *argv[])
{
	int x=10; 
	cout<<"Before � "<<x<<"\n\n";	//�� ������ � 10
	test_pow(&x); 
	cout<<"After � "<<x<<"\n\n";	//�� ������ � 100
	return 0;
}

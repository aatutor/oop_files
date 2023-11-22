// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//������� �����
class A
{
public:
	//����������� ������� ���
	//������������ ��������������� � �������
	virtual void Test()
	{
		cout << "Test A\n\n";
	}
};
//�����-�������
class B : public A
{
public:
	//��������������� ����������� �������
	void Test() override
	{
		cout << "Test B\n\n";
	}
};

int main()
// int main(int argc, char *argv[])
{
	//��������� �� �����-��������
	//������ ������-��������
	A *ptr_a, obj_a;

	//��������� �� �����-�������
	//� ������ ������-�������
	B *ptr_b, obj_b;

	//�������� ����� ������� (B*) � ��������� ���� B*
	ptr_b = dynamic_cast<B*>(&obj_b);

	//���� ��� ������ ������� - �������� !0
	//��������� ����������
	if (ptr_b)
	{
		cout << "Good work - ";
		ptr_b->Test();
	}
	else //���� ��������� ������ - �������� nullptr
		cout << "Error work!!!\n\n";

	ptr_a = dynamic_cast<A*>(&obj_a);
	if (ptr_a)
	{
		cout << "Good work - ";
		ptr_a->Test();
	}
	else
		cout << "Error work!!!\n\n";

	ptr_a = dynamic_cast<A*>(&obj_b);
	if (ptr_a)
	{
		cout << "Good work - ";
		ptr_a->Test();
	}
	else
		cout << "Error work!!!\n\n";
	
	//��������!!! ��� ����������
	ptr_b = dynamic_cast<B*>(&obj_a); // warning: dynamic_cast of 'A obj_a' to 'class B*' can never succeed
	
	if (ptr_b)
		cout << "Good work - ";
	else
		cout << "Error work!!!\n\n";
		
	return 0;
}

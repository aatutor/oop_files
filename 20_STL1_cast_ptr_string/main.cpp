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
{
	{
		A* ptrA = new A;
		ptrA->Test();
		B* ptrB = reinterpret_cast<B*>(ptrA);
		ptrB->Test();
	}
	return 0;
}

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
		A* ptrB = new A;
		ptrB->Test();
		B* ptrD = reinterpret_cast<B*>(ptrB);
		ptrD->Test();
	}
	{
		int x = 5;
		unsigned int y = reinterpret_cast<unsigned int>(x);
	}
	return 0;
}

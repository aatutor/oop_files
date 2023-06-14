// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

template <class X>
class Std::auto_ptr
{
	X *ptr;

  public:
	//����������� � ����������
	explicit auto_ptr(X *p = 0) throw()
	{
		ptr = p;
	}
	~auto_ptr() throw()
	{
		delete ptr;
	}
	//�������� ������������� ��������� �������� ������
	X &operator*() const throw()
	{
		return *ptr;
	}
	//�������� -> ��������� �������� ���������
	X *operator->() const throw()
	{
		return ptr;
	}
};
class TEMP
{
  public:
	TEMP()
	{
		cout << "TEMP\n\n";
	}
	~TEMP()
	{
		cout << "~TEMP\n\n";
	}
	void TEST()
	{
		cout << "TEST\n\n";
	}
};
void main()
{
	//������ ��� �������������� ���������
	//��� ���� �� ��� �������� ������ ���� TEMP
	auto_ptr<TEMP> ptr1(new TEMP), ptr2;
	//�������� ����� ��������
	ptr2 = ptr1;
	//����� ������� ����� �������������� ���������
	ptr2->TEST();
	//������������ ��������������� ���������
	//�������� ��������� �� ������ ������
	TEMP *ptr = ptr2.get();
	//����� ������� ����� ������� ���������
	ptr->TEST();
}

int main()
// int main(int argc, char *argv[])
{
	f1();
	f2();

	return 0;
}

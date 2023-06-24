// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory>
using namespace std;

template <class X>
class my_auto_ptr
{
	X *ptr;
public: //����������� � ����������
	explicit my_auto_ptr(X *p = nullptr) throw() {
		ptr = p;
	}
	~my_auto_ptr() throw() {
		delete ptr;
	}
	//�������� ������������� ��������� �������� ������
	X& operator*() const throw() {
		return *ptr;
	}
	//�������� -> ��������� �������� ���������
	X* operator->() const throw() {
		return ptr;
	}
};
struct Temp
{
	Temp() { cout << "Temp\n\n"; }
	~Temp(){ cout << "~Temp\n\n"; }
	void Test() { cout << "Test\n\n"; }
};

int main()
{
	{
		int *x = new int(5);
		int *y = x;

		delete x;
		// delete y; // not success
	}
	{
 		//������ ��� �������������� ���������
		//��� ���� �� ��� �������� ������ ���� Temp
		std::auto_ptr<Temp> ptr1(new Temp), ptr2;
		// my_auto_ptr<Temp> ptr1(new Temp), ptr2;
		
		ptr2 = ptr1; //�������� ����� ��������

		ptr2->Test(); //����� ������� ����� �������������� ���������
		
		//������������ ��������������� ���������
		//�������� ��������� �� ������ ������
		Temp *ptr = &*ptr2;
		ptr->Test(); //����� ������� ����� ������� ���������
	}
	cout << "Success\n";
	return 0;
}

// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
// int main(int argc, char *argv[])
{
	int i;
	for(i=0;i<10;i++)
		cout<<static_cast<double>(i)/3<<"\t";	
		//���������� ���������� i � ���� double
		//���������� ������� �� ������, �����������
		//������������

	return 0;
}

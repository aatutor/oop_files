// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void f1()
{
	FILE *f;
	if (!(f = fopen("test.txt", "rt")))
	{
		//�� ������� ������� ���� � �������
		throw 1;
	}
	//�������, �������� � ������ ������
	//��, ����� ����� ���������� ����������
	//� �� ��������� ������ �� �� ���������
	//�������������� ���� �� ����� ������
	fclose(f);
}

class FileOpen
{
	FILE *f;
public:
	FileOpen(char *filename, char *mode)
	{
		if (!(f = fopen(filename, mode)))
		{
			throw 1;
		}
	}
	~FileOpen()
	{
		fclose(f);
	}
};
void f2()
{
	FileOpen MyFile("test.txt", "r+");
	//����� ��������� ������ ������ � ������
}
/// TODO: �������� ������ � ������

int main()
// int main(int argc, char *argv[])
{
	try {
		f1();
		f2();
	}
	catch (...) {
		cout << "Error with file!\n";
	}

	return 0;
}

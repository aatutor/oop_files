// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void f1()
{
	FILE *f;
	if (!(f = fopen("test.txt", "rt")))
	{
		//�� ������� ������� ���� � �������
		exit(0);
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
			exit(0);
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

int main()
// int main(int argc, char *argv[])
{
	f1();
	f2();

	return 0;
}

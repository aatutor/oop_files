// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void f1()
{
	FILE *f;
	if (!(f = fopen("test.txt", "rt")))
	{
		//не удалось открыть файл Ч выходим
		exit(0);
	}
	//удалось, работаем с файлом дальше
	//но, здесь может возникнуть исключение
	//и до следующей строки мы не доберемс€
	//соответственно файл не будет закрыт
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
	//здесь выполн€ем нужную работу с файлом
}

int main()
// int main(int argc, char *argv[])
{
	f1();
	f2();

	return 0;
}

// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void f1()
{
	FILE *f;
	if (!(f = fopen("test.txt", "rt")))
	{
		//не удалось открыть файл Ч выходим
		throw 1;
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
	//здесь выполн€ем нужную работу с файлом
}
/// TODO: добавить работу с файлом

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

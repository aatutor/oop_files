#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <io.h>
#include <stdio.h>
#include <string>

//������� ����������� �����
bool CopyFile(const char *source, const char *destination)
{
	FILE *src, *dest;

	// �������� �����
	if ( (src = fopen(source, "rb")) == 0 ){
		return false;
	}
	// �������� �����, ���� ����� ������������� �����������
	if ( (dest = fopen(destination, "wb")) == 0 ) {
		return false;
	}

	{
		// ��������� ����������� �����
		int handle = _fileno(src);
		long len = _filelength(handle);
	}
	while (!feof(src))
	{
		const int SIZE = 65536;
		//��������� ������ ��� ������
		char buf[SIZE];
		//������ ������ �� �����
		int realsize = fread(buf, sizeof(char), SIZE, src);
		//������ ������ � ����
		fwrite(buf, sizeof(char), realsize, dest);
	}

	//�������� ������
	fclose(src);
	fclose(dest);
	return true;
}

void Test1()
{
	using namespace std;
	{
		FILE* file = fopen("test.txt", "w");
		fputs("int main()\n{\n\tcout << \"Hello World\" << endl;\n}", file);
		fclose(file);
	}
	if (CopyFile("test.txt", "clone.cpp") == false){
		cout << "Failed to copy file\n";
	}

	system("pause");

	remove("test.txt");
	remove("clone.cpp");
}
void Test2()
{
	using namespace std;
	
	char source[]{"test.txt"};
	char clone[]{"clone"};
	{
		FILE* file = fopen(source, "wb");
		for(size_t i = 0; i != 1024; ++i)
		{
			long buf[1024]{};
			fwrite(buf, sizeof(long), 1024, file);
		}
		fclose(file);
	}
	if (_access(source, 00) != 0) {
		cout << "Source file not exists\n";
		return;
	}
	if (_access(source, 04) != 0) {
		cout << "Source file unreadable\n";
		return;
	}
	if (_access(clone, 00) == 0) {
		cout << "Clonable filename exist\n\t";
		if (_access(clone, 02) != 0){
			cout << "protected to write\n";
			return;
		}
		cout << "replacing file\n";
	}
	if (CopyFile(source, clone) == false){
		cout << "Failed to copy file\n";
	}

	system("pause");

	remove(source);
	remove(clone);
}

int main(int argc, char *argv[])
{
	// Test1();
	Test2();
	return 0;
}


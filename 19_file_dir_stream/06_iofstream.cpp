#include <iostream>
#include <fstream>
using namespace std;

void use_ofstream(const char* name);
void use_ifstream(const char* name);
void use_fstream(const char* name);
void use_struct(const char* name);

int main()
{
	char name[MAX_PATH]{ "test.txt" };

	// use_ofstream(name);
	// use_ifstream(name);

	// ofstream{name}; // создать файл
	use_fstream(name);

	// use_struct(name);

	system("pause");
	remove(name);
}

void use_ofstream(const char* fileName)
{
	ofstream oFile(fileName, ios::out);

	cout << "source: ";
	for (char c = 'A'; c <= 'Z'; c++) {
		cout << c;
		//oFile.put(c);
		oFile << c;
	}
	cout << endl;

	oFile.write("\n Hello world", 20);
	//oFile << "\n Hello world";

	oFile.close();
}
void use_ifstream(const char* name)
{
	ifstream iFile;
	iFile.open(name, ios::in);

	char line[100];

	//iFile.get(line, 100, '\n');
	iFile.getline(line, 100);
	cout << "in file> chars: " << line << endl;

	iFile.read(line, 100);
	cout << "in the end: " << line << endl;

	iFile.close();
}

void use_fstream(const char* name)
{
	fstream ioFile(name, ios::out | ios::in); // файл не создается, только открывается
	if (!ioFile.is_open()){
		cout << "not exists file " << name << endl;
		return;
	}

	cout << "source: ";
	for (char c = 'A'; c <= 'Z'; c++) {
		cout << c;
		// ioFile.put(c);
		ioFile << c;
	}
	cout << endl;
	ioFile.write("", 1);

	ioFile.seekg(0, ios::beg);

	char line[100];
	ioFile.getline(line, 100);
	cout << "in file: " << line << endl;

	ioFile.close();
}

struct A {
	char str[10];
	int x;
};

void use_struct(const char* name)
{
	A a{ "hello", 10 };
	ofstream file(name, ios::out | ios::binary);

	file.write((char*)&a, sizeof(a));

	file.close();
}


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <io.h>
#include <stdio.h>
#include <string>

void TestRp(){
	
	using namespace std;
	FILE* file;
	file = fopen("test.txt", "w");
	fprintf(file, "new");
	fclose(file);

	file = fopen("test.txt", "r+");

	//char str[100];
	char c;
	for (int i = 0; i < 1; i++) {
		fscanf(file, "%c", &c);
		cout << c << endl;
	}

	fprintf(file, "world");

	fclose(file);
}
void TestWp(){
	
	using namespace std;
	FILE* file;
	file = fopen("test.txt", "w");
	fprintf(file, "new");
	fclose(file);

	file = fopen("test.txt", "r+");

	fprintf(file, "st");
	//char str[100];
	char c = '-';
	for (int i = 0; i < 5; i++) {
		fscanf(file, "%c", &c);
		cout << c << endl;
		c = '-';
	}
	fprintf(file, "hello");
}

int main(int argc, char *argv[])
{
	// TestRp();
	TestWp();
	return 0;
}


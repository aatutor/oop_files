/*
	start with:
	g++ main.cpp -D1 -o main
*/
#include <iostream>
#include <io.h>
using namespace std;

int main()
{
	_finddata_t find;
	_findclose(_findfirst("_", &find));

	return 0;
}

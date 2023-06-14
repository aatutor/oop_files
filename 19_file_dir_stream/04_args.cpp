#include <iostream>
#include <direct.h>
#include <stdio.h>
using namespace std;

int main(int argc, char *argv[])
{
	cout << "Count arguments: "<< argc << endl;
	cout << "Args:\n";
	for(size_t i = 0; i < argc; i++)
	{
		cout << " - \t" << argv[i] << endl;
	}

    return 0;
}

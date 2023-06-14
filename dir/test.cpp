#include <iostream>
#include <direct.h>
#include <stdio.h>
#include <windows.h>
#include <io.h>
using namespace std;

int main()
{
    char path[MAX_PATH]{"cd     .."};
    char command[size];
    char temp[MAX_PATH];

    int ind = strspn(path+2, " ");
    strcpy(temp, path + ind + 2);
    cout << temp;
    cout << (path - temp);

    int a = 0;
    if (false && (a = 1))
        ;
    cout << "a: " << a << endl;
        
}

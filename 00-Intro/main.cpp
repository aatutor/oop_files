// ��������� ������� ������ ��������
#include <iostream>
#include <string> // ����������� ����� string
using namespace std;

int main()
{
    string h {"Hello"};    
    string w = "world";
    string str = h;
    str += " " + w + "!";

    cout << str << endl;
    cout << str.size() << endl;

	return 0;
}

// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <functional>
#include <string>
using namespace std;

// алгоритм поиска в строке
int Find(const string& str, char sym, int start = 0)
{
	if (start < 0 || start >= str.size())
		throw out_of_range{"index more"};

	for(int i = start; i != str.size(); ++i){
		if (str[i] == sym)
			return i;
	}

	return -1;
}

// алгоритм изменения элементов строки
void Transform(string& str, function<void(char&)> ftor)
{
	for(size_t i = 0; i != str.size(); ++i)
		ftor(str[i]);
}

int main ()
{
	string line{"hello world"};

	{
		int ind = Find(line, 'o');
		cout << ind <<": "<< line[ind] << endl;
		ind = Find(line, 'o', ind+1);
		cout << ind <<": "<< line[ind] << endl;
	}
	{
		Transform(line, [](char& c){
			if (c == 'l')
				c = '!';
		});
		cout << line << endl;
	}

	return 0;
}

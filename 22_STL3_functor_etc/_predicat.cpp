#include <algorithm>
#include <iostream>
#include <list>
using namespace std;
//��������
bool isEven(int num)
{
	return bool(num % 2);
}
void main()
{
	list<int> l;
	list<int>::iterator t;
	for (int i = 1; i <= 10; i++)
		l.push_back(i);
	copy(l.begin(), l.end(),
		 ostream_iterator<int>(cout, " "));
	cout << "\n\n";
	t = remove_if(l.begin(), l.end(), isEven);
	copy(l.begin(), t, ostream_iterator<int>(cout, " "));
}
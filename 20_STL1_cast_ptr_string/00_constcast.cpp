// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//указатель на объект €вл€етс€ константным,
//следовательно, через него изменить значение
//объекта нельз€
void test_pow(const int& v)
{
	//снимаем модификатор const
	//и теперь можем измен€ть объект
	int* temp = const_cast<int*>(&v);
	// int& temp = const_cast<int>(v);  //error: invalid use of const_cast with type 'int', which is not a pointer, reference, nor a pointer-to-data-member type

	//изменение объекта
	*temp = v * v;
}

int main ()
// int main(int argc, char *argv[])
{
	int x=10; 
	cout<<"Before - "<<x<<"\n\n";	//на экране Ч 10
	test_pow(x); 
	cout<<"After - "<<x<<"\n\n";	//на экране Ч 100
	return 0;
}

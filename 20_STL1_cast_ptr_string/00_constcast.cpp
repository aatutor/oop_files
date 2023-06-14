// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//указатель на объект €вл€етс€ константным,
//следовательно, через него изменить значение
//объекта нельз€
void test_pow(const int* v){
	int*temp;
	//снимаем модификатор const
	//и теперь можем измен€ть объект
	temp = const_cast<int*>(v);
	//изменение объекта
	*temp= *v * *v;
}

int main ()
// int main(int argc, char *argv[])
{
	int x=10; 
	cout<<"Before Ч "<<x<<"\n\n";	//на экране Ч 10
	test_pow(&x); 
	cout<<"After Ч "<<x<<"\n\n";	//на экране Ч 100
	return 0;
}

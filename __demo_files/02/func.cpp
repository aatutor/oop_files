/*
	Написать программу определения количества шестизначных 'счастливых' билетов, 
	у которых сумма первых 3 десятичных цифр равна сумме 3 последних десятичных цифр.
*/
#include <iostream>

void Slice(int temp, int nums[], int SIZE) 
{
	for(int i = 0; i < SIZE; i++)
	{
		nums[i] = temp % 10;
		temp /= 10;
	}
}
bool IsLucky(int num, const int SIZE)
{
	int nums[SIZE];
	Slice(num, nums, SIZE);

	int s1 = 0;
	int s2 = 0;
	for(size_t i = 0; i < SIZE/2; i++)
	{
		s1 += nums[i];
		s2 += nums[SIZE/2 + i];
	}
	return s1 == s2;
}

int GetCountLuckyByNum6() {
	const int SIZE = 6;
	int count = 0;

	for(int num = 0; num < 1000000; num++)
	{
		if ( IsLucky(num, SIZE) )
			count++;
	}
	return count;
}

void Print(int nums[], int SIZE){
	using namespace std;
	for(size_t i = 0; i < SIZE; i++)
		cout << nums[i] << " ";
	cout << endl;
}

int GetCountLucky6() {
	int count = 0;
	for(int a1 = 0; a1 < 10; a1++){
		for(int a2 = 0; a2 < 10; a2++){
			for(int a3 = 0; a3 < 10; a3++){
				for(int a4 = 0; a4 < 10; a4++){
					for(int a5 = 0; a5 < 10; a5++){
						for(int a6 = 0; a6 < 10; a6++){
							if (a1+a2+a3 == a4+a5+a6)
								count++;
	}}}}}}
	return count;
}
void Test() 
{
	using namespace std;
	int rightRes = GetCountLucky6();
	cout << rightRes << endl;	

	{
		if (rightRes == GetCountLuckyByNum6())
			cout << "ok\n";
		else
			cout << "fail\n";		
	}

	{
		cout << IsLucky(12, 6) << endl;		
	}
	{
		cout << IsLucky(123321, 6) << endl;		
	}
	{
		cout << IsLucky(10001, 6) << endl;		
	}
}

void Program() {
	using namespace std;
	cout << GetCountLucky6() << endl;	
}

int main ()
{
	Test();	
	//Program();
	
    return 0;
}

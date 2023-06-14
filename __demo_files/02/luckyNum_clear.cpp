/*
	Написать программу определения количества шестизначных 'счастливых' билетов, 
	у которых сумма первых 3 десятичных цифр равна сумме 3 последних десятичных цифр.
*/
#include <iostream>
#include <math.h>

class Number {
	int size_;
	int* digits_;
	int value_;
	int limit_;
public:
	Number(int size): size_(size), value_(0) 
	{
		this->limit_ = round( powl(10, this->size_) );
		this->digits_ = new int[this->size_] {}; 
	}
	~Number() {
		delete[] this->digits_;
	}
	bool IsEnd() {
		return this->value_ >= this->limit_;
	}
	int* GetDigits() {
		return this->digits_;
	}
	int* Next() 
	{
		++(this->value_);

		if (this->IsEnd()) {
			return nullptr;
		}
		this->FillDigits();

		return this->digits_;
	}
private:
	void FillDigits() 
	{
		int temp = this->value_;
		for(int i = 0; i != this->size_; ++i) {
			(this->digits_)[i] = temp % 10;
			temp /= 10;
		}
	}
};

class NumberLuckyCounter {
	int size_;
	int count_;
public:
	NumberLuckyCounter(int size): size_(size*2), count_(0)
	{
		this->CalcCount();
	}
	int GetCount() {
		return this->count_;
	}
	int GetSize() {
		return this->size_;
	}
private:
	void CalcCount() 
	{
		Number number(this->size_);

		while(number.IsEnd() != true) {
			if ( this->CheckLucky( number.GetDigits() ) ){
				++(this->count_);
			}
			number.Next();
		}
	}
	bool CheckLucky(int list[]) 
	{
		int s1 = 0, s2 = 0;
		for	(int i = 0, j = (this->size_)-1; i < j; ++i, --j)
		{
			s1 += list[i];
			s2 += list[j];
		}
		return s1 == s2;
	}
};

int GetCountLucky6() 
{
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

void Print(int nums[], int SIZE){
	using namespace std;
	for(size_t i = 0; i < SIZE; i++)
		cout << nums[i] << " ";
	cout << endl;
}

void Test() 
{
	// {
	// 	Testing(2);
	// }
	{
		Number number(2);
		while(number.IsEnd() != true) {
			Print(number.GetDigits(), 2);
			number.Next();
		}
	}
	{
		Number number(4);
		while(number.IsEnd() != true) {
			Print(number.GetDigits(), 4);
			number.Next();
		}
	}
}

void TestClass()
{
	using std::cout;
	using std::endl;

	NumberLuckyCounter counter6(3);
	cout << counter6.GetCount() << endl;
	cout << (GetCountLucky6() == counter6.GetCount() ? "ok" : "fail") << endl;
}

void Program() {
	std::cout << GetCountLucky6() << std::endl;	
}

int main ()
{
	TestClass();
	// Test();
	//Program();
	
    return 0;
}

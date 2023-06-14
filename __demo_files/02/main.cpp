/*
	Написать программу определения количества 2*N -значных 
	билетов, у которых сумма первых N десятичных цифр 
	равна сумме N последних десятичных цифр; при этом 
	N -произвольное натуральное число.
*/
#include <iostream>
#include <math.h>

class Number {
	int value_;
	int limit_;
	int size_;
	int* digits_;
public:
	Number(int size) {
		this->value_ = 0;
		this->limit_ = round(pow(10, size));

		// std::cout << (this->limit_) << std::endl;

		this->size_ = size;
		this->digits_ = new int[size]{};
	}
	// 0 1 4
	~Number() {
		delete[] digits_;
	}
	int GetSize() {
		return this->size_;
	}
	bool IsEnd() {
		return this->value_ >= this->limit_;
	}
	int* GetDigits() {
		return this->digits_;
	}
	bool Next() {
		++(this->value_);
		if (this->IsEnd() == true) {
			return false;
		}
		this->FillDigits();
		return true;
	}
private:
	void FillDigits() 
	{
		int temp = this->value_;
		for(int i = 0; i != this->size_; ++i)
		{
			(this->digits_)[i] = temp % 10;
			temp /= 10;
		}
	}
};

class NumberLuckyCounter {
	int size_;
	int count_;
public:
	NumberLuckyCounter(int n) 
	{
		this->size_ = n*2;

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
		this->count_ = 0;

		Number num(this->size_);

		do {
			// Print(num.GetDigits(), num.GetSize());
			if (this->IsLucky(num.GetDigits()) == true)
				++(this->count_);
		} while(num.Next() == true);
	}
	
	bool IsLucky(int*&& nums) 
	{
		int s1 = 0;
		int s2 = 0;
		for(size_t i = 0, j = (this->size_)-1; i < j; i++, j--)
		{
			s1 += nums[i];
			s2 += nums[j];
		}
		return s1 == s2;
	}
};

class SimpleLuckyCounter {
	int size_;
	int count_;
public:
	SimpleLuckyCounter(int n) 
	{
		this->size_ = n*2;

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
		this->count_ = 0;

		int* nums = new int[this->size_];
		this->CalcCount(0, nums);
		delete[] nums;
	}
	void CalcCount(int&& n, int*& nums) 
	{
		if (n == this->size_) 
		{
			if (this->IsLucky(nums) == true) {
				(this->count_)++;
			}
			return;
		}

		for(int digit = 0; digit < 10; digit++)
		{
			nums[n] = digit;
			this->CalcCount(n+1, nums);
		}
	}
	bool IsLucky(int*& nums) 
	{
		int s1 = 0;
		int s2 = 0;
		for(size_t i = 0, j = (this->size_)-1; i < j; i++, j--)
		{
			s1 += nums[i];
			s2 += nums[j];
		}
		return s1 == s2;
	}
};

void Test() 
{
	using namespace std;
	{
		NumberLuckyCounter numCtr6(3);
		cout << numCtr6.GetCount() << endl;
	}
	{
		for(int i = 1; i <= 4; i++)
		{
			SimpleLuckyCounter sim(i);
			NumberLuckyCounter num(i);
			if (sim.GetCount() == num.GetCount())
				cout << "ok";
			else
				cout << "fail";
			cout << endl;
		}
		
	}
	// {
	// 	SimpleLuckyCounter counter_6(3);

	// 	cout << counter_6.GetCount() << endl;
	// }
	// {
	// 	SimpleLuckyCounter counter_4(2);

	// 	cout << counter_4.GetCount() << endl;
	// }
}

void Program() {
	using namespace std;
	// cout << GetCountLucky6() << endl;	
}

int main ()
{
	Test();	
	//Program();
	
    return 0;
}

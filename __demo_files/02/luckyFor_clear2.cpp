/*
	Написать программу определения количества 2*N -значных 
	билетов, у которых сумма первых N десятичных цифр 
	равна сумме N последних десятичных цифр; при этом 
	N -произвольное натуральное число.
*/
#include <iostream>

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
		SimpleLuckyCounter counter_6(3);

		cout << counter_6.GetCount() << endl;
	}
	{
		SimpleLuckyCounter counter_4(2);

		cout << counter_4.GetCount() << endl;
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

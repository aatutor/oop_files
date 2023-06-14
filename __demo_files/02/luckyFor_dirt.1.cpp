/*
	Написать программу определения количества шестизначных 'счастливых' билетов, 
	у которых сумма первых 3 десятичных цифр равна сумме 3 последних десятичных цифр.
*/
#include <iostream>

void Print(int nums[], int SIZE){
	using namespace std;
	for(size_t i = 0; i < SIZE; i++)
		cout << nums[i] << " ";
	cout << endl;
}

class SimpleLuckyCounter {
	int size_;
	int count_;
public:
	SimpleLuckyCounter(int size2) {
		this->size_ = size2*2;

		this->CalcCount();
		// this->TestLucky();
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
	void CalcCount(int n, int digits[]) 
	{
		if (n == this->size_) {
			if (this->IsLucky(digits, n) == true)
				(this->count_)++;
			return;
		}

		for(int digit = 0; digit < 10; digit++)
		{
			digits[n] = digit;
			this->CalcCount(n+1, digits);
		}
	}
	bool IsLucky(int digits[], int size) 
	{
		int s1 = 0;
		int s2 = 0;
		for(size_t i = 0, j = size-1; i < j; i++, j--)
		{
			s1 += digits[i];
			s2 += digits[j];
		}
		return s1 == s2;
	}
	void TestLucky() {
		int* nums = new int[4]{2, 3, 2, 3};
		std::cout << this->IsLucky(nums, 4) << std::endl;
		
		delete[] nums;
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
		SimpleLuckyCounter counter6(3);
		cout << counter6.GetCount() << endl;
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

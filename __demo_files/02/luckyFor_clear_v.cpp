/*
	Написать программу определения количества шестизначных 'счастливых' билетов, 
	у которых сумма первых 3 десятичных цифр равна сумме 3 последних десятичных цифр.
*/
#include <iostream>
#include <vector>

class SimpleLuckyCounter {
	int size_;
	int count_;
public:
	SimpleLuckyCounter(int size) 
	{
		this->size_ = size*2;
		this->count_ = 0;

		CalcCount();
	}
	int GetCount() 
	{
		return count_;
	}
private:
	void CalcCount() 
	{
		std::vector<int> temp;
		CalcCount(temp);
	}
	void CalcCount (std::vector<int>& numbers) 
	{
		if (numbers.size() == this->size_) 
		{
			if (CheckLucky(numbers)) {
				++(this->count_);
			}
			return;
		}

		for(int digit = 0; digit != 10; ++digit)
		{
			numbers.push_back(digit);
			CalcCount(numbers);
			numbers.pop_back();
		}
	}
	bool CheckLucky (std::vector<int>& list) 
	{
		int s1(0), s2(0);
		for	(int i = 0, j = list.size()-1; i < j; ++i, --j)
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

void TestClass()
{
	using std::cout;
	using std::endl;

	SimpleLuckyCounter counter(3);
	cout << counter.GetCount() << endl;
	cout << (GetCountLucky6() == counter.GetCount() ? "ok" : "fail") << endl;
}

void Program() {
	std::cout << GetCountLucky6() << std::endl;	
}

int main ()
{
	TestClass();
	//Program();
	
    return 0;
}

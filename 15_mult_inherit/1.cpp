#include <iostream>
using namespace std;

void Test1() 
{
	class ParentOne {
	protected:
		int one_ = 1;
	};
	class ParentTwo {
	protected:
		int two_ = 2;
	};
	class Child : public ParentOne, public ParentTwo {
	public:
		void Foo() {
			cout << one_ <<" "<< two_ << endl;
		}
		void Bar() {
			one_ = 3;
			two_ = 4;
		}
	};

	{
		Child* chPrt = new Child(); // 1 2
		chPrt->Bar();

		ParentOne* parPrt = (ParentOne*)chPrt;
		Child* chPrt2 = (Child*)parPrt;
		chPrt2->Foo();	// 3 4
	}
	{
		Child ch;
		ch.Foo(); // 1 2

		ParentOne p1 = (ParentOne)ch;
		Child ch2 = (Child)p1; // fail: no exists Child::Child(ParentOne&)
	}
}
void Test2() 
{
	class ParentOne {
	protected:
		int one_ = 1;
	};
	class ParentTwo {
	protected:
		int two_ = 2;
	};
	class Child : public ParentOne, public ParentTwo {
	public:
		Child() = default;
		Child(ParentOne& par): ParentOne(par), ParentTwo() {}
		void Foo() {
			cout << one_ <<" "<< two_ << endl;
		}
		void Bar() {
			one_ = 3;
			two_ = 4;
		}
	};

	{
		Child ch; // 1 2
		ch.Bar();

		ParentOne p1 = (ParentOne)ch;
		Child ch2 = (Child)p1;

		ch2.Foo(); // 3 2 - wat?
	}
}

int main ()
{
	Test1();
	Test2();
	
	return 0;
}

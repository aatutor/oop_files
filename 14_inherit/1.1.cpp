#include <iostream>
using namespace std;

void TestPub() 
{
	class Parent {
	private: 	int priv_;
	protected: 	int prot_;
	public: 	int pub_;
	};
	class Child : public Parent {
	public:
		void Foo() {
			// priv_ = 0; // fail
			prot_ = 1;	// ok
			pub_ = 2;	// ok
		}
	};

	Parent par;
	// par.priv_ = 0;
	// par.prot_ = 0;
	par.pub_ = 0; // ok. Other - fail

	Child ch;
	// ch.priv_ = 0;
	// ch.prot_ = 0;
	ch.pub_ = 10; // ok. Other - fail
}

void TestPriv() 
{
	class Parent {
	private: 	int priv_;
	protected:	int prot_;
	public: 	int pub_;
	};
	class Child : private Parent {
	public:
		void Foo() {
			// priv_ = 0; // fail
			prot_ = 1;	// ok
			pub_ = 2;	// ok
		}
	};
	class Baby : public Child {
	public:
		void Foo() {
			// priv_ = 0; 	// fail
			// prot_ = 1;	// fail
			// pub_ = 2;	// fail
		}
	};

	Parent par;
	// par.priv_ = 0;
	// par.prot_ = 0;
	par.pub_ = 1; // ok. Other - fail

	Child ch;
	// ch.priv_ = 0;
	// ch.prot_ = 0;
	// ch.pub_ = 11; // fail. All field is private

	Baby bb;
	// bb.priv_ = 0;
	// bb.prot_ = 0;
	// bb.pub_ = 22; // fail
}
void TestProt() 
{
	class Parent {
	private: 	int priv_;
	protected:	int prot_;
	public: 	int pub_;
	};
	class Child : protected Parent {
	public:
		void Foo() {
			// priv_ = 0; // fail
			prot_ = 1;	// ok
			pub_ = 2;	// ok
		}
	};
	class Baby : public Child {
	public:
		void Foo() {
			// priv_ = 0; // fail
			prot_ = 1;	// ok
			pub_ = 2;	// ok
		}
	};

	Parent par;
	// par.priv_ = 0;
	// par.prot_ = 0;
	par.pub_ = 2; // ok. Other - fail

	Child ch;
	// ch.priv_ = 0;
	// ch.prot_ = 0;
	// ch.pub_ = 12; // fail. pub_ - protected

	Baby bb;
	// bb.priv_ = 0;
	// bb.prot_ = 0;
	// bb.pub_ = 22; // fail
}

int main ()
{
	TestPub();
	TestPriv();
	TestProt();

	return 0;
}

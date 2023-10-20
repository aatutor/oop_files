#include <iostream>
#include "ElemTree.cc"
using namespace std;

void Tests();

int main()
{
	Tests();
}

void TestCtor() {
	ElemTree t{
		{1,'z'},
		{3,'x'},
		{0,'c'}
	};
	cout << "must: c z x\n";
	t.Print();
	cout << "c-tor & print done\n";
}
ElemTree* CreateTree() {
	return new ElemTree{
		{1,'z'},
		{3,'x'},
		{0,'c'}
	};
}
void Console(bool flag, const char* msg) {
	cout << (flag ? "ok" : "fail") << ": " << msg << endl;
}
bool CheckElemIn(ElemTree* tree, Element* elem) {
	Element* temp = tree->Search(elem->key);
	return temp ? temp->value == elem->value : false;
}
void TestSrch() {
	Element* a = new Element{1, 'a'},
			*b = new Element{2, 'b'},
			*c = new Element{0, 'c'};
	ElemTree t({*a, *b, *c});
	Console( CheckElemIn(&t, a)
			&& CheckElemIn(&t, b) 
			&& CheckElemIn(&t, c) 
			, "Search");
	// Console(   t->Search(0)->value == 'c'
	// 		&& t->Search(1)->value == 'z' 
	// 		&& t->Search(3)->value == 'x' 
	// 		, "Search");
}

void TestEmpty() {
	cout << "TestEmpty\n";
	ElemTree t;
	Element* a = new Element {1, 'a'};

	t.Print();
	Console(1, "Print empty");
	Console(CheckElemIn(&t, a) == 0, "Search empty");

	t.Insert(a);
	Console( CheckElemIn(&t, a), "Insert empty");
}

void Tests() 
{
	TestCtor();
	TestSrch();
	TestEmpty();
	ElemTree* t = CreateTree();
	cout << CheckElemIn(t, new Element{0, 'c'}) << ": check element in tree\n";
	delete t;
}
#include <iostream>
using namespace std;

struct Node {
	int val;
	Node* next;
};

class List {
	enum {ERROR = 0, EMPTY = -1};
	Node* top_ = nullptr;
public:
	void Print() {
		Node* temp = top_;

		cout << "list: ";
		while (temp != nullptr) {
			cout << temp->val << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	bool IsEmpty() {
		return top_ == nullptr; 
	}
	int GetSize() {
		Node* temp = top_;
		int k = 0;
		while (temp != nullptr) {
			temp = temp->next;
			k++;
		}
		return k;
	}
	void AddBefore(int val) {
		Node* temp = new Node { val };
		if ( !IsEmpty()) {
			temp->next = top_;
		}
		top_ = temp;
	}
	void PushBack(int val) {
		Node* temp = new Node{ val };

		if ( IsEmpty() ){
			top_ = temp;
			return;
		}
		Node* current = top_;
		while (current->next != nullptr){
			current = current->next;
		}
		current->next = temp;
	}
	int Pop() {
		if ( IsEmpty() ) 
			return ERROR; // плохо, но пока так
		
		if (top_->next == nullptr) {
			int val = top_->val;

			delete top_;
			top_ = nullptr;

			return val;
		}

		Node* current = top_;
		Node* prev = 0;
		while (current->next != nullptr){
			prev = current;
			current = current->next;
		}
		int val = current->val;

		delete current;
		prev->next = nullptr;

		return val;
	}
	int Search(int val) {
		Node* temp = top_;
		int k = 0;
		while (temp != nullptr) {
			if (temp->val == val)
				return k;
			temp = temp->next;
			k++;
		}
		return EMPTY;
	}
	void Remove(int val) {
		int ind = Search(val);
		if (ind == EMPTY) 
			return;
			
		if (ind == 0) {
			Node* next = top_->next;
			delete top_;
			top_ = next;
			return;
		}

		Node* temp = top_;
		Node* prev = 0;
		for (int i = 0; i < ind; i++){
			prev = temp;
			temp = temp->next;
		}
		prev->next = temp->next;
		delete temp;
	}
	void Insert(int pos, int val) {
		if ( IsEmpty() || pos == 0)
			AddBefore(val);

		Node* temp = new Node{ val };

		Node* current = top_;
		Node* prev = 0;
		for (int i = 0; i < pos && current != nullptr; i++){
			prev = current;
			current = current->next;
		}
		prev->next = temp;
		temp->next = current;
	}
};

void Demo() 
{
	List list;
	list.PushBack(8);
	list.PushBack(2);
	list.PushBack(5);
	list.Print();
	cout <<"size: "<< list.GetSize() << endl;
	list.AddBefore(4);
	list.Insert(2, 10);
	list.Print();
	cout << "2 on "<< list.Search(2) + 1 << " position" << endl;
	list.Remove(2);
	cout << "Removed 2\n";
	list.Print();
}

void Test();

int main()
{
	// Test();
	Demo();
}

void Test() 
{
	{
		List list;
		cout << (list.GetSize() == 0 ? "ok" : "fail") << ": count empty\n";
	}
	{
		List list;
		list.PushBack(1);
		cout  << (list.Pop() == 1 ? "ok" : "fail") << ": pop one\n";
		cout << (list.GetSize() == 0 ? "ok" : "fail") << ": pop last\n";
	}
	{
		List list;
		list.PushBack(1);
		list.PushBack(2);
		list.AddBefore(3);
		cout << (list.GetSize() == 3 ? "ok" : "fail") << ": push+add\n";
	}
	{
		List list;
		list.Remove(1);
		cout << (list.GetSize() == 0 ? "ok" : "fail") << ": remove empty\n";
	}
	{
		List list;
		list.PushBack(1);
		list.Remove(1);
		cout << (list.GetSize() == 0 ? "ok" : "fail") << ": remove last\n";
	}
	{
		List list;
		list.PushBack(1);
		list.PushBack(3);
		list.Remove(1);
		cout << (list.GetSize() == 1 ? "ok" : "fail") << ": remove top\n";
	}
	{
		List list;
		list.PushBack(1);
		list.PushBack(3);
		list.Remove(3);
		cout << (list.GetSize() == 1 ? "ok" : "fail") << ": remove back\n";
	}
}
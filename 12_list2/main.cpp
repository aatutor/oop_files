#include <iostream>
using namespace std;

struct Node {
	int val;
	Node* next;
	Node* prev;
};

class List {
	enum {ERROR = 0, EMPTY = -1};
	Node* top_ = nullptr;
	Node* tail_ = nullptr;
public:
	void Print() {
		cout << "list: ";
		Node* temp = top_;
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
	void PushBack(int val) {
		Node* temp = new Node{ val };
		if (tail_ != nullptr) {
			tail_->next = temp;
			temp->prev = tail_;
		}
		else {
			top_ = temp;
		}
		tail_ = temp;
	}
	void AddBefore(int val) {
		Node* temp = new Node{ val };
		if (top_ != nullptr) {
			top_->prev = temp;
			temp->next = top_;
		}
		else {
			tail_ = temp;
		}
		top_ = temp;
	}
	int Pop() {
		if (tail_ == nullptr)
			return ERROR;

		int val = tail_->val;
		if (top_ == tail_) {
			delete tail_;
			top_ = tail_ = nullptr;
		}
		else {
			tail_ = tail_->prev;
			delete tail_->next;
			tail_->next = nullptr;
		}
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

		Node* temp = top_;
		for (int i = 0; i < ind; i++)
			temp = temp->next;

		if (temp->prev != nullptr) 
			(temp->prev)->next = temp->next;
		else
			top_ = temp->next;

		if (temp->next != nullptr) 
			(temp->next)->prev = temp->prev;
		else
			tail_ = temp->prev;

		delete temp;
	}
	void Insert(int pos, int val) {
		if ( IsEmpty() || pos == 0)
			AddBefore(val);


		Node* current = top_;
		for (int i = 0; i < pos && current != nullptr; i++){
			current = current->next;
		}
		if (current == nullptr) PushBack(val);

		Node* temp = new Node{ val };
		(current->prev)->next = temp;
		temp->prev = current->prev;

		temp->next = current;
		current->prev = temp;
	}
};

void Demo() {
	List list;
	cout << list.GetSize() << endl;
	list.PushBack(5);
	list.PushBack(3);
	list.AddBefore(1);
	list.Print();
	cout << "5 on "<< list.Search(5) + 1 << " position" << endl;
	list.Remove(3);
	cout << "Removed 3\n";
	list.Print();
}

void Test();

int main()
{
	Test();
	// Demo();
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
		list.Remove(1);
		cout << (list.Pop() == 0 ? "ok" : "fail") << ": empty pop after remove\n";
	}
	{
		List list;
		list.PushBack(1);
		cout	<< (list.Pop() == 1 ? "ok" : "fail") << ": Pop one\n";
		cout << (list.GetSize() == 0 ? "ok" : "fail") << ": Pop last\n";
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
		 cout << (list.GetSize() == 0 ? "ok" : "fail") << ": Remove empty\n";
	}
	{
		List list;
		list.PushBack(1);
		list.Remove(1);
		 cout << (list.GetSize() == 0 ? "ok" : "fail") << ": Remove last\n";
	}
	{
		List list;
		list.PushBack(1);
		list.PushBack(3);
		list.Remove(1);
		 cout << (list.GetSize() == 1 ? "ok" : "fail") << ": Remove top\n";
	}
	{
		List list;
		list.PushBack(1);
		list.PushBack(3);
		list.Remove(3);
		 cout << (list.GetSize() == 1 ? "ok" : "fail") << ": Remove back\n";
	}
}
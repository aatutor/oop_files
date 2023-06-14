#include <iostream>
using namespace std;

struct Node {
	int val;
	Node* next = nullptr;
	Node* prev = nullptr;
};

class List {
	Node* top = nullptr;
	Node* tail = nullptr;
public:
	List() {}
	void pushBack(int val) {
		Node* temp = new Node{ val };
		if (tail) {
			tail->next = temp;
			temp->prev = tail;
		}
		else {
			top = temp;
		}
		tail = temp;
	}
	void addBefore(int val) {
		Node* temp = new Node{ val };
		if (top) {
			top->prev = temp;
			temp->next = top;
		}
		else {
			tail = temp;
		}
		top = temp;
	}
	int pop() {
		if (!tail)
			return NULL;
		int val = tail->val;
		if (top == tail) {
			delete tail;
			top = tail = nullptr;
		}
		else {
			tail = tail->prev;
			delete tail->next;
			tail->next = nullptr;
		}
		return val;
	}
	int srch(int val) {
		Node* temp = top;
		int k = 0;
		while (temp) {
			if (temp->val == val)
				return k;
			temp = temp->next;
			k++;
		}
		return -1;
	}
	void remove(int val) {
		int ind = srch(val);
		if (ind == -1) return;
		Node* temp = top;
		for (int i = 0; i < ind; i++)
			temp = temp->next;

		if (temp->prev) (temp->prev)->next = temp->next;
		else			top = temp->next;
		if (temp->next) (temp->next)->prev = temp->prev;
		else			tail = temp->prev;

		delete temp;
	}
	bool isEmpty() { return top == nullptr; }
	void print() {
		cout << "list: ";
		Node* temp = top;
		while (temp) {
			cout << temp->val << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	int getSize() {
		Node* temp = top;
		int k = 0;
		while (temp) {
			temp = temp->next;
			k++;
		}
		return k;
	}
};

int main()
{
	List list;
	cout << list.getSize() << endl;
	list.pushBack(5);
	list.pushBack(3);
	list.addBefore(1);
	list.print();
	cout << list.srch(5) << endl;
	list.remove(3);
	list.print();
}

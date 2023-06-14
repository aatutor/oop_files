#include <iostream>
using namespace std;

class Stack {
	enum { EMPTY = -1, FULL = 20 };
	char st[FULL + 1];
	int top;
public:
	Stack() : top(EMPTY) {}
	void push(const char c) {
		if (isFull())
			return;
		st[top + 1] = c;
		top++;
		//cout << "add: " << st[top] << endl;
	}
	char pop() {
		if (isEmpty())
			return NULL;
		//cout << "pop: " << st[top] << endl;
		top--;
		return st[top + 1];
		//retrun st[top--];
	}
	void clear() { top = EMPTY; }
	bool isEmpty() { return top == EMPTY; }
	bool isFull() { return top == FULL; }
	int getCount() { return top + 1; }
};

int main()
{
	Stack s;
	s.push('a');
	s.push('b');
	s.push('c');
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;

	return 0;
}

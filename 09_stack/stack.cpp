#include <iostream>
using namespace std;

class Stack {
	enum { EMPTY = -1, FULL = 20 };
	int st_[FULL + 1];
	int top_;
public:
	Stack() : top_(EMPTY) {}
	void Clear() { 
		top_ = EMPTY; 
	}
	bool IsEmpty() { 
		return top_ == EMPTY; 
	}
	bool IsFull() { 
		return top_ == FULL; 
	}
	int GetCount() { 
		return top_ + 1; 
	}

	void push(int c) {
		if (IsFull())
			return;
		top_++;
		st_[top_] = c;
		//st_[++top_] = c;
	}
	int pop() {
		if (IsEmpty())
			return -1;// -1 - плохо, но пока сойдет
		top_--;
		return st_[top_ + 1];
		//retrun st_[top_--];
	}
};

int main()
{
	Stack s;
	s.push(2);
	s.push(5);
	s.push(1);
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;

	return 0;
}

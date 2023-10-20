#include <iostream>
#include <functional>
using namespace std;

struct Node {
	int value;
	Node* next;
};
#define OLD 0
class List {
	enum {ERROR = 0, EMPTY = -1};
	Node* top_ = nullptr;
public:
	void Print() {
		cout << "list: ";

	#if OLD
		Node* temp = top_;
		while (temp) {
			cout << temp->value << " ";
			temp = temp->next;
		}
	#else
		ForEach([](Node*& temp){
			cout << temp->value << " ";
		});
	#endif
		cout << endl;
	}
	bool IsEmpty() {
		return top_ == nullptr; 
	}
	int GetSize() {
		int k = 0;
	#if OLD
		Node* temp = top_;
		while (temp) {
			k++;
			temp = temp->next;
		}
	#else
		ForEach([&k](Node*& temp){
			k++;
		});
	#endif
		return k;
	}
	void AddBefore(int value) {
		top_ = new Node{ value, top_ };
	}
	void PushBack(int value) {
		(IsEmpty() 
			? top_ 
			: Last()->next
		) = new Node{ value };
	}
	int Pop() {
	#define POPV 0
		if ( IsEmpty() ) 
			throw "can't remove from empty list";
	#if POPV		
		Node* current = top_;
		Node* prev = nullptr;
		while (current->next){
			prev = current;
			current = current->next;
		}
	#else
		#if 1
		Node*& current = Last();
		#else
			Node* prev;
			try {
				prev = Prev();
			}
			catch(...) {
				prev = nullptr;
			}
			Node* current = prev ? prev->next : top_;
		#endif
	#endif
		
	#if POPV
		bool flag = top_->next == nullptr;
	#else
		// bool flag = prev != nullptr;
		// bool flag = !prev;
	#endif

	#if POPV
		Node* toRemove = flag ? top_ : current;
		int value = toRemove->value;
		delete toRemove;
	#else
		int value = current->value;
		delete current;
	#endif
	
	#if POPV
		(flag ? top_ : prev->next) = nullptr;
	#else
		current = nullptr;
	#endif

		return value;
	}
	int Search(int value) {
		Node** ptr = &top_;
		return Search(value, ptr);
	}
	bool Remove(int value) {
	#if OLD
		int ind = Search(value);
	#else
		Node** temp = &top_;
		int ind = Search(value, temp);
	#endif
	
	// #if OLD
	// #else
	// #endif
		if (ind == EMPTY)
			return false;
			
	#if OLD
		if (ind == 0) {
			Node* next = top_->next;
			delete top_;
			top_ = next;
			return true;
		}
		Node* temp = top_;
		Node* prev = 0;
		for (int i = 0; i < ind; i++){
			prev = temp;
			temp = temp->next;
		}
		prev->next = temp->next;
		delete temp;
		return true;
	#else
		Node* next = (temp != &top_ ? (*temp)->next : nullptr); // save next
		delete (*temp); // remove needed
		(temp == &top_ ? top_ : (*temp)->next) = next; // fix links
		return true;
	#endif
	}
	int GetValue(int ind) {
		return GetByIndex(ind)->value;
	}
	void Insert(int pos, int value) {
		if ( IsEmpty() || pos == 0)
			AddBefore(value);
		
	#if 0
		Node* node = new Node{ value };

		Node* temp = top_;
		Node* prev = 0;
		for (int i = 0; i < pos && temp != nullptr; i++){
			prev = temp;
			temp = temp->next;
		}
		prev->next = node;
		node->next = temp;
	#else
		Node*& current = GetByIndex(pos);
		current = new Node{value, current->next};
	#endif
	}
private:
/// TODO: в колбеках убрать ссылку?
	Node*& GetByIndex(int ind) {
		size_t i = 0;
		Node* prev = 0;
		ForEach([&i, ind](Node*& temp){
			return i++ < ind && temp != nullptr;
		},
		[&prev](Node*& temp){
			prev = temp;
		});
		return prev->next;
	}
/// TODO: возвращать ноду
	int Search(int value, Node**& begin) {
	#if OLD
		int k = 0;
		Node* temp = *begin;
		while (temp) {
			if (temp->value == value)
				return k;
			k++;
			temp = temp->next;
		}
	#else
		int k = 0;
		bool flag = 1;
		Node* prev = 0;
		ForEach([begin](Node*& temp){
			temp = *begin;
		},
		[&flag](Node*& temp){
			return flag && temp != nullptr;
		},
		[&flag, &k, &value, &begin, &prev](Node*& temp){
			if (temp->value == value){
				// begin = &(prev->next);
				flag = 0;
			}
			else {
				k++;
				prev = temp;
			}
		});
		begin = &(prev->next);
	#endif
	#if OLD
		return EMPTY;
	#else
		return (flag ? EMPTY : k);
	#endif
	}
	Node*& Prev() {
		if (IsEmpty())
			throw "has no last item";

		if(top_->next == nullptr)
			throw "has no prev item";

		if(top_->next->next == nullptr)
			return top_;
		
		Node* prev = nullptr;
		ForEach([](Node*& temp){
			return temp->next->next;
		},
		[&prev](Node*& temp){
		#if 0
			if(temp->next){
				if(temp->next->next){
					if(temp->next->next->next == nullptr){
						prev = temp;
					}
				}
			}
		#else
			if(temp->next->next->next == nullptr){
				prev = temp;
			}
		#endif
		});
		return prev->next;
	}
	Node*& Last() { // and source of last
		if (IsEmpty())
			throw "has no last item";
			
		if (top_->next == nullptr)
			return top_;

	#if OLD
		Node* current = top_;
		while ( current->next->next ){
			current = current->next;
		}
	#else
		Node* current;
		ForEach([](Node*& temp){
			return temp->next;
		},
		[&current](Node*& temp){
			if (temp->next->next == nullptr){
				current = temp;
			}
		});
	#endif
		return current->next;
	}
	void ForEach(std::function<void(Node*&)> init,
			std::function<bool(Node*&)> cont, 
			std::function<void(Node*&)> todo) {
		Node* temp;
		init(temp);
		while ( cont(temp) ){
			todo(temp);
			temp = temp->next;
		}
	}
	void ForEach(std::function<bool(Node*&)> cont, 
			std::function<void(Node*&)> todo) {
		Node* ptr = top_;
		ForEach([ptr](Node*& temp){
			temp = ptr;
		},
			cont,
			todo
		);
	}
	void ForEach(std::function<void(Node*&)> todo) {
		ForEach([](Node*& temp){
			return temp != nullptr;
		},
			todo
		);
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
void Check();

int main()
{
	Check();
	Test();
	Demo();
}

void Console(bool flag, const char* msg){
	using namespace std;
	cout  << (flag ? "ok":"fail") <<": "<< msg << endl;
}

void Check() 
{
	using namespace std;

		List list;
		list.PushBack(1);
		list.PushBack(2);
		Console(list.GetSize() == 2, "count two");
		Console(list.Search(2) == 1, "search two");
		Console(list.Search(2) == 1, "search two again");
		Console(list.Remove(2) && list.GetSize() == 1, "remove two");
		list.Print();
		Console(1, "==============");
}

void Test() 
{
	{// Empty
		List list;
		Console(list.GetSize() == 0, "count empty");
		#if 0
		bool flag = 1;
		try {
			list.Pop();
			flag = 0;
		} catch (...) {}
		Console(flag , "push back empty");
		#endif
		Console(list.Search(1) == -1, "search empty");
		Console(list.Remove(1) == 0, "remove empty");
	}
	{ // push back
		List list;
		list.PushBack(1);
		list.PushBack(3);
		list.PushBack(5);
		list.PushBack(7);
		Console(list.Pop() == 7, "pop");
		Console(
			list.Pop() == 5 &&
			list.Pop() == 3 &&
			list.Pop() == 1
		, "PushBack");
		Console(list.GetSize() == 0, "pop clear");
	}
	{ // One
		List list;
		list.PushBack(1);
		Console(list.GetSize() == 1, "count one");
		Console(list.Search(1) == 0, "search one");
		Console(list.Remove(1), "remove one");
	}
	{ // Two
		List list;
		list.PushBack(1);
		list.PushBack(2);
		Console(list.GetSize() == 2, "count two");
		Console(list.Search(2) == 1, "search two");
		Console(list.Search(2) == 1, "search two again");
		Console(list.Remove(2) && list.GetSize() == 1, "remove two");
	}
	{
		List list;
		list.PushBack(1);
		list.PushBack(2);
		list.PushBack(3);
		Console(list.GetSize() == 3, "push back");
		Console(list.Search(1) == 0, "search first");
		Console(list.Search(2) == 1, "search inside");
		Console(list.Search(3) == 2, "search last");
		Console(list.Search(0) == -1, "search none");
	}
	{
		List list;
		list.PushBack(1);
		list.PushBack(1);
		Console(list.Pop() == 1 && list.Pop() == 1, "push+pop same");
	}
	{
		List list;
		list.AddBefore(1);
		list.AddBefore(2);
		list.AddBefore(3);
		Console(list.GetSize() == 3, "add before");
	}
	{
		List list;
		list.AddBefore(1);
		Console(list.Remove(2) == 0, "remove wrong");
		Console(list.Remove(1) && list.GetSize() == 0, "remove last");
	}
	{
		List list;
		list.PushBack(1);
		list.PushBack(3);
		Console(list.Remove(1) && list.Search(1) == -1, "remove top");
	}
	{
		List list;
		list.PushBack(1);
		list.PushBack(3);
		Console(list.Remove(3) && list.Search(3) == -1, "remove back");
	}
	{
		List list;
		list.PushBack(1);
		list.PushBack(2);
		list.PushBack(3);
		Console(list.Remove(2) && list.Search(2) == -1, "remove inside");
	}
}
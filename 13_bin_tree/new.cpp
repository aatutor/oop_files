#include <iostream>
// using namespace std;

struct Pair {
	char value;
	int key;
};

struct Node {
	Pair* element;
	// Node* left = nullptr;
	// Node* right = nullptr;
	// Node* parent = nullptr;
	Node* left;
	Node* right;
	Node* parent;
};
class ElemTree {
	Node* root_ = nullptr;
public:
	bool IsEmpty() { 
		return root_ == nullptr; 
	}
	void Insert(Pair elem) {
		Node* obj = new Node{ new Pair(elem) };

		if (IsEmpty()) {
			root_ = obj;
			return;
		}

		Node* temp = root_;
		Node* lastParent = nullptr;
		bool flag = true;
		do {
			lastParent = temp;
			flag = elem.key < temp->element->key;
			temp = flag ? temp->left : temp->right;
			// if (flag)
			// 	temp = temp->left;
			// else
			// 	temp = temp->right;
		} while (temp);

		obj->parent = lastParent;
		flag ? lastParent->left : lastParent->right = obj;
		// if (flag)
		// 	lastParent->left = obj;
		// else
		// 	lastParent->right = obj;
	}
	// friend ostream& operator<< (ostream& out, ElemTree& tree){
	void Print() {
		using namespace std;
		if (IsEmpty())
			return;

		using namespace std;
		Node* temp = Min(root_);
		while(temp){
			cout << (temp->element->value) << "["
			     << (temp->element->key) << "], ";
			temp = Next(temp);
		}
		cout << endl;
	}
	Pair* Search(int key) {
		return Search(key, root_)->element;
	}
	void Remove(int key) {
		// search node
		// remove node

	}
private:
	Node* Min(Node* obj) {
		while (obj->left)
			obj = obj->left;
		return obj;
	}
	Node* Next(Node* obj) {
		if (!obj) // obj == nullptr
			throw "can't find next from null";

		if (obj->right){
			return Min(obj->right);
		}
		Node* curParent = obj->parent;
		while (obj == curParent->right && curParent) {
			obj = curParent;
			curParent = curParent->parent;
		}
		return curParent;
	}
	Node* Search(int key, Node* temp){
		while(temp){
			int tempKey = temp->element->key;
			if (key == tempKey)
				break;
			else
				temp = (key < tempKey) 
						? temp->left 
						: temp->right;
		}
		return temp;
	}
	void Remove(Node* obj) {
		if (root_ == obj) { // delete root
			if (obj->left == 0 && obj->right == 0)
				root_ = nullptr;
			else if (obj->left != 0 && obj->right != 0) {
				root_ = obj->right;
				obj->right->parent = nullptr;

				Node* temp = Next(obj);
				temp->left = obj->left;
				obj->left->parent = temp;
			}
			else if (obj->left != 0) {
				obj->left->parent = nullptr;
				root_ = obj->left;
			}
			else {
				obj->right->parent = nullptr;
				root_ = obj->right;
			}
		}
		else if (obj->left == 0 && obj->right == 0) {
			if (obj == obj->parent->right)
				obj->parent->right = nullptr;
			else
				obj->parent->left = nullptr;
		}
		else if (obj->left != 0 && obj->right != 0) {
			if (obj == obj->parent->right)
				obj->parent->right = obj->right;
			else
				obj->parent->left = obj->right;
			obj->right->parent = obj->parent;

			Node* temp = Next(obj);
			temp->left = obj->left;
			obj->left->parent = temp;
		}
		else if (obj->left != 0) {
			obj->left->parent = obj->parent;
			obj->parent->left = obj->left;
		}
		else {
			obj->right->parent = obj->parent;
			obj->parent->right = obj->right;
		}
		delete obj;
	}
	void Remove1(Node* obj){
		Node* temp;
		Node*& curParent = (obj == root_)
			? root_
			: obj->parent;

		if (obj->left == nullptr && obj->right == nullptr)
			curParent = nullptr;
		else if(obj->left == nullptr || obj->right == nullptr)
			Node*& curChild = (curParent->left) ? curParent->left : curParent->right;

		if (temp)
			temp->parent = curParent->parent;

		if ( !(curParent->parent) )
			root_ = temp;
		else if (curParent == curParent->parent->left)
			curParent->parent->left = temp;
		else
			curParent->parent->right = temp;

		if (curParent != obj) {
			// strcpy(obj->name, curParent->name);
			// strcpy(obj->opp, curParent->opp);
			// strcpy(obj->match, curParent->match);
			// obj->oppPoints = curParent->oppPoints;
			// obj->ownerPoints = curParent->ownerPoints;
		}
		delete curParent;
	}
	void RemoveTernary(Node* obj) {
		if (obj->left == 0 && obj->right == 0){
			// if (obj == root_)
			// 	root_ = nullptr;
			// else {
			// 	if (obj == obj->parent->right)
			// 		obj->parent->right = nullptr;
			// 	else
			// 		obj->parent->left = nullptr;
			// }
			((obj == root_) ? 
				root_ :
				(obj == obj->parent->right) ?
					obj->parent->right :
					obj->parent->left
			) = nullptr;
		}
		else if (obj->right == 0) {
			// if (obj == root_) {
			// 	obj->left->parent = nullptr;
			// 	root_ = obj->left;
			// }
			// else {
			// 	obj->left->parent = obj->parent;
			// 	obj->parent->left = obj->left;
			// }
			obj->left->parent = (obj == root_) ?
				nullptr :
				obj->parent;
			((obj == root_) ?
				root_ :
				obj->parent->left
			) = obj->left;
		}
		else if (obj->left == 0) {
			// if (obj == root_) {
			// 	obj->right->parent = nullptr;
			// 	root_ = obj->right;
			// }
			// else {
			// 	obj->right->parent = obj->parent;
			// 	obj->parent->right = obj->right;
			// }
			obj->right->parent = (obj == root_) ?
				nullptr :
				obj->parent;
			((obj == root_) ?
				root_ :
				obj->parent->right
			) = obj->right;
		}
		else if (obj->left != 0 && obj->right != 0) {
			// if (obj == root_) {
			// 	root_ = obj->right;
			// 	obj->right->parent = nullptr;
			// }
			// else {
			// 	if (obj == obj->parent->right)
			// 		obj->parent->right == obj->right;
			// 	else
			// 		obj->parent->left == obj->right;
			// 	obj->right->parent = obj->parent;
			// }
			((obj == root_) ? 
				root_ :
				(obj == obj->parent->right) ?
					obj->parent->right :
					obj->parent->left
			) = obj->right;
			obj->right->parent = (obj == root_) ?
				nullptr :
				obj->parent;

			Node* temp = Next(obj);
			temp->left = obj->left;
			obj->left->parent = temp;
		}
		delete obj;
	}
#if 0
	void RemoveTernary1(Node* obj) {
		if (obj->left == 0 && obj->right == 0){
			((obj == root_) ? 
					root_ :
					(obj == obj->parent->right) ?
							obj->parent->right :
							obj->parent->left)
									= nullptr;
		}
	#if 0
		else if (obj->right == 0) {
			obj->left->parent = (obj == root_) ?
					nullptr :
					obj->parent;
			((obj == root_) ?
					root_ :
					obj->parent->left)
							= obj->left;
		}
		else if (obj->left == 0) {
			obj->right->parent = (obj == root_) ?
					nullptr :
					obj->parent;
			((obj == root_) ?
					root_ :
					obj->parent->right) 
							= obj->right;
		}
	#endif
	#if 1
		else if (obj->right == 0 || obj->left == 0) {
			Node*& objSide = (obj->left == 0) ?
					obj->right:
					obj->left;
			objSide->parent = (obj == root_) ?
					nullptr :
					obj->parent;
			((obj == root_) ?
					root_ :
					obj->parent->(obj->left == 0 ?
							right : left)
			) = objSide;
		}
	#endif
		else if (obj->left != 0 && obj->right != 0) {
			((obj == root_) ?
					root_ :
					obj->parent->(obj == obj->parent->right) ?
							right :
							left)
									= obj->right;
			obj->right->parent = (obj == root_) ?
					nullptr :
					obj->parent;

			Node* temp = Next(obj);
			temp->left = obj->left;
			obj->left->parent = temp;
		}
		delete obj;
	}
#endif
};

int main()
{
	ElemTree tree;
	// Node a = new Node{'a'},
	// 	 b = new Node{'b'},
	// 	 c = new Node{'c'};
	// init a, b, c
	tree.Insert({'a', 10});
	tree.Insert({'b', 20});
	tree.Insert({'c', 3});

}

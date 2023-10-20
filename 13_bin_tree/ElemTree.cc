#include <iostream>
#include <initializer_list>

struct Element {
	int key;
	char value;
};
struct Node {
	Element* elem;
	Node* left;
	Node* right;
	Node* parent;
};
class ElemTree {
	Node* root_ = nullptr;
public:
	void Insert(Element* elem) {
		Node* eNode = new Node{ elem };
		
		if (root_ == nullptr) {
			root_ = eNode;
			return;
		}
		Node* temp = root_;
		Node* parent = nullptr;

		while (temp != nullptr) {
			parent = temp;
			if (elem->key < parent->elem->key)
				temp = temp->left;
			else
				temp = temp->right;
		}
		eNode->parent = parent;
		if (elem->key < parent->elem->key)
			parent->left = eNode;
		else
			parent->right = eNode;
	}
  	void Print(){
		std::cout << "Tree: "; 
		Print(root_);
		std::cout << std::endl;
	}
	Element* Search(int key){
		Node* temp = SearchNode(key, root_);
		if (temp == nullptr)
			return nullptr;

		return temp->elem;
	}
	Element* Min(){
		Node* temp = Min(root_);
		if (temp == nullptr)
			return nullptr;
		
		return temp->elem;
	}
	Element* Max(){
		Node* temp = Max(root_);
		if (temp == nullptr)
			return nullptr;
		
		return temp->elem;
	}
	Element* Next(Element* elem){
		if (elem == nullptr)
			return nullptr;

		return Next( SearchNode(elem->key, root_) )->elem;
	}
	Element* Previous(Element* elem);
	void Delete(Element* elem){
		Node* temp = SearchNode(elem->key, root_);
		Delete(temp);
	}
	~ElemTree(){
		Delete(root_);
	}
	ElemTree() = default;
	ElemTree(std::initializer_list<Element> init) {
		for(auto elem : init) {
			Insert(new Element{elem});
		}
	}
private:
	void Print(Node* eNode){
		if (eNode == nullptr)
			return;
		
		Print(eNode->left);
		std::cout << eNode->elem->value << " ";
		Print(eNode->right);
	}
	Node* SearchNode(int key, Node* temp){
		// Node* temp = root_;

		while (temp != nullptr) {
			if (key == temp->elem->key)
				return temp;
			if (key < temp->elem->key)
				temp = temp->left;
			else
				temp = temp->right;
		}
		return nullptr;
	}
	Node* GetNode(Element* eNode) {

	}
	Node* Next(Node* eNode){
		if (eNode == nullptr)
			return nullptr; // throw

		if (eNode->right)
			return Min(eNode->right);

		Node* parent = eNode->parent;
		while (parent != nullptr && eNode == parent->right) {
			eNode = parent;
			parent = eNode->parent;
		}
		return parent;
	}
  	Node* Prev(Node* eNode);
	Node* Min(Node* eNode){
		if (eNode == nullptr)
			return nullptr; // or throw

		while (eNode->left)
			eNode = eNode->left;
		return eNode;
	}
	Node* Max(Node* eNode){
		if (eNode == nullptr)
			return nullptr; // or throw

		while (eNode->right)
			eNode = eNode->right;
		return eNode;
	}
	void Delete(Node* eNode) {
		if (root_ == eNode) {
			if (eNode->left == 0 && eNode->right == 0)
				root_ = nullptr;
			else if (eNode->left != 0 && eNode->right != 0) {
				root_ = eNode->right;
				eNode->right->parent = nullptr;

				Node* temp = Next(eNode);
				temp->left = eNode->left;
				eNode->left->parent = temp;
			}
			else if (eNode->left != 0) {
				eNode->left->parent = nullptr;
				root_ = eNode->left;
			}
			else {
				eNode->right->parent = nullptr;
				root_ = eNode->right;
			}
		}
		else if (eNode->left == 0 && eNode->right == 0) {
			if (eNode == eNode->parent->right)
				eNode->parent->right == nullptr;
			else
				eNode->parent->left == nullptr;
		}
		else if (eNode->left != 0 && eNode->right != 0) {
			if (eNode == eNode->parent->right)
				eNode->parent->right == eNode->right;
			else
				eNode->parent->left == eNode->right;
			eNode->right->parent = eNode->parent;

			Node* temp = Next(eNode);
			temp->left = eNode->left;
			eNode->left->parent = temp;
		}
		else if (eNode->left != 0) {
			eNode->left->parent = eNode->parent;
			eNode->parent->left = eNode->left;
		}
		else {
			eNode->right->parent = eNode->parent;
			eNode->parent->right = eNode->right;
		}
		delete eNode;
	}
};



#if 0
void ElemTree::Insert(Element* elem) {
	Node* eNode = new Node{ elem };
	
	if (root_ == nullptr) {
		root_ = eNode;
		return;
	}
	Node* temp = root_;
	Node* parent = nullptr;

	while (temp != nullptr) {
		parent = temp;
		if (elem->key < parent->elem->key)
			temp = temp->left;
		else
			temp = temp->right;
	}
	eNode->parent = parent;
	if (elem->key < parent->elem->key)
		parent->left = eNode;
	else
		parent->right = eNode;
}

void ElemTree::Print(Node* eNode) {
	if (eNode == nullptr)
		return;
	
	Print(eNode->left);
	std::cout << eNode->elem->value << " ";
	Print(eNode->right);
}
void ElemTree::Print() {
	Print(root_);
}

Node* ElemTree::SearchNode(int key) {
	Node* temp = root_;

	while (temp != nullptr) {
		if (key == temp->elem->key)
			return temp;
	}
	return nullptr;
}

Element* ElemTree::Search(int key) {
	Node* temp = SearchNode(key);
	if (temp == nullptr)
		return nullptr;

	return temp->elem;
}

Node* ElemTree::Min(Node* eNode) {
	if (eNode == nullptr)
		return nullptr; // or throw

	while (eNode->left)
		eNode = eNode->left;
	return eNode;
}
Element* ElemTree::Min() {
	Node* temp = Min(root_);
	if (temp == nullptr)
		return nullptr;
	
	return temp->elem;
}

Node* ElemTree::Max(Node* eNode) {
	if (eNode == nullptr)
		return nullptr; // or throw

	while (eNode->right)
		eNode = eNode->right;
	return eNode;
}
Element* ElemTree::Max() {
	Node* temp = Max(root_);
	if (temp == nullptr)
		return nullptr;
	
	return temp->elem;
}

Node* ElemTree::Next(Node* eNode){
	if (eNode == nullptr)
		return nullptr; // throw

	if (eNode->right)
		return Min(eNode->right);

	Node* parent = eNode->parent;
	while (parent != nullptr && eNode == parent->right) {
		eNode = parent;
		parent = eNode->parent;
	}
	return parent;
}
Element* ElemTree::Next(Element* elem) {
	if (elem == nullptr)
		return nullptr;

	return Next( SearchNode(elem->key) )->elem;
}
#endif
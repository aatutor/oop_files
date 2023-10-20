#include <iostream>

struct Pair {
	char value;
	int key;
};

struct Node {
	Pair* element;
	Node* left = nullptr;
	Node* right = nullptr;
	Node* parent = nullptr;
};

class Tree {
	Node* root_;
	void RemoveTernar(Node* obj) {
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

	void RemoveTernar2(Node* obj) {
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
	Node*& ParentSide(Node* obj) {
		if(obj->parent == nullptr)
			throw "have not parent";

		return obj->parent->(obj == obj->parent->right ? right : left);
	}
	
	Node* Min(Node* obj) {
		while (obj->left)
			obj = obj->left;
		return obj;
	}
	Node* Next(Node* obj) {
		if (!obj) // obj == nullptr
			throw "can't find next from null";

		if (obj->right){
			return Min(obj-right);
		}
		Node* curParent = obj->parent;
		while (obj == curParent->right && curParent) {
			obj = curParent;
			curParent = curParent->parent;
		}
		return curParent;
	}
};
int main()
{
	using namespace std;
	
	int x{}, y{};

	(false ? x : y) = 1;

	cout << x << y << endl;

	return 0;
}

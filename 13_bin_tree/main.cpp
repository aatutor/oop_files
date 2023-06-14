#include <iostream>
using namespace std;

struct Elem {
	char name[20];
	int ownerPoints;
	int oppPoints;
	char opp[20];
	char match[10];
	Elem *left = nullptr;
	Elem *right = nullptr;
	Elem *parent = nullptr;
};
struct Cat {
	int size;
	char* name[100];
	bool operator <=>
}
struct Node {
	Cat value;
	Cat* left;
	Cat* right;
	Cat* parent;
}
class Tree {
	Node* root_ = nullptr;
public:
	void Insert(Cat *z) {
		Node* temp = new Node{ z };
		if (root_ == nullptr) {
			root_ = z;
			return;
		}
		Cat* prnt = nullptr;
		Cat* temp = root_;

		while (temp != nullptr) {
			prnt = temp;
			if (strcmp(z->name, temp->name) < 0)
				temp = temp->left;
			else
				temp = temp->right;
		}
		z->parent = prnt;
		if (strcmp(z->name, prnt->name) < 0)
			prnt->left = z;
		else
			prnt->right = z;
	}
	void Delete(Cat* z = nullptr) {
		if (!z) {
			while (root_)
				Delete(root_);
			return;
		}
		Cat* temp, *prnt;
		if (z->left == 0 || z->right == 0)
			prnt = z;
		else
			prnt = Next(z);

		if (prnt->left)
			temp = prnt->left;
		else
			temp = prnt->right;

		if (temp)
			temp->parent = prnt->parent;

		if (prnt->parent == 0)
			root_ = temp;
		else if (prnt == prnt->parent->left)
			prnt->parent->left = temp;
		else
			prnt->parent->right = temp;
		
		if (prnt != z) {
			strcpy(z->name, prnt->name);
			strcpy(z->opp, prnt->opp);
			strcpy(z->match, prnt->match);
			z->oppPoints = prnt->oppPoints;
			z->ownerPoints = prnt->ownerPoints;
		}
		delete prnt;
	}
	void Del2(Cat* z = nullptr) {
		if (!z) {
			while (root_)
				Del2(root_);
			return;
		}
		if (root_ == z) {
			if (z->left == 0 && z->right == 0)
				root_ = nullptr;
			else if (z->left != 0 && z->right != 0) {
				root_ = z->right;
				z->right->parent = nullptr;

				Cat* temp = Next(z);
				temp->left = z->left;
				z->left->parent = temp;
			}
			else if (z->left != 0) {
				z->left->parent = nullptr;
				root_ = z->left;
			}
			else {
				z->right->parent = nullptr;
				root_ = z->right;
			}
		}
		else if (z->left == 0 && z->right == 0) {
			if (z == z->parent->right)
				z->parent->right == nullptr;
			else
				z->parent->left == nullptr;
		}
		else if (z->left != 0 && z->right != 0) {
			if (z == z->parent->right)
				z->parent->right == z->right;
			else
				z->parent->left == z->right;
			z->right->parent = z->parent;

			Cat* temp = Next(z);
			temp->left = z->left;
			z->left->parent = temp;
		}
		else if (z->left != 0) {
			z->left->parent = z->parent;
			z->parent->left = z->left;
		}
		else {
			z->right->parent = z->parent;
			z->parent->right = z->right;
		}
		delete z;
	}
	Cat * Next(Cat* z) {
		Cat* prnt = nullptr;
		if (z) {
			if (z->right)
				return Min(z->right);

			prnt = z->parent;
			while (prnt && z == prnt->right) {
				z = prnt;
				prnt = prnt->parent;
			}
		}
		return prnt;
	}
	Cat* Min(Cat* z) {
		if (z)
			while (z->left)
				z = z->left;
		return z;
	}
};

int main()
{
	Tree tree;
	Cat *a = new Cat,
		*b = new Cat,
		*c = new Cat;
	// init a, b, c
	tree.Insert(a);
	tree.Insert(b);
	tree.Insert(c);

}

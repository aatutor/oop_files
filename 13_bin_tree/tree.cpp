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
class Tree {
	Elem* root = nullptr;
public:
	void insert(Elem *z) {
		if (!root) {
			root = z;
			return;
		}
		Elem * prnt = nullptr;
		Elem * temp = root;

		while (temp) {
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
	void del(Elem* z = nullptr) {
		if (!z) {
			while (root)
				del(root);
			return;
		}
		Elem* temp, *prnt;
		if (z->left == 0 || z->right == 0)
			prnt = z;
		else
			prnt = next(z);

		if (prnt->left)
			temp = prnt->left;
		else
			temp = prnt->right;

		if (temp)
			temp->parent = prnt->parent;

		if (prnt->parent == 0)
			root = temp;
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
	void del1(Elem* z = nullptr) {
		if (!z) {
			while (root)
				del1(root);
			return;
		}
		if (root == z) {
			if (z->left == 0 && z->right == 0)
				root = nullptr;
			else if (z->left != 0 && z->right != 0) {
				root = z->right;
				z->right->parent = nullptr;

				Elem* temp = next(z);
				temp->left = z->left;
				z->left->parent = temp;
			}
			else if (z->left != 0) {
				z->left->parent = nullptr;
				root = z->left;
			}
			else {
				z->right->parent = nullptr;
				root = z->right;
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

			Elem* temp = next(z);
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
	Elem * next(Elem* z) {
		Elem* prnt = nullptr;
		if (z) {
			if (z->right)
				return min(z->right);

			prnt = z->parent;
			while (prnt && z == prnt->right) {
				z = prnt;
				prnt = prnt->parent;
			}
		}
		return prnt;
	}
	Elem* min(Elem* z) {
		if (z)
			while (z->left)
				z = z->left;
		return z;
	}
};

int main()
{
	Tree tree;
	Elem *a = new Elem,
		*b = new Elem,
		*c = new Elem;
	// init a, b, c
	tree.insert(a);
	tree.insert(b);
	tree.insert(c);

}

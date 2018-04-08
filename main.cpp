# tree001

#include <iostream>

using namespace std;

class tree_t
{
private:
	struct node_t {
		node_t * left;
		node_t * right;
		int value;

		node_t() {
			left = nullptr;
			right = nullptr;
			value = 0;
		}

		void print_(ostream & stream, int size) const {
			if (right != nullptr) right->print_(stream, size + 4);
			for (int i = 0; i < size + 4; i++) 
				stream << '-';
			stream << value << endl;
			if (left != nullptr) left->print_(stream, size + 4);
		}

		~node_t() {
			if (left != nullptr) delete left;
			if (right != nullptr)delete right;
		}

	};

	node_t * root_;

public:
	tree_t() {
		root_ = nullptr;
	}

	void insert(int value) {

		if (root_ == nullptr) {
			root_ = new node_t;
			root_->value = value;
		}
		else {
			node_t * first = root_;

			while (root_->left != nullptr || root_->right != nullptr) {
				if (root_->value > value ) {
					if (root_->left != nullptr) root_ = root_->left;
					else break;
				}
				else if (root_->value < value ) {
					if (root_->right != nullptr) root_ = root_->right;
					else break;
				}
			}

			if (root_->value > value) {
				root_->left = new node_t;
				root_->left->value = value;
			}
			else if (root_->value < value) {
				root_->right = new node_t;
				root_->right->value = value;
			}
			root_ = first;
		}
	}

	bool find(int value) const {

		if (root_ == nullptr) return false;

		else {
			node_t * tmp = root_;

			while (tmp != nullptr) {
				if (tmp->value == value) return true;
				else if (tmp->value > value) tmp = tmp->left;
				else if (tmp->value < value) tmp = tmp->right;
			}
			return false;
		}
	}

	void print(ostream & stream) const {
		if (root_ == nullptr) {
			stream << "ERROR: EMPTY TREE " << endl;
		}
		else {
			root_->print_(stream, 0);
		}
	}

	~tree_t() {
		if (root_ != nullptr) delete root_;
	}
};


int main()
{
	char oper;
	tree_t Tree;
	cin >> oper;
	int data;

	while (oper != 'q') {

		switch (oper)
		{
		case '+':
			cin >> data;
			Tree.insert(data);
			Tree.print(cout);
			break;
		
		case '?':
			cin >> data;
			if (Tree.find(data)) cout << "true" << endl;
			else cout << "false" << endl;
			break;

		case '=':
			Tree.print(cout);
			break;
		}

		cin >> oper;
	}

	cin.get();
	cin.get();
	return 0;
}

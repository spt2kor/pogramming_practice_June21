#include <iostream>
#include <queue>
#include <stack>
using namespace std;
//----------------------------
struct Node {
	int data;
	Node* left;
	Node* right;
	Node():left(nullptr),right(nullptr){}
	Node(int data, Node* left=nullptr, Node* right= nullptr) :data(data), left(left), right(right) {}
};
//----------------------------------------------------
void insert(Node*& root, int data) {
	Node* node = new Node(data);;
	if (root == nullptr) {
		root = node;
	}
	else {
		Node* temp = root;

		while (temp) {
			if (data <= temp->data) {
				if (temp->left == nullptr) {
					temp->left = node;
					return;
				}
				temp = temp->left;
			}
			else {
					if (temp->right == nullptr) {
						temp->right = node;
						return;
					}
					temp = temp->right;
			}
		}
	}
}
void printInorderRecursive(Node* &root)
{
	if (root == nullptr)
		return;
	if (root->left)
		printInorderRecursive(root->left);

	cout << "\t " << root->data;
	if (root->right)
		printInorderRecursive(root->right);

}
//-----------------------------------------
void printInorderIterative(Node*& root) // LNR ,  R,N L
{
	if (root == nullptr)
		return;
	stack<Node*> st;
	Node* tmp = root;
	while (! st.empty()  || (tmp))
	{
		while (tmp)
		{
			st.push(tmp);
			tmp = tmp->left;
		}
		tmp = st.top();
		st.pop();
		cout << "\t " << tmp->data;

		tmp = tmp->right;
	}
}
//----------------------------------------------------
void printLevelorderIterative(Node*& root)
{
	if (root == nullptr)
		return;
	queue<Node*> qu;
	qu.push(root);
	Node* tmp = nullptr;
	while (!qu.empty())
	{
		tmp = qu.front();
		qu.pop();
		cout << "\t " << tmp->data;
		if (tmp->left)
			qu.push(tmp->left);
		if (tmp->right)
			qu.push(tmp->right);
	}
}
//----------------------------------------------------
void driver_tree_traveral()
{
	cout << "\n program started" << endl;
	Node* root = nullptr;
	insert(root, 30);
	insert(root, 20);
	insert(root, 10);
	insert(root, 25);
	insert(root, 50);
	insert(root, 40);
	insert(root, 60);
	cout << "\n Inorder recusrive : ";
	printInorderRecursive(root);
	cout << "\n Inorder iterative: ";
	printInorderIterative(root);

	cout << "\n Level order iterative: ";
	printLevelorderIterative(root);
	cout << endl << endl;
}

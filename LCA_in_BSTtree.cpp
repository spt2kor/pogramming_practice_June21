#include <iostream>

using namespace std;

/// <summary>
/// BST Node
/// </summary>
struct Node {
	int v;
	Node* l;
	Node* r;
	Node(): v(INT_MIN), l(nullptr), r(nullptr) 	{}

	Node(int v, Node* l = nullptr, Node* r=nullptr) : v(v), l(l), r(r) {}
};
Node* root = nullptr;

void insert( int v)
{
	Node* n = new Node(v);
	Node* t = root;
	if (!root) {
		root = n;
		t = root;
	}
	else {
		while (t)
		{
			if (t->v < v ) {
				if (!t->r)
				{
					t->r = n;
					break;
				}
				else {
					t = t->r;
				}
			}
			else {
				if (!t->l)
				{
					t->l = n;
					break;
				}
				else {
					t = t->l;
				}
			}
		}//end of while

	}
	if (!t)
		cout << "unable to insert the node in Tree" << endl;
	else
		cout << "successfully added node :" << v << endl;
}

void find_LCA(int m, int n)
{
	cout << "\n find_LCA of " << m << ", and " << n << " : ";
	if (!root)
		cout << "Tree is Empty " << endl;
	else
	{
		Node* t = root;
		while (t)
		{
			if (t->v == m)
			{
				cout << " LCA is = " << m << endl;
				break;
			}
			else if (t->v == n)
			{
				cout << " LCA is = " << n << endl;
				break;
			}
			else if ((m < t->v && t->v < n) || (n < t->v && t->v < m))
			{
				cout << " LCA is = " << t->v << endl;
				break;
			}
			else if (m < t->v && n < t->v)
				t = t->l;
			else
				t = t->r;
		}
		if (!t)
			cout << " No LCA present in Tree " << endl;
	}
}

void Driver_LCA_In_BSTTree()
{
	int td[] = { 50,20,40,60,80,45,19,70,35,75 };
	for(auto x : td)
		insert(x);

	find_LCA(80, 70);
	find_LCA(50, 70);
	find_LCA(20, 19);
	find_LCA(70, 19);
}
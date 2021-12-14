#include <iostream>
using namespace std;

struct Node {
	int v;
	Node* l;
	Node* r;
	Node(int v = INT_MIN , Node* l= nullptr, Node* r=nullptr) :v(v), l(l), r(r)
	{	}

};
Node* root = nullptr;

struct List
bool FindNGetPath(int m)
{

}

void Find_LCA(int m , int n)
{

}


void Driver_for_LCA_in_simpleTree()
{
	cout << "\n Driver_for_LCA_in_simpleTree()" << endl;
	Node* t = nullptr;
	t = root = new Node(20);

	t->l = new Node(10);
		t->l->l = new Node(70);
			t->l->l->l = new Node(25);
			t->l->l->r = new Node(85);
		t->l->r = new Node(40);
			t->l->r->l = new Node(5);
			t->l->r->r = new Node(60);
	t->r = new Node(5);
		t->r->l = new Node(50);
			t->r->l->l = new Node(35);
			t->r->l->r = new Node(90);
		t->r->r = new Node(55);
			t->r->r->l = new Node(65);
			t->r->r->r = new Node(80);

	Find_LCA(25, 35);
	Find_LCA(5, 35);
	Find_LCA(25, 55);
	Find_LCA(25, 60);
	Find_LCA(5, 35);
	Find_LCA(55, 35);

}
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
{
	Node* cn;
	List* nxt;

	List(Node* cn=nullptr, List* nxt=nullptr) : cn(cn), nxt(nxt)
	{}
};

bool FindNGetPath(int m, Node* rt,  List* &l)
{
	if (!rt)
	{
		l = nullptr;
	}
	else
	{
		l = new List(rt);
		if (rt->v == m)
		{
			return true;
		}
		else
		{
			if (FindNGetPath(m, rt->l, l->nxt))
			{
				return true;
			}
			else if (FindNGetPath(m, rt->r, l->nxt))
			{
				return true;
			}
		}
	}

	return false;
}

void Find_LCA(int m , int n)
{
	cout << "\n LCA of m= " << m << ", and n= " << n << " : ";
	List* p = nullptr;
	FindNGetPath(m, root, p);

	List* q = nullptr;
	FindNGetPath(m, root, q);

	List* r = p;
	List* s = q;
	Node* re = nullptr;
	while (r && s)
	{
		if (r->cn->v == s->cn->v)
		{
			re = r->cn;

			r = r->nxt;
			s = s->nxt;
		}
		else
			break;
	}
	if (re)
		cout << " found: value : " << re->v << endl;
	else
		cout << " Not found" << endl;

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
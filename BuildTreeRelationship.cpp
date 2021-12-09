#include "common.h"
struct Node {
	string name;
	unordered_set<Node*> childs;
	Node(string name) :name(name) {}
};
void printList(string root, unordered_map<string, Node*>& treeMap, int tab)
{
	cout << endl;
	for (int i = 0; i < tab; ++i)
		cout << "\t";

	cout << root;

	auto childs = treeMap[root]->childs;
	++tab;
	for (auto itr = childs.begin(); itr != childs.end(); ++itr) {
		auto name = (*itr)->name;
		printList(name, treeMap, tab);
	}
}
//--------------------------
void buildTree(vector<pair<string, string>>& anmalOrder)
{
	int size = anmalOrder.size();
	unordered_map<string, Node*> treeMap;
	unordered_map<string,bool> rootList;

	for (int i = 0; i < size; ++i)
	{
		auto elem = anmalOrder[i];
		auto par = elem.first;
		auto child = elem.second;
		//cout << "\n\n pair : par=" << par << ", child=" << child;
		if (treeMap.find(par) == treeMap.end())
		{
			//cout << "\n add parent in  treeMap : par=" << par ;
			treeMap[par] = new Node(par);
		}

		if (treeMap.find(child) == treeMap.end())
		{
			//cout << "\n add child  in treeMap : child=" << child;
			treeMap[child] = new Node(child);
		}
		//add child
		treeMap[par]->childs.insert(treeMap[child]);
		//cout << "\n insert child  in parent tree map";

		if (rootList.find(par) == rootList.end()) {
			//cout << "\n add as root  : par=" << par ;
			rootList[par]=true;
		}

		if (rootList.find(child) != rootList.end()) {
			//cout << "\n remove as root  child: par=" << child;
			rootList[child]= false;
		}
		else {
			//cout << "\n ADD child as false: child=" << child;
			rootList[child] = false;
		}
	}

	for (auto itr = rootList.begin(); itr != rootList.end(); ++itr) {
		if(itr->second)
			printList(itr->first, treeMap, 1);
	}
}
//=====================================================
void BuildTreeRelationship() {
	FUNC_START;
	vector<pair<string, string>>  anmalOrder{ {"animal", "bird"}
											, { "animal", "fish" }
											, { "lifeform", "animal" }
											, { "mammal", "cat" }
											, { "animal", "mammal" }
											, { "cat","lion" }
											, { "bird", "parrot" }
											, { "bird", "cuckoo" } };

	buildTree(anmalOrder);

	FUNC_END;
}
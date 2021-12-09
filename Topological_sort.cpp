#include "common.h"
#include <iostream>

#include <vector>
#include <tuple>
#include <queue>
#include <list>
#include <stack>
using namespace std;

struct GraphMatrix {
	int E;
	int V;
	vector<vector<int>> adj;
};

void createInitMatrix_ts(vector<vector<int>>& graph, int V, int dv = 0)
{
	for (int i = 0; i < V; ++i) {
		vector<int> v;
		graph.push_back(v);
		for (int j = 0; j < V; ++j) {
			graph[i].push_back(dv);
		}
	}
}
//--------------------------------------------------------
void InitGraph_ts(GraphMatrix& graph, int V, int E
	, vector<pair<int, int>>& edges) {
	graph.V = 5;
	graph.E = 10;
	createInitMatrix_ts(graph.adj, V, 0);
	for (auto e = edges.begin(); e != edges.end(); ++e) {
		graph.adj[e->first][e->second] = 1;
		graph.adj[e->second][e->first] = 1;
	}
}
void printGraph_ts(GraphMatrix& graph) {
	cout << "\n content of graph is";
	for (int i = 0; i < graph.V; ++i) {
		cout << endl;
		for (int j = 0; j < graph.V; ++j) {
			cout << "  " << graph.adj[i][j];
		}
	}
	cout << endl;
}

//==================================================================
void  TopologicalSort(GraphMatrix& graph , int u 
	, vector<int> &visited, stack<int>& st)
{
	visited[u] = 1;
	
	for (int v = 0; v < graph.V; ++v) {
		if ((graph.adj[u][v] == 1) && (visited[v]==0)) {
			TopologicalSort(graph,v,visited,st);
		}
	}
	st.push(u);
}
//==================================================================
void  RunTopologicalSort(GraphMatrix &graph) {
	stack<int> st;
	vector<int> visited = vector<int>(graph.V , 0);
	for (int u = 0; u < graph.V; ++u)
	{
		if (visited[u] == 0) {
			TopologicalSort(graph, u, visited, st);
		}
	}
	cout << "\n topological sequence is :: ";
	while (!st.empty()) {
		cout << "\t" << st.top();
		st.pop();
	}
}
//=============================================================
void Driver_TopologicalSort() {
	cout << "\n Driver_TopologicalSort started" << endl;
	GraphMatrix g;
	int V = 5;
	int E = 7;
	vector<pair<int, int>> edges = { {0,1}, {0,4}, {0,3},
									{1,3},
									{2,3},{2,4},
									{3,4} };
	InitGraph_ts(g, V, E, edges);
	printGraph_ts(g);

	RunTopologicalSort(g);

	cout << "\n Driver_TopologicalSort ended" << endl;
}
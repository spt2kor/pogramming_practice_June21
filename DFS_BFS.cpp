#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct GraphMatrix {
	int E;
	int V;
	vector<vector<int>> adj;
};

void createInitMatrix(vector<vector<int>> &graph, int V , int dv=0)
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
void InitGraph(GraphMatrix& graph , int V, int E
	, vector<pair<int,int>> &edges) {
	graph.V = 5;
	graph.E = 10;	
	createInitMatrix(graph.adj, V, 0);
	for (auto e = edges.begin(); e != edges.end(); ++e) {
		graph.adj[e->first][e->second] = 1;
		graph.adj[e->second][e->first] = 1;
	}
}
void printGraph(GraphMatrix& graph) {
	cout << "\n content of graph is";
	for (int i = 0; i < graph.V; ++i) {
		cout << endl;
		for (int j = 0; j < graph.V; ++j) {
			cout<<"  "<<graph.adj[i][j];
		}
	}
	cout << endl;
}
//------------------------------------
void DFSHelper(GraphMatrix& graph, int start, vector<int> &visited)
{
	visited[start] = 1;
	cout << "\t" << start;
	for (int i = 0; i < graph.V; ++i) {
		if ((visited[i] == 0) && (graph.adj[start][i] == 1)) {
			DFSHelper(graph, i, visited);
		}
	}
}

void PrintDFS(GraphMatrix& graph)
{
	vector<int> visited;
	for (int i = 0; i < graph.V; ++i) {
		visited.push_back(0);
	}
	cout << "\n DFS sequence is :";
	for (int i = 0; i < graph.V; ++i) 
	{		
		if (visited[i] == 0)
		{
			DFSHelper(graph , i , visited);
		}
	}
}
//------------------------------------
void BFSHelper(GraphMatrix& graph, int start, vector<int>& visited) 
{
	queue<int> qu;
	qu.push(start);
	visited[start] = 1;
	
	while (!qu.empty()) {
		int u = qu.front();
		qu.pop();
		cout << "\t" << u;
		for (int i = 0; i < graph.V; ++i) {
			if ((visited[i] == 0) && (graph.adj[u][i] == 1)) {
				qu.push(i);
				visited[i] = 1;
			}
		}

	}
}

void PrintBFS(GraphMatrix& graph)
{
	vector<int> visited;
	for(int i=0;i<graph.V;++i)
		visited.push_back(0);
	cout << "\n BFS sequence is : ";
	for (int i = 0; i < graph.V; ++i) 
	{
		if (visited[i] == 0)
			BFSHelper(graph, i , visited);
	}
	cout << endl;
}
//=========================
void driver_DFS_BFS()
{
	cout << "\n program started" << endl;
	GraphMatrix g;
	int V = 5;
	int E = 7;
	vector<pair<int, int>> edges = { {0,1}, {0,4}, {0,3},
									{1,3},
									{2,3},{2,4},
									{3,4} };
	InitGraph(g,V,E,edges );
	printGraph(g);

	PrintDFS(g);
	PrintBFS(g);
}
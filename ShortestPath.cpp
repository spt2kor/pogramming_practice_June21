#include <iostream>

#include <vector>
#include <tuple>
#include <queue>
#include <list>
#include <queue>
#include "common.h"
using namespace std;

struct GraphList {
	int V;
	int E;
	vector< list< pair<int,int> >> adj;   // 0 -> 1,40 -> 3,100
};
void PrintGraph(GraphList& graph) {
	cout << "\n current graph is :" << endl;
	for (int i = 0; i < graph.V; ++i) {
		cout << "\n vertex = " << i;
		for (auto& itr : graph.adj[i]) {
			cout << "\t (" << itr.first << "," << itr.second << ")";
		}
	}
}
void CreateInitGraph(GraphList& graph, int V, vector<tuple<int, int, int>>& edges)
{
	graph.V = V;
	graph.E = edges.size();
	for (int i = 0; i < V; ++i) {
		list<pair<int,int>> lst;
		graph.adj.push_back(lst);
	}

	for (auto e = edges.begin(); e != edges.end(); ++e)
	{
		auto u = get<0>(*e);
		auto v = get<1>(*e);
		auto w = get<2>(*e);
		graph.adj[u].push_back(pair<int,int>(v,w));
	}
	PrintGraph(graph);
}

//--------------------------------------------------------------------------------
bool compare(pair<int, int>& left, pair<int, int>& right)
{
	return left.second < right.second;
}
int getMin(std::vector < pair<int, int>> &pq, vector<int> &visited) {
	int min = INT_MAX;
	int pos = -1;
	for (int i = 0; i < pq.size(); ++i) {
		int dist = pq[i].second;
		if ((visited[i] == 0) && (dist != INT_MAX) && ( dist < min)) {
			min = dist;
			pos = i;
		}
	}
	return pos;
}

char print_vector(vector<int>& v) {
	for (auto& x : v) {
		cout << "\t" << x;
	}
	return ' ';
}
char print_vector_pair(vector<pair<int,int>>& v) {
	for (auto& x : v) {
		cout << "\t(" << x.first<<","<<x.second<<")";
	}
	return ' ';
}

void RunDikstra(GraphList& graph)
{
	vector<int> visited = vector<int>(graph.V , 0);
	vector<int> dist    = vector<int>(graph.V, INT_MAX);
	vector<int> parent  = vector<int>(graph.V, -1);

	dist[0] = 0;
	//loc,data
	std::vector < pair<int, int>> pq { {0,0}
								     , {1,INT_MAX}
									 , {2,INT_MAX} 
									 , {3,INT_MAX}
									 , {4,INT_MAX}
									 , {5,INT_MAX}
									 , {6,INT_MAX}	};
	// start vertax 0, with distance 0
	int u  ;
	cout << "\n******\n Print dist: ";	print_vector(dist) ;
	cout << "\n Print visited: ";	print_vector(visited);
	cout << "\n Print parent: ";print_vector(parent) ;
	cout << "\n Print priority queue raw array: "; print_vector_pair(pq);;


	while ((u = getMin(pq, visited)) != -1) {
		cout << "\n$$$$$$$\n Print dist: ";	print_vector(dist);
		cout << "\n Print visited: ";	print_vector(visited);
		cout << "\n Print parent: "; print_vector(parent);
		cout << "\n Print priority queue raw array: "; print_vector_pair(pq);;
		cout << "\n new min = " << u << endl;
		visited[u] = 1;
		auto itr = graph.adj[u].begin();
		auto itr_end = graph.adj[u].end();
		while (itr != itr_end) {
			int v = itr->first;
			int w = itr->second;
			if ((visited[v] == 0) && 
				(dist[v] ==INT_MAX)  || (dist[v] > dist[u]+w) )
			{
				dist[v] = dist[u] + w;
				parent[v] = u;
				pq[v].second = dist[v];
				cout << "\n u = " << u << ", v = " << v << ", dist[u] = " << dist[u]
					<< ", dist[v] = " << dist[v] << ", w = " << w;
			}
			++itr;
		}
	}

	cout << "\n******\n Print dist: ";	print_vector(dist);
	cout << "\n Print visited: ";	print_vector(visited);
	cout << "\n Print parent: "; print_vector(parent);
	cout << "\n Print priority queue raw array: "; print_vector_pair(pq);;

}
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
void RunBellmenFort(GraphList& graph, vector<tuple<int, int, int>> &edges)
{
	vector<int> dist = vector<int>( graph.V, INT_MAX );
	vector<int> parent = vector<int>( graph.V, -1 );
	dist[0] = 0;
	for (int i = 0; i < graph.V - 1; ++i) {
		cout << "\n******\n Print dist: ";	print_vector(dist);
		cout << "\n Print parent: "; print_vector(parent);
		bool changed = false;
		for (auto& e : edges) {
			auto u = std::get<0>(e);
			auto v = std::get<1>(e);
			auto w = std::get<2>(e);
			if ((dist[u] != INT_MAX) && (dist[u] + w < dist[v])) {
				dist[v] = dist[u] + w;
				parent[v] = u;
				cout << "\n u = " << u << ", v = " << v << ", dist[u] = " << dist[u]
					<< ", dist[v] = " << dist[v] << ", w = " << w << ", parent[v] =" << parent[v];
				changed = true;
			}
		}

		if (changed == false)
			break;
	}
	cout << "\n******\n Print dist: ";	print_vector(dist);
	cout << "\n Print parent: "; print_vector(parent);

	for (auto e : edges) {
		auto u = std::get<0>(e);
		auto v = std::get<1>(e);
		auto w = std::get<2>(e);
		if ((dist[u] != INT_MAX) && (dist[u] + w < dist[v])) {
			dist[v] = dist[u] + w;
			parent[v] = u;
			cout << "\n u = " << u << ", v = " << v << ", dist[u] = " << dist[u]
				<< ", dist[v] = " << dist[v] << ", w = " << w<<", parent[v] ="<<parent[v];
			
			cout << "\n $$$$ Graph has negative cycle, cannot find SP using bellman ford also, exiting!!!!" << endl;
			return;
		}
	}
	for (int i = 0; i < graph.V; ++i)
	{
		cout << "\n path of node =" << i << ", is : \t";
		int pos = i;
		while (pos != -1) {
			cout << pos << " <- ";
			pos = parent[pos];
		}

	}
}
//==============================
//shortest path algorithms
void driver_Dijkstra_SP_Algo() {
	cout << "\n driver_Dijkstra_SP_Algo started" << endl;
	vector<tuple<int, int,int>> edges = { tuple<int,int,int>(0,1,5)
										, tuple<int,int,int>(0,3,9) 
										, tuple<int,int,int>(0,4,2) 
										, tuple<int,int,int>(0,5,3) 
										, tuple<int,int,int>(1,2,2)
										, tuple<int,int,int>(1,3,1) 
										, tuple<int,int,int>(2,3,6)
										, tuple<int,int,int>(3,4,7)
										, tuple<int,int,int>(4,5,6)
										, tuple<int,int,int>(4,6,10) 
	};
	int V = 7;
	GraphList graph;
	CreateInitGraph(graph , V, edges);
	RunDikstra(graph);
	
	cout << "\n driver_Dijkstra_SP_Algo ended" << endl;
}
//-------------------------------------------------
void driver_Bellman_SP_Algo() {
	cout << "\n driver_Bellman_SP_Algo started" << endl;
	vector<tuple<int, int, int>> edges = { tuple<int,int,int>(0,1,5)
										, tuple<int,int,int>(0,3,9)
										, tuple<int,int,int>(0,4,2)
										, tuple<int,int,int>(0,5,3)
										, tuple<int,int,int>(1,2,2)
										, tuple<int,int,int>(1,3,1)
										, tuple<int,int,int>(2,3,6)
										, tuple<int,int,int>(3,4,7)
										, tuple<int,int,int>(4,5,6)
										, tuple<int,int,int>(4,6,10)
	};
	int V = 7;
	edges.push_back(tuple<int, int, int>(3, 6, -5));
	edges.push_back(tuple<int, int, int>(5, 2, -1));
	edges.push_back(tuple<int, int, int>(6, 2, -1));
	GraphList graph1;
	CreateInitGraph(graph1, V, edges);
	RunBellmenFort(graph1, edges);
	cout << "\n driver_Bellman_SP_Algo ended" << endl;
}
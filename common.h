#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;
//================================
#define FUNC_START {cout<<"\n function started "<<__FUNCTION__<<endl;}
#define FUNC_END {cout<<"\n function Ended "<<__FUNCTION__<<endl;}

void driver_Dijkstra_SP_Algo();
void driver_Bellman_SP_Algo();
void Driver_TopologicalSort();
void runTestApp();
void BuildTreeRelationship();
void threeTripletSumProblem();
void FindFourSumProblem();
int GetTopThreeLargestElementsDriver();
int KthSmalllestNoInArray();
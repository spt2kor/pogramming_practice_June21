#include <iostream>
#include "common.h"
#include <vector>
using namespace std;


/*
Input: [5, 12, 11, -1, 12], K = 3
Output: 11
Explanation: The 3rd smallest number is '11', as the first two small numbers are [5, -1].
*/
void swap_k(vector<int>& v, int a, int b)
{
	int t = v[a];
	v[a] = v[b];
	v[b] = t;
}
int pivot_k(vector<int>& v, int s, int e)
{
	cout << "\n\n pivot = s=" << s << ", e=" << e<<", ";
	if (s >= e)
		return s;

	int p = v[e];
	int i = s;
	while (i < e) {
		while ((v[i] >= p) && i < e)
			++i;

		if (i >= e)
			break;

		if(s != i)
			swap_k(v, s, i);
		++s;
		++i;
	}
	swap_k(v, s, e);
	cout << ", pivot = " << s<<", array : ";
	for (auto& x : v)
		cout << "\t" << x;
	return s;
}
// 5, 12, 11, -1, 12
int QuickSelect(vector<int>& v, int s, int e, int k) {
	cout << "\n\n qucik_select s=" << s << " , e = " << e;
	if (s >= e && (s == k - 1)) {
		return v[s];
	}
	int pi = pivot_k(v,s,e);
	if (pi == k-1)
	{
		return v[pi];
	}
	else if(pi < k)
		QuickSelect(v, pi+1, e, k);
	else
		QuickSelect(v, s, pi-1, k);
}
//---------------------
int KthSmalllestNoInArray_helper(vector<int>& v, int k) {
	if (k == 0 || v.empty())
		return -1;

	return QuickSelect(v, 0,v.size()-1,k);
}
//======================
int KthSmalllestNoInArray() {

	vector<int> v{ 5, 12, 11, -1, 12 };
	//int k = 1;
	for (int k = 1; k < v.size() + 1; ++k)
	{
		int res = KthSmalllestNoInArray_helper(v, k);
		cout << "\n "<<k<<" smallest is :" << res;
	}
	return 0;
}
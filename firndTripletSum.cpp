#include "common.h"
#include <vector>

using namespace std;
void printVector(vector<int>& a) {
	cout << "\n array content: ";
	for (auto& x : a) {
		cout << "\t" << x;
	}
	cout << endl;
}
void swap(vector<int>& array, int a, int b)
{
	auto t = array[a];
	array[a] = array[b];
	array[b] = t;
}

int pivot(vector<int>& array, int lo, int hi)
{
	
	if (hi <= lo)
		return lo;
	FUNC_START;
	auto p = lo;
	auto i = lo;
	auto j = hi;
	printVector(array);
	cout << "\n  p=" << array[p] << "\tlo=" << array[lo] << "\thi=" << array[hi] << endl;


	while (i <= j)
	{
		while (array[i] <= array[p] && i <= hi)
		{
			++i;	
			if (i > hi) {
				i = hi; break;
			}
		}

		while (array[j] > array[p] && lo <= j)
		{
			--j;
			if (j < lo)
			{
				j = lo;
				break;
			}
		}
		if (i < j)
		{
			swap(array, i, j);
		}
		else
			break;
		cout << "\np=" << array[p] << "\t i=" << array[i] << "\t j=" << array[j] << endl;
		printVector(array);
	}
	swap(array, j, p);
	
	printVector(array);
	FUNC_END;
	return j;
}

void QuickSort(vector<int>& array, int lo, int hi)
{
	if (hi <= lo)
		return;

	auto p = pivot(array, lo, hi);
	QuickSort(array, lo, p - 1);
	QuickSort(array, p + 1, hi);
}

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
	// Write your code here.
	auto& a = array;
	vector<vector<int>> res;
	auto size = a.size();
	if (size > 2)
	{
		printVector(array);
		cout << "\n Quick Sort" << endl;
		QuickSort(a, 0, size - 1);
		cout << "\n array after sort: ";
		for (auto& x : a) {
			cout << "\t" << x;
		}
		cout<<endl;
		vector<int> r;
		for (int i = 0; i < size - 2; ++i)
		{
			auto lo = i + 1;
			auto hi = size - 1;
			auto sum = targetSum - a[i];
			while (lo < hi)
			{
				auto rem = a[lo] + a[hi];
				if (sum == rem)
				{
					r.push_back(a[i]);
					r.push_back(a[lo]);
					r.push_back(a[hi]);
					res.push_back(r);
					r.clear();
					--hi;
					++lo;
				}
				else if (sum < rem)
				{
					--hi;
				}
				else// sum>rem
				{
					++lo;
				}
			}
		}
	}
	return res;
}

void threeTripletSumProblem()
{
	FUNC_START;

	vector<int> array = { 12, 3, 1, 2, -6, 5, -8, 6 };
	int targetSum = 0;

	vector<vector<int>> res = threeNumberSum(array, targetSum);
	cout << "\n result: " << endl;
	for (auto& v : res) {
		cout << endl;
		for (auto& x : v) {
			cout << "\t" << x;
		}
	}
	FUNC_END;
}
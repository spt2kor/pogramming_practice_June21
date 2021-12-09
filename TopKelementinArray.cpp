
/*
Given an unsorted array of numbers, find the ‘K’ largest numbers in it.

Input: [3, 1, 5, 12, 2, 11], K = 3
Output: [5, 12, 11]

Input: [5, 12, 11, -1, 12], K = 3
Output: [12, 11, 12]

test cases
	k=0 or k is negative
		return empty
	arr.size() <= k
		return complete array
	arr.size()>k;
		go with min heap.
	
	complexity - build heap =>O(K logK), iterate all element - NlogK => total = NlogK
	space = O(N)
	
*/
#include "common.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//-------------------------------

vector<int> GetTopThreeLargestElements(vector<int>& arr, int k)
{
	vector<int> res;
	if(k <= 0)
		return res;
	
	if(arr.size() <= k ){
		res.assign(arr.begin(),arr.end());
		return res;
	}
	
	priority_queue<int,vector<int> , greater<int>> minHeap(arr.begin() ,arr.begin()+k);
	//cout << "\n heap elements: ";
	//while (!minHeap.empty()) {
	//	cout<<"\t"<<minHeap.top();
	//	minHeap.pop();
	//}

	for(int i=k ; i< arr.size() ; ++i){
		int no = minHeap.top();
		cout << "\n heap top: " << no <<", arr[k] = "<<arr[k];
		if(arr[i] > no){
			cout << "\n heap pop: " << no;
			minHeap.pop();
			minHeap.push(arr[i]);
		}
	}
	
	while(! minHeap.empty()){
		res.push_back(minHeap.top());
		minHeap.pop();
	}
	
	return res;
}
 
void driver(vector<int>& arr, int k) {
	vector<int> res= GetTopThreeLargestElements(arr, k);

	cout << "\n res  : ";
	for (auto& x : res) {
		cout << "\t" << x;
	}
}
 

//-------------------------------
int GetTopThreeLargestElementsDriver()
{
	vector<int> arr1{ 3, 1, 5, 12, 2, 11 };
	int K1 = 3;
	driver(arr1, K1);
	
	//-------------------------------
	vector<int> arr2{5, 12, 11, -1, 12};
	int K2 = 3;
	driver(arr2, K2);
	
	return 0;
}
#pragma once

#include <iostream>
#include <vector>
using namespace std;

class Priority_Queue
{
	vector<int>	data;
	int size;
	int capacity;

	void Build_Heap();
	int left_child(int pos);
	int right_child(int pos);
	int parent(int pos);
	void swap(int a, int b);
	void Heapify_Up(int loc);
	void Heapify_Down(int loc);
public:
	Priority_Queue(int capacity);
			
	Priority_Queue(int capacity, vector<int> dat);
	
	void Insert(int val);

	int GetMin();
	int Size();
	int Capacity();
	void Print();
};
void Driver_Priority_queue();
void Driver_Priority_queue_One_by_one();
#include "Priority_Queue.h"

Priority_Queue::Priority_Queue( int capacity)
	: capacity(capacity)
	, size(-1), data(vector<int>(capacity, INT_MAX))
{
}

Priority_Queue::Priority_Queue( int capacity, vector<int> dat)
	: capacity(capacity)
	, data(dat), size(dat.size()-1)
{
	Build_Heap();
}

void Priority_Queue::Insert(int val)
{
	if ((size + 1) < capacity) {
		++size;
		data[size] = val;
		
		Heapify_Up(size);
	}
}

int Priority_Queue::GetMin()
{
	if (size >= 0) {
		int min = data[0];
		data[0] = data[size];
		--size;
		Heapify_Down(0);
		return min;
	}
	return INT_MAX;
}

int Priority_Queue::Size()
{
	return size;
}

int Priority_Queue::Capacity()
{
	return capacity;
}

int Priority_Queue::left_child(int pos) {
	return 2 * pos + 1;
}

int Priority_Queue::right_child(int pos) {
	return 2 * pos + 2;
}

int Priority_Queue::parent(int pos) {
	return (pos-1)/2;
}

void Priority_Queue::Print() {
	cout << "\n Heap array Content" << endl;
	for (int i = 0; i <= size; ++i)
	{
		cout << "\t " << data[i];
	}
	
}

void Priority_Queue::swap(int a, int b) {
	int temp = data[a];
	data[a] = data[b];
	data[b] = temp;
}
//when we add an element at the last, it goes up
void Priority_Queue::Heapify_Up(int loc) {
	if (loc <= size)
	{
		int pr;
		while (loc >= 0)
		{
			pr = parent (loc);
			if (pr >= 0 && data[loc] < data[pr])
			{
				swap(loc, pr);
				loc = pr;
			}
			else
				break;
		}
	}
}

void Priority_Queue::Heapify_Down(int loc) {
	if (loc >= 0)
	{
		int rc;
		int lc;
		int pos = loc;
		while (loc <= size) {
			pos = loc;
			rc = right_child(loc);
			lc = left_child(loc);
			if (rc <= size && data[pos] > data[rc])
				pos= rc;
			if (lc <= size && data[pos] > data[lc])
				pos= lc;
			if (loc != pos) {
				swap(pos, loc);
				loc = pos;
			}
			else
				break;
		}
	}
}

void Priority_Queue::Build_Heap() {
	if (size > 0) {
		for (int i = (size - 1) / 2; i >= 0; --i) {
			Heapify_Down(i);
		}
	}
}

void Driver_Priority_queue()
{
	cout << "\n Driver_Priority_queue Start " << endl;
	vector<int> data = {3,6,10,1,8,6,9,2,6,15};
	int size = 10;

	cout << "\n Min Heap build Hepify" << endl;
	Priority_Queue pq(size, data);
	
	pq.Print();

	cout << "\n Priority queue remove in order : ";
	for (int i = 0; i < size; ++i)
	{
		cout << "\n min =  " << pq.GetMin();
		cout << "\n array content now is :";
		pq.Print();
	}

	cout << "\n Driver_Priority_queue End" << endl;
}

void Driver_Priority_queue_One_by_one()
{
	cout << "\n Driver_Priority_queue one_by_one Start " << endl;
	vector<int> data = { 3,6,10,1,8,6,9,2,6,15 };
	int size = 10;

	cout << "\n Min Heap build Hepify" << endl;
	Priority_Queue pq(size);

	pq.Print();

	cout << "\n Priority queue insert : ";
	for (int i = 0; i < size; ++i)
	{
		pq.Insert(data[i]);
		cout << "\n array content now is :";
		pq.Print();
	}

	cout << "\n***********\n Priority queue remove in order : ";
	for (int i = 0; i < size; ++i)
	{
		cout << "\n min =  " << pq.GetMin();
		cout << "\n array content now is :";
		pq.Print();
	}

	cout << "\n Driver_Priority_queue End" << endl;
}

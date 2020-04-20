#pragma once
#include <vector>
using namespace std;
template <typename T>
class Queue
{
public:
	Queue();
	bool push(T n);
	T pop();
	T front();
	int size();
	bool clear();
private:
	vector<T> items;
};
#include "queue.inl"

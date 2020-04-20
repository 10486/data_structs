#pragma once
#include <vector>
using namespace std;
template <typename T>
class Deque
{
public:
	Deque();
	bool push_front(T n);
	bool push_back(T n);
	T pop_front();
	T pop_back();
	T front();
	T back();
	int size();
	bool clear();
private:
	vector<T> items;
};
#include "Deque.inl"
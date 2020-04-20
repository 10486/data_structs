#pragma once
#include <vector>
using namespace std;
template <typename T>
class Stack
{
public:
	Stack();
	bool push(T n);
	T pop();
	T back();
	int size();
	bool clear();
private:
	vector<T> items;
};
#include "stack.inl"
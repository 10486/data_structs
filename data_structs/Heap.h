#pragma once
#include <vector>
using namespace std;
template <typename T>
class Heap
{
public:
	Heap();
	T Peak_Max();
	T Extract_Max();
	void Add(T el);
	void Delete(int i);
	int Increase_Priority(int i, int prior);
	int Decrease_Priority(int i, int prior);
private:
	vector<T> items;
};


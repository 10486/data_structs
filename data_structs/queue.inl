#ifndef Queueh
#define Queueh
#include "queue.h"
#include <vector>
using namespace std;
template <typename T>
Queue<T>::Queue() {
	items = vector<T>();
}
template <typename T>
bool Queue<T>::push(T n) {
	items.push_back(n);
	return true;
}
template <typename T>
bool Queue<T>::clear() {
	items.clear();
	return true;
}
template <typename T>
int Queue<T>::size() {
	return items.size();
}
template <typename T>
T Queue<T>::pop() {
	if (size() == 0) {
		throw new exception();
	}
	T tmp = items.front();
	for (size_t i = 1; i < size(); i++)
	{
		items[i - 1] = items[i];
	}
	items.pop_back();
	return tmp;
}
template <typename T>
T Queue<T>::front() {
	if (size() == 0) {
		throw new exception();
	}
	return items[0];
}
#endif
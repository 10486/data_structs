#ifndef Dequeh
#define Dequeh
#include <vector>
#include "Deque.h"
using namespace std;
template <typename T>
Deque<T>::Deque() {
	items = vector<T>();
}
template <typename T>
bool Deque<T>::push_back(T n) {
	items.push_back(n);
	return true;
}
template <typename T>
bool Deque<T>::push_front(T n) {
	items.insert(items.begin(), n);
	return true;
}
template <typename T>
bool Deque<T>::clear() {
	items.clear();
	return true;
}
template <typename T>
int Deque<T>::size() {
	return items.size();
}
template <typename T>
T Deque<T>::pop_back() {
	if (size() == 0) {
		throw new exception();
	}
	T tmp = items.back();
	items.pop_back();
	return tmp;
}
template <typename T>
T Deque<T>::pop_front() {
	if (size() == 0) {
		throw new exception();
	}
	T tmp = items.front();
	items.erase(items.begin(), items.begin() + 1);
	return tmp;
}
template <typename T>
T Deque<T>::back() {
	if (size() == 0) {
		throw new exception();
	}
	return items[items.size() - 1];
}
template <typename T>
T Deque<T>::front() {
	if (size() == 0) {
		throw new exception();
	}
	return items[0];
}
#endif
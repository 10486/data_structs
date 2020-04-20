#ifndef Stackh
#define Stackh
#include <vector>
#include "stack.h"
using namespace std;
template <typename T>
Stack<T>::Stack() {
	items = vector<T>();
}
template <typename T>
bool Stack<T>::push(T n) {
	items.push_back(n);
	return true;
}
template <typename T>
T Stack<T>::pop() {
	if (size() == 0) {
		throw new exception();
	}
	T tmp = items.back();
	items.pop_back();
	return tmp;
}
template <typename T>
T Stack<T>::back() {
	if (size() == 0) {
		throw new exception();
	}
	return items[items.size() - 1];
}
template <typename T>
bool Stack<T>::clear() {
	items.clear();
	return true;
}
template <typename T>
int Stack<T>::size() {
	return items.size();
}
#endif
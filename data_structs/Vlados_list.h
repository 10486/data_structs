#pragma once
template <typename T>
class Vlados_list
{
	template <typename T>
	class Node {
	public:
		Node<T>(T el) {
			data = el;
		}
		T data;
		Node<T>* next;
		Node<T>* prev;
	};
public:
	T front();
	T back();
	bool push_back(T e);
	bool push_front(T e);
	T pop_back();
	T pop_front();
	long long size();
	bool clear();
	T& operator[] (const int index);
private:
	long long size_l;
	Node<T>* head;
	Node<T>* tail;
};
#include "Vlados_list.inl"

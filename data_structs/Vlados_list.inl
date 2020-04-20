#ifndef Listh
#define Listh
#include "Vlados_list.h"
template <typename T>
T Vlados_list<T>::back() {
	return tail->data;
}
template <typename T>
T Vlados_list<T>::front() {
	return head->data;
}
template <typename T>
bool Vlados_list<T>::push_back(T el) {
	if (head == nullptr) {
		head = new Node<T>(el);
		tail = head;
	}
	else {
		Node<T>* t = new Node<T>(el);
		tail->next = t;
		t->prev = tail;
		tail = tail->next;
	}
	size_l++;
	return true;
}
template <typename T>
bool Vlados_list<T>::push_front(T el) {
	if (head == nullptr) {
		head = new Node<T>(el);
		tail = head;
	}
	else {
		Node<T>* t = new Node<T>(el);
		head->prev = t;
		t->next = head;
		head = head->prev;
	}
	size_l++;
	return true;
}
template <typename T>
T Vlados_list<T>::pop_back() {
	T tmp = tail->data;
	if (tail == head) {
		delete tail;
		tail = head = nullptr;

	}
	else {
		tail = tail->prev;
		delete tail->next;
		tail->next = nullptr;
	}
	size_l--;
	return tmp;
}
template <typename T>
T Vlados_list<T>::pop_front() {
	T tmp = head->data;
	if (tail == head) {
		delete head;
		tail = head = nullptr;

	}
	else {
		head = head->next;
		delete head->prev;
		head->prev = nullptr;
	}
	size_l--;
	return tmp;
}
template <typename T>
long long Vlados_list<T>::size() {
	return size_l;
}
template <typename T>
bool Vlados_list<T>::clear() {
	if (size_l > 0) {
		for (auto i = tail->prev; i != nullptr; i = i->prev)
		{
			delete i->next;
		}
		delete head;
		tail = head = nullptr;
		size_l = 0;
	}
	return true;
}
template <typename T>
T& Vlados_list<T>::operator[] (const int index) {
	auto tmp = head;
	for (size_t i = 0; i < index; i++)
	{
		tmp = tmp->next;
	}
	return tmp->data;
}
template <typename T>
bool Vlados_list<T>::insert(int index, T el) {
	if (index > 0) {
		auto next = this[index];
		auto prev = next.prev;
		prev.next = new Node<T>(el);
		next.prev = prev.next;
	}
	else {
		push_front(el);
	}
	return true;
}
#endif
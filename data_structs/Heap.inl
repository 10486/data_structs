#ifndef Heaph
#define Heaph
#include "Heap.h"
#include <vector>
using namespace std;
template <typename T>
T& Heap<T>::operator[](const int i) {
	return items[i];
}
template <typename T>
Heap<T>::Heap() {
	items = vector<Node<T>*>();
}
template <typename T>
Heap<T>::Heap(vector<T> d, vector<int> s) {
	items.reserve(d.size());
	for (size_t i = 0; i < d.size(); i++)
	{
		items.push_back(new Node<T>(d[i], s[i]));
	}
	size = items.size();
	for (int i = size - 1; i >= 0; i--)
	{
		Shift_Down(i);
	}
}
template <typename T>
void Heap<T>::Add(T el) {
	items.push_back(el);
	int i = items.size() - 1;
	Shift_Up(i);
	size++;
}
template <typename T> 
T Heap<T>::Peak_Max() {
	return items.front()->data;
}
template <typename T>
T Heap<T>::Extract_Max() {
	T tmp = items.front()->data;
	Delete(0);
	return tmp;
}
template <typename T>
void Heap<T>::Delete(int ind) {
	int i = ind;
	delete items[i];
	items[i] = items.back();
	items.pop_back();
	if (size > 0)size--;
	if(size)Shift_Down(Shift_Up(i));
}
template <typename T>
vector<T> Heap<T>::Get_Items() {
	return vector<Node<T>*>(items);
}
template <typename T>
int Heap<T>::Increase_Priority(int i, int prior) {
	items[i]->Change_Prior(prior);
	return Shift_Up(i);
}
template <typename T>
int Heap<T>::Decrease_Priority(int i, int prior) {
	items[i]->Change_Prior(-prior);
	return Shift_Down(i);
}
template <typename T>
int Heap<T>::Shift_Up(int i) {
	int par_ind = (i - 1) / 2;
	Node<T>* tmp;
	while (par_ind >= 0 && *(items[par_ind]) < *(items[i])) {
		tmp = items[par_ind];
		items[par_ind] = items[i];
		items[i] = tmp;
		i = par_ind;
		par_ind = (par_ind - 1) / 2;
	}
	return i;
}
template <typename T>
int Heap<T>::Shift_Down(int i) {
	int f_node_ind = i * 2 + 1;
	int s_node_ind = f_node_ind + 1;
	Node<T>* t;
	while (s_node_ind < items.size()) {
		if (*(items[f_node_ind]) > *(items[s_node_ind]) && *(items[f_node_ind]) > *(items[i])) {
			t = items[i];
			items[i] = items[f_node_ind];
			items[f_node_ind] = t;
			i = f_node_ind;
		}
		else if (*(items[s_node_ind]) > *(items[f_node_ind]) && *(items[s_node_ind]) > *(items[i])) {
			t = items[i];
			items[i] = items[s_node_ind];
			items[s_node_ind] = t;
			i = s_node_ind;
		}
		else {
			break;
		}
		f_node_ind = i * 2 + 1;
		s_node_ind = f_node_ind + 1;
	}
	if (f_node_ind < items.size() && *(items[i]) < *(items[f_node_ind])) {
		t = items[i];
		items[i] = items[f_node_ind];
		items[f_node_ind] = t;
		i = f_node_ind;
	}
	return i;
}
#endif
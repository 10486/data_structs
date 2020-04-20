#ifndef Heaph
#define Heaph
#include "Heap.h"
#include <vector>
using namespace std;
template <typename T>
Heap<T>::Heap() {
	items = vector<T>();
}
template <typename T>
void Heap<T>::Add(T el) {
	items.pop_back(el);
	int i = items.size() - 1;
	int par_ind = (i - 1) / 2;
	while (par_ind >= 0 && el > items[i]) {
		auto tmp = items[par_ind];
		items[par_ind] = el;
		items[i] = tmp;
		i = par_ind;
		par_ind = (par_ind - 1) / 2;
	}
}
template <typename T> 
T Heap<T>::Peak_Max() {
	return items.front();
}
template <typename T>
T Heap<T>::Extract_Max() {
	T tmp = items.front();
	items[0] = items.back();
	items.pop_back();
	int i = 0;
	int f_node_ind = i * 2 + 1;
	int s_node_ind = f_node_ind + 1;
	T t;
	while (s_node_ind < items.size()) {
		if (items[f_node_ind] > items[s_node_ind] && items[f_node_ind] > items[i]) {
			t = items[i];
			items[i] = items[f_node_ind];
			items[f_node_ind] = t;
			i = f_node_ind;
		}
		else if (items[s_node_ind] > items[f_node_ind] && items[s_node_ind] > items[i]) {
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
	if (f_node_ind < items.size() && items[i] < items[f_node_ind]) {
		t = items[i];
		items[i] = items[f_node_ind];
		items[f_node_ind] = t;
	}
	return tmp;
}
template <typename T>
void Heap<T>::Delete(int ind) {
	int i = ind;
	int f_node_ind = i * 2 + 1;
	int s_node_ind = f_node_ind + 1;
	T t;
	while (s_node_ind < items.size()) {
		if (items[f_node_ind] > items[s_node_ind] && items[f_node_ind] > items[i]) {
			t = items[i];
			items[i] = items[f_node_ind];
			items[f_node_ind] = t;
			i = f_node_ind;
		}
		else if (items[s_node_ind] > items[f_node_ind] && items[s_node_ind] > items[i]) {
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
	if (f_node_ind < items.size() && items[i] < items[f_node_ind]) {
		t = items[i];
		items[i] = items[f_node_ind];
		items[f_node_ind] = t;
	}
}
#endif
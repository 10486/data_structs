#ifndef BinTreeh
#define BinTreeh
#include "Binary_tree.h"
template <typename T>
int Binary_tree<T>::max_depth() {
	return Binary_tree<T>::max_dep(root);
}
template <typename T>
void Binary_tree<T>::add(T el) {
	if (root == nullptr) {
		root = new Node<T>(el);
	}
	else {
		Binary_tree<T>::add_el(root, el);
	}
}
template <typename T>
void Binary_tree<T>::del(T el) {
	Binary_tree<T>::del_el(root, el);
}
template <typename T>
bool Binary_tree<T>::find(T el) {
	return Binary_tree<T>::find_el(root, el);
}
template <typename T>
list<T> Binary_tree<T>::prefix() {
	return Binary_tree<T>::prefix_traverse(root);
}
template <typename T>
list<T> Binary_tree<T>::infix() {
	return Binary_tree<T>::infix_traverse(root);
}
template <typename T>
list<T> Binary_tree<T>::postfix() {
	return Binary_tree<T>::postfix_traverse(root);
}
#endif

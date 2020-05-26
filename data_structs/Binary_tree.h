#pragma once
#include <list>
using namespace std;
template <typename T>
class Binary_tree
{
public:
	template <typename K>
	struct Node {
	public:
		Node<K>(K el) {
			data = el;
		}
		K data;
		Node<K>* parent;
		Node<K>* left;
		Node<K>* right;
	};
	void add(T el);
	void del(T el);
	bool find(T el);
	list<T> infix();
	list<T> postfix();
	list<T> prefix();
	int max_depth();
private:
	Node<T>* root;
	static void add_el(Node<T>* node, T el) {
		if (node->data == el) {
			return;
		}
		if (el < node->data && node->left == nullptr) {
			node->left = new Node<T>(el);
			node->left->parent = node;
		}
		else if (el > node->data&& node->right == nullptr) {
			node->right = new Node<T>(el);
			node->right->parent = node;
		}
		else if (el < node->data) {
			Binary_tree<T>::add_el(node->left, el);
		}
		else {
			Binary_tree<T>::add_el(node->right, el);
		}
	}
	static void del_el(Node<T>* node, T el) {
		if (node == nullptr)return;
		if (node->data == el) {
			if (node->left == nullptr && node->right == nullptr) {
				if (node->data > node->parent->data) {
					node->parent->right = nullptr;
				}
				else {
					node->parent->left = nullptr;
				}
			}
			else if (node->left == nullptr) {
				if (node->data > node->parent->data) {
					node->parent->right = node->right;
				}
				else {
					node->parent->left = node->right;
				}
			}
			else if (node->right == nullptr) {
				if (node->data > node->parent->data) {
					node->parent->right = node->left;
				}
				else {
					node->parent->left = node->left;
				}
			}
			else {
				Node<T>* tmp = node->right;
				while (tmp->left != nullptr) {
					tmp = tmp->left;
				}
				if (node->data > node->parent->data) {
					node->parent->right = tmp;
				}
				else {
					node->parent->left = tmp;
				}
				tmp->parent->left = nullptr;
				tmp->left = node->left;
				tmp->right = node->right;
				tmp->parent = node->parent;
			}
			delete node;
		}
		else if (el > node) {
			Binary_tree<T>::del_el(node->right, el);
		}
		else {
			Binary_tree<T>::del_el(node->left, el);
		}
	}
	static bool find_el(Node<T>* node, T el) {
		if (node == nullptr)return  false;
		if (node->data == el)return true;
		else return (node->data < el ? Binary_tree<T>::find_el(node->left, el) : Binary_tree<T>::find_el(node->right, el));
	}
	static list<T> prefix_traverse(Node<T>* node) {
		if (node == nullptr)return list<T>();
		auto l = Binary_tree<T>::prefix_traverse(node->left);
		auto r = Binary_tree<T>::prefix_traverse(node->right);
		l.push_front(node->data);
		l.insert(l.end(), r.begin(), r.end());
		return l;
	}
	static list<T> infix_traverse(Node<T>* node) {
		if (node == nullptr)return list<T>();
		auto l = Binary_tree<T>::infix_traverse(node->left);
		auto r = Binary_tree<T>::infix_traverse(node->right);
		l.push_back(node->data);
		l.insert(l.end(), r.begin(), r.end());
		return l;
	}
	static list<T> postfix_traverse(Node<T>* node) {
		if (node == nullptr)return list<T>();
		auto l = Binary_tree<T>::postfix_traverse(node->left);
		auto r = Binary_tree<T>::postfix_traverse(node->right);
		l.insert(l.end(), r.begin(), r.end());
		l.push_back(node->data);
		return l;
	}
	static int max_dep(Node<T>* n) {
		if (n == nullptr)return 0;
		return max(Binary_tree<T>::max_dep(n->left), Binary_tree<T>::max_dep(n->right)) + 1;
	}
};
#include "Binary_tree.inl"
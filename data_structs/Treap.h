#pragma once
#include <iostream>
#include <list>
using namespace std;
template <typename T>
class Treap
{
public:
	Treap<T>(T data, int key);
	Treap<T>(T data);
	Treap<T>();
	Treap<T>* Merge (Treap<T> * a, Treap<T> * b);
	Treap<T>* Merge(Treap<T>* a);
	pair<Treap<T>*,Treap<T>*> Split(T a);
	Treap<T>* Insert(T data);
	Treap<T>* Delete(T data);
	Treap<T>* Find(T data);
	list<list<Treap<T>*>> Traverse();
	Treap<T>* Insert(T data, int key);
	T X;
	int Y;
private:
	Treap<T>* Left;
	Treap<T>* Right;
	Treap<T>* Parent;
};
#include "Treap.inl"
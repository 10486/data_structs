#pragma once
#include <vector>
using namespace std;
template <typename T>
class Heap
{
public:
	template <typename K>
	struct Node
	{
		int prior;
		K data;
		Node(K data, int p) {
			this->data = data;
			this->prior = p;
		}
		Node(K data)
		{
			this->data = data;
		}
		void Chanege_Prior(int i) {
			this->prior += i;
		}
		bool operator<(const Node<K> &op) {
			return this->prior < op.prior;
		}
		bool operator>(const Node<K>& op) {
			return this->prior > op.prior;
		}
		bool operator>=(const Node<K>& op) {
			return this->prior >= op.prior;
		}
		bool operator<=(const Node<K>& op) {
			return this->prior <= op.prior;
		}
		bool operator==(const Node<K>& op){
			return this->prior == op.prior;
		}
	};
	T& operator[] (const int i);
	Heap();
	Heap(vector<T> i,vector<int> s);
	T Peak_Max();
	T Extract_Max();
	void Add(T el);
	void Delete(int i);
	int Increase_Priority(int i, int prior);
	int Decrease_Priority(int i, int prior);
	vector<T> Get_Items();
	long long size = 0;
private:
	int Shift_Up(int);
	int Shift_Down(int);
	vector<Node<T>*> items;
};

#include "Heap.inl"
#include <iostream>
#include <list>
#include <random>
using namespace std;
template <typename T>
class Treap
{
public:
	Treap<T>(T data, int key, int n) {
		this->X = data;
		this->Y = key;
		this->number = n;
	}
	Treap<T>(T data, int key) {
		this->X = data;
		this->Y = key;
	}
	Treap<T>(T data) {
		this->X = data;
		this->Y = rand();
	}
	Treap<T>();
	Treap<T>* Merge(Treap<T>* a, Treap<T>* b);
	Treap<T>* Merge(Treap<T>* a);
	pair<Treap<T>*, Treap<T>*> Split(T a);
	Treap<T>* Insert(T data);
	Treap<T>* Delete(T data);
	Treap<T>* Find(T data);
	list<list<Treap<T>*>> Traverse();
	Treap<T>* Insert(T data, int key);
	Treap<T>* Insert(T data, int key, int number);
	T X;
	int Y;
	int number;
private:
	Treap<T>* Left;
	Treap<T>* Right;
	Treap<T>* Parent;
};

template <typename T>
Treap<T>* Treap<T>::Merge(Treap<T>* a) {
	return Merge(this, a);
}
template <typename T>
Treap<T>* Treap<T>::Merge(Treap<T>* a, Treap<T>* b) {
	if (a == nullptr)return b;
	if (b == nullptr)return a;
	if (a->Y > b->Y) {
		a->Right = Merge(a, b);
		a->Right->Parent = a;
		a->Parent = nullptr;
		return a;
	}
	else {
		b->Left = Merge(b, a->Left);
		b->Left->Parent = b;
		b->Parent = nullptr;
		return b;
	}
}
template <typename T>
pair<Treap<T>*, Treap<T>*> Treap<T>::Split(T x) {
	if (this == nullptr) {
		return pair<Treap<T>*, Treap<T>*>{nullptr, nullptr};
	}
	if (this->X < x && this->Right == nullptr) {
		return pair<Treap<T>*, Treap<T>*>{this, nullptr};
	}
	if (this->X > x&& this->Left == nullptr) {
		return pair<Treap<T>*, Treap<T>*>{nullptr, this};
	}
	if (this->X < x) {
		auto p = this->Right->Split(x);
		p.second->Parent = nullptr;
		this->Right = p.first;
		if (p.first != nullptr)p.first->Parent = this;
		return pair<Treap<T>*, Treap<T>*>{this, p.second};
	}
	auto p = this->Left->Split(x);
	if (p.first != nullptr)p.first->Parent = nullptr;
	this->Left = p.second;
	if (p.second != nullptr)p.second->Parent = this;
	return pair<Treap<T>*, Treap<T>*>{p.first, this};
}
template <typename T>
Treap<T>* Treap<T>::Insert(T data) {
	int key = rand();
	return this->Insert(data, key);
}
template <typename T>
Treap<T>* Treap<T>::Insert(T data, int key) {
	if (Find(data) != nullptr)return this;
	if (key > Y) {
		auto p = this->Split(data);
		auto t = new Treap<T>(data, key);
		t->Left = p.first;
		t->Right = p.second;
		if (p.second != nullptr) {
			p.second->Parent = t;
		}if (p.first != nullptr) {
			p.first->Parent = t;
		}
		return t;
	}
	else {
		if (data < X && this->Left != nullptr) {
			this->Left = this->Left->Insert(data, key);
			this->Left->Parent = this;
		}
		else if (data > X&& this->Right != nullptr) {
			this->Right = this->Right->Insert(data, key);
			this->Right->Parent = this;
		}
		else if (data < X) {
			this->Left = new Treap<T>(data, key);
			this->Left->Parent = this;
		}
		else {
			this->Right = new Treap<T>(data, key);
			this->Right->Parent = this;
		}
		return this;
	}
}
template <typename T>
Treap<T>* Treap<T>::Insert(T data, int key,int number) {
	if (Find(data) != nullptr)return this;
	if (key > Y) {
		auto p = this->Split(data);
		auto t = new Treap<T>(data, key,number);
		t->Left = p.first;
		t->Right = p.second;
		if (p.second != nullptr) {
			p.second->Parent = t;
		}if (p.first != nullptr) {
			p.first->Parent = t;
		}
		return t;
	}
	else {
		if (data < X && this->Left != nullptr) {
			this->Left = this->Left->Insert(data, key,number);
			this->Left->Parent = this;
		}
		else if (data > X&& this->Right != nullptr) {
			this->Right = this->Right->Insert(data, key,number);
			this->Right->Parent = this;
		}
		else if (data < X) {
			this->Left = new Treap<T>(data, key,number);
			this->Left->Parent = this;
		}
		else {
			this->Right = new Treap<T>(data, key,number);
			this->Right->Parent = this;
		}
		return this;
	}
}
template <typename T>
Treap<T>* Treap<T>::Find(T data) {
	if (data == this->X)return this;
	if (data > this->X&& this->Right != nullptr) {
		return this->Right->Find(data);
	}
	if (data < this->X && this->Left != nullptr) {
		return this->Left->Find(data);
	}
	return nullptr;
}
template <typename T>
Treap<T>* Treap<T>::Delete(T data) {
	auto par = this->Find(data)->Parent;
	Treap<T>* res;
	if (par == nullptr) {
		res = Merge(this->Left, this->Right);
		delete this;
		return res;
	}
	else {
		if (par->Left->X == data) {
			res = Merge(par->Left->Left, par->Left->Right);
			delete par->Left;
			par->Left = res;
			return this;
		}
		else {
			res = Merge(par->Right->Left, par->Right->Right);
			delete par->Right;
			par->Right = res;
			return this;
		}
	}
}
template <typename T>
list<list<Treap<T>*>> Treap<T>::Traverse() {
	auto d = list<list<Treap<T>*>>();
	d.push_back(list<Treap<T>*>{this->Parent, this->Left, this->Right});
	if (this->Left != nullptr)	d.splice(d.begin(), this->Left->Traverse());
	if (this->Right != nullptr)	d.splice(d.end(), this->Right->Traverse());
	return d;
}
int main() {
	int n,tmp1,tmp2; cin >> n;
	cin >> tmp1 >> tmp2;
	try {
		auto tree = new Treap<int>(tmp1, tmp2,1);
		for (size_t i = 1; i < n; i++)
		{
			cin >> tmp1 >> tmp2;
			tree = tree->Insert(tmp1, tmp2,i+1);
		}
		cout << "YES" << endl;
		for (auto i : tree->Traverse()) {
			for (auto k : i)
			{
				cout << (k == nullptr ? 0 : k->number) << " ";
			}
			cout << endl;
		}
	}
	catch(exception e){
		cout << "NO";
	}
	
}
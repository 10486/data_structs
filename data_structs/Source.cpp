#include <iostream>
#include <vector>
#include <string>
using namespace std;
template <typename T>
class Vlados_list
{
	template <typename K>
	class Node {
	public:
		Node<K>(K el) {
			data = el;
		}
		T data;
		Node<K>* next;
		Node<K>* prev;
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
int main() {
	string command;
	int arg;
	vector<string> out = vector<string>();
	Vlados_list<int> s = Vlados_list<int>();
	cin >> command;
	while (command != "exit") {
		if (command == "push_back") {
			cin >> arg;
			if (s.push_back(arg)) {
				out.push_back("ok");
			}
		}
		else if (command == "push_front") {
			cin >> arg;
			if (s.push_front(arg)) {
				out.push_back("ok");
			}
		}
		else if (command == "pop_back") {
			out.push_back((s.size() == 0 ? "error" : to_string(s.pop_back())));
		}
		else if (command == "pop_front") {
			out.push_back((s.size() == 0 ? "error" : to_string(s.pop_front())));
		}
		else if (command == "front") {
			out.push_back((s.size() == 0 ? "error" : to_string(s.front())));
		}
		else if (command == "back") {
			out.push_back((s.size() == 0 ? "error" : to_string(s.back())));
		}
		else if (command == "clear") {
			if (s.clear()) {
				out.push_back("ok");
			}
		}
		else if (command == "size") {
			out.push_back(to_string(s.size()));
		}
		cin >> command;
	}
	for (size_t i = 0; i < out.size(); i++)
	{
		cout << out[i] << endl;
	}
	cout << "bye" << endl;
}
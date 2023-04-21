#pragma once
#include <iostream>

using namespace std;

struct Node {
	int val;
	Node* next;
	Node(int _val) : val(_val), next(nullptr) {}
};

class TList
{
protected:
	Node* first;
	Node* last;

public:
	TList() : first(nullptr), last(nullptr) {}
	
	bool is_empty() {
		return first == nullptr;
	}

	void push_back(int _val) {
		Node* p = new Node(_val);
		if (is_empty()) {
			first = p;
			last = p;
			return;
		}
	}

	void push_back1(int _val) {
		Node* p = new Node(_val);
		if (is_empty()) {
			first = p;
			last = p;
			return;
		}
		last->next = p;
		last = p;
	}

	void push(int _val) {
		Node* p = new Node(_val);
		if (is_empty()) {
			first = p;
			last = p;
			return;
		}
	}

	Node* find_value(int _val) {
		Node* p = first;
		while ((p != nullptr) && (p->val != _val)) p = p->next;
		return ((p != nullptr) && (p->val == _val)) ? p : nullptr;

	}

	Node* find_index(int _val) {
		Node* p = first;
		while ((p != nullptr) && (p->val != _val)) p = p->next;
		return ((p != nullptr) && (p->val == _val)) ? p : nullptr;

	}

	void push1(int _val) {
		Node* p = new Node(_val);
		p->next = first;
		first = p;
	}

	void remove(int _val) {
		if (is_empty()) return;
		if (first->val == _val) {
			Node* p = first; //указатель на узел равен первому указателю. 
			first = p->next; //поле фёрст у листа становится равным полю некст у объекта пэ. пэ — узел
			delete p;
			return;
		}
		else if (last->val == _val) {
			if (first == last) {
				if (is_empty()) return;
				Node* p = first;
				first = p->next;
				delete p;
				return;
			}
			Node* p = first;
			while (p->next != last) p = p->next;
			p->next = nullptr;
			delete last;
			last = p;
			return;
		}
		Node* prev = first;
		Node* forw = first->next; 
		while (forw != nullptr && forw->val != _val) {
			forw = forw->next; //переходим к следующему узлу по указателю
			prev = prev->next;
		}
		if (forw == nullptr) {
			cout << "Элемента не существует!" << endl;
			return;
		}
		prev->next = forw->next;
		delete forw;
	}

	int operator[] (const int index) {
		if (is_empty()) return 0;
		Node* p = first;
		for (int i = 0; i < index; i++) {
			p = p->next;
			if (p == nullptr) return 0;
		}
		return p->val; //возвращаем значение вал узла пэ
	}

	void push_index(const int index, int _val) {
		if (is_empty()) return;
		if (index == 0)
		{
			Node* p = new Node(_val);
			p->next = first;
			first = p;
		}
		else{
		int counted = 0;
		Node* counter = first;
		while (counter != nullptr)
		{
			counter = counter->next;
			counted++;
		}
		if (index == counted)
		{
			Node* p = new Node(_val);
			last->next = p; //поменял у конкретного последнего объекта
			last = p; //говорим всему листу что ласт = пэ
		}
		else {
			int i = 0;
			Node* p = new Node(_val);
			Node* prev = first;
			Node* forw = first->next;
			while (forw != nullptr && i < index - 1) {
				forw = forw->next;
				prev = prev->next;
				i++;
			}
			if (forw == nullptr) {
				cout << "Элемент невозможно вставить в данную позицию!" << endl;
				return;
			}
			prev->next = p;
			p->next = forw;
		}
	}
}

	void remove_index(const int index)
	{
		if (index == 0)
			first = first->next;
		else {
			Node* p = first;
			int count = 0;
			while (p != nullptr)
			{
				p = p->next;
				count++;
			}
			if (index == count) {
				Node* p = first;
				while (p->next != last) p = p->next;
				p->next = nullptr;
				delete last;
				last = p;
			}
			else {
				int i = 0;
				Node* prev = first;
				Node* forw = first->next;
				while (forw != nullptr && i < index-1) {
					forw = forw->next;
					prev = prev->next;
					i++;
				}
				if (forw == nullptr) {
					cout << "Элемента не существует!" << endl;
					return;
				}
				prev->next = forw->next;
				delete forw;
			}
		}
	}

	void print() {
		if (is_empty()) return;
		Node* p = first;
		while (p != nullptr) { 
			cout << p->val << " ";
			p = p->next;
		}
		cout << endl;
	}

};
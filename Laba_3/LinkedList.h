#pragma once

#include <iostream>
#include <string>
using namespace std;

template<typename T>
class List
{
public:
	List();

	void pop_front();
	void push_back(T data);
	void print();
	void clear();
	bool is_empty();
	int getSize() { return Size; }

	T& operator[](const int index);
private:
	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;
		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	int Size;
	Node<T>* head;
};

template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}

template<typename T>
inline void List<T>::pop_front()
{
	Node<T> *temp = head;

	head = head->pNext;
	delete temp;

	Size--;
}

template<typename T>
inline void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data); 
	}
	else
	{
		Node<T>* current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}

	Size++;
}

template<typename T>
inline void List<T>::print()
{
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		cout << current->data << "   ";
		current = current->pNext;
	}
	
}


template<typename T>
inline void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}

template<typename T>
inline bool List<T>::is_empty()
{
	if (this->getSize() == 0) return true;
	else return false;
}

template<typename T>
T& List<T>::operator[](const int index)
{
	int ctr = 0;
	Node<T>* current = this->head;
	while (current!=nullptr)
	{
		if (ctr == index)
		{
			return current->data;
		}
		current = current->pNext;
		ctr++;
	}
}


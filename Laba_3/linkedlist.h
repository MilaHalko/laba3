#pragma once

#include <iostream>
#include <string>
using namespace std;

template<typename T>
class List
{
public:
	List();


	void push_back(T data);
	void pop_front();
	void clear();
	int GetSize() { return Size; }

	T& operator[](const int index);
private:
	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;
		Node(T data = T(), Node* pNext = NULL)
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
	head = NULL;
}

template<typename T>
inline void List<T>::push_back(T data)
{
	if (head == NULL)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;

		while (current->pNext != NULL)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}

	Size++;
}

template<typename T>
inline void List<T>::pop_front()
{
	Node<T>* temp = head;

	head = head->pNext;
	delete temp;

	Size--;
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
inline T& List<T>::operator[](const int index)
{
	int ctr = 0;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if (ctr == index)
		{
			return current->data;
		}
		current = current->pNext;
		ctr++;
	}
}


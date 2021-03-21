#pragma once

#include <iostream>
#include <string>

template<typename T>
class List
{
public:
	List();

	void push_back(T data);
	int GetSize() { return Size; }

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


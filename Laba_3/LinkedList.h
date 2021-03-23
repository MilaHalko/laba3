#pragma once
#include <iostream>
#include <string>
using namespace std;

template<typename T>
class Node            // хранения данных и указателей на следующий элемент списка
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


template<typename T>
class List
{
    int size;
    Node<T>* head;
    
public:
	List();
   
    // методы списка (основные действия)
	void pushBack(T definition);
	void print();
	void clear();
    void popFront();
    
    // счетчик размера списка + возможность обращению к элементу списка за индексом
	int getSize() {return size;}
	T& operator[](const int index);
};


template<typename T>
List<T>::List()
{
	size = 0;
	head = NULL;
}


template<typename T>
inline void List<T>::pushBack(T definition)
{
	if (head == NULL)
	{
		head = new Node<T>(definition);
	}
	else
	{
		Node<T>* current = this->head;

		while (current->pNext != NULL)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(definition);
	}
	size++;
}


template<typename T>
inline void List<T>::clear()
{
	while (size)
	{
		popFront();
	}
}


template<typename T>
inline void List<T>::popFront()
{
    Node<T>* temp = head;

    head = head->pNext;
    delete temp;

    size--;
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

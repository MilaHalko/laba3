#pragma once
#include <iostream>
#include <string>
using namespace std;

template<typename T>  // ! не стоит ли убрать шаблон так как мы знаем что мы заботаем со стригами?
class List
{
    template<typename T>
    class Node                 // хранения данных и указателей на следующий элемент списка
    {
    public:
        Node* pNext;  // !не понимаю почему указатель реализуется через Node*
        T data;
        Node(T data = T(), Node* pNext = NULL)  // ! что значит Т()
        {
            this->data = data;
            this->pNext = pNext;
        }
    };

    int Size;
    Node<T>* head;
    
public:
	List();
   
    // методы списка (основные действия)
	void push_back(T data);
	void print();
	void clear();
    void pop_front();
    
    // счетчик размера списка + возможность обращению к элементу списка за индексом
	int GetSize() { return Size; }
	T& operator[](const int index);
};


template<typename T>
List<T>::List()         // заполнения по умолчанию
{
	Size = 0;
	head = NULL;
}


template<typename T>
inline void List<T>::push_back(T data)
{
	if (head == NULL)
	{
		head = new Node<T>(data);   // ! почему тип пишется в <>?
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

template<typename T> // !не поняла как работает и зачем нужна / не можно ли соеденить pop_front и clear
inline void List<T>::pop_front()
{
    Node<T>* temp = head;

    head = head->pNext;
    delete temp;

    Size--;
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


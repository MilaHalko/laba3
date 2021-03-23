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
List<T>::List()         // заполнения по умолчанию
{
	size = 0;
	head = NULL;
}


template<typename T>
inline void List<T>::pushBack(T definition)
{
	if (head == NULL)
	{
		head = new Node<T>(definition);   // ! почему тип пишется в <>?
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
	while (size)
	{
		popFront();
	}
}

template<typename T> // !не поняла как работает и зачем нужна / не можно ли соеденить pop_front и clear
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
	int ctr = 0;        // ! за что отвечает?
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


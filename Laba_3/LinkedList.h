#pragma once
#include <iostream>
#include <string>
using namespace std;

template<typename T>
class Node
{
public:
    Node* pNext;
    T definition;
    Node(T definition = T(), Node* pNext = nullptr)
    {
        this->definition = definition;
        this->pNext = pNext;
    }
};

template<typename T>
class List
{
    int Size;
    Node<T>* head;
    
public:
    List();
    
    int getSize() {return Size;}
    
    void push_back(T definition);
    void clear();
    
    bool is_empty();
    T& operator[](const int index);

    //void print();
};

template<typename T>
List<T>::List()
{
    Size = 0;
    head = nullptr;
}

template<typename T>
void List<T>::push_back(T definition)
{
    if (head == nullptr)
    {
        head = new Node<T>(definition);
    }
    else
    {
        Node<T>* current = this->head;
        
        while (current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node<T>(definition);
    }
    
    Size++;
}

template<typename T>
void List<T>::clear()
{
    while (Size)
    {
        Node<T> *temp = head;
        
        head = head->pNext;
        delete temp;
        
        Size--;
    }
}

template<typename T>
bool List<T>::is_empty()
{
    bool empty = false;
    if (this->getSize() == 0) empty = true;
    return empty;
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
            return current->definition;
        }
        current = current->pNext;
        ctr++;
    }
    return current->definition;
}

/*
template<typename T>
void List<T>::print()
{
    Node<T>* current = this->head;
    while (current != nullptr)
    {
        cout << current->definition << "   ";
        current = current->pNext;
    }
}
*/

//
// Created by SeyedReza on 5/3/2019.
//

#ifndef HW4Q5_STACK_HPP
#define HW4Q5_STACK_HPP

#include "stack.h"

//template<class T>
//using sharedObj = std::shared_ptr<T>;

template<class T>
Stack<T>::Stack() {
    std::cout << "Stack created!" << std::endl;
}

template<class T>
Stack<T>::~Stack() {
    //std::cout << "Trying to..." << std::endl;
    while(pHead)                       // While current pointer is not null
    {
        auto* next {pHead->getNext()}; // Get the pointer to the next
        //delete pHead;                  // Delete the current head
        pHead = next;                  // Make head point to the next node
    }
    std::cout << "Stack was killed!" << std::endl;
}

template<class T>
void Stack<T>::push(const T& pObj){
    if (size == 0)
    {
        std::cout << "First object added!" << std::endl;
        pHead = new Obj{pObj};
    }
    else
    {
        std::cout << "New object added!" << std::endl;
        auto po = new Obj{pObj};
        po->setNext(pHead);
        pHead = po;
    }
    //std::cout << *(pHead->getObj()) << std::endl;
    size++;
}

template<class T>
T Stack<T>::pop() {
    if (isEmpty())
    {
        throw std::logic_error {"Stack empty"}; // Pop is not valid so throw exception
    }
    Obj* next{pHead->getNext()};   // Save pointer to the next node
    T item {pHead->getObj()};       // Save the T value to return later
    //delete pHead;                   // Delete the current head
    pHead = next;                   // Make head point to the next node

    //std::cout << pHead->getObj() << std::endl;
    //std::cout << "Object removed!" << std::endl;
    size--;


    return item;                    // Return the top object
}

template<class T>
size_t Stack<T>::getCount() { return size; }

template<class T>
bool Stack<T>::isEmpty() { return pHead == nullptr; }

#endif //HW4Q5_STACK_HPP

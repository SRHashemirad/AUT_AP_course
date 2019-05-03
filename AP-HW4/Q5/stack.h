//
// Created by SeyedReza on 5/3/2019.
//

#ifndef HW4Q5_STACK_H
#define HW4Q5_STACK_H

#include <iostream>
#include <memory>

template<class T>
class Stack {
public:
    Stack();
    ~Stack();

    void push(const T& pObj);
    T pop();
    size_t getCount();
    bool isEmpty();
private:
    class Obj {
    private:
        T pObj;
        Obj* pNext;
    public:
        Obj(const T& po): pObj{po}, pNext{nullptr} { }
        ~Obj() {delete pNext;}

        T getObj() const { return pObj; }
        Obj* getNext() const { return pNext; }
        void setNext(Obj* po){ pNext = po; }
    };

    Obj* pHead{};

    size_t size{};
};

#endif //HW4Q5_STACK_H

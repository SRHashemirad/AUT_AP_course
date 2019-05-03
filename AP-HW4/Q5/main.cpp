#include <iostream>
#include <memory>
#include <string>
#include "stack.hpp"

int main() {
    Stack<std::shared_ptr<std::string>> stack;
    std::string base{"TEXT"};

    //std::cout << stack.isEmpty() << std::endl;

    for(char a{'A'}; a <= 'Z'; a++) {
        stack.push(std::make_shared<std::string>(base + a));
        //std::cout << stack.getCount() << std::endl;
    }

    //Pop everything out
    size_t N{stack.getCount()};
    //std::cout << N << std::endl;

    for(size_t i{}; i < N; i++) {
        std::cout << *stack.pop() << std::endl;
        //stack.pop();
        //std::cout << stack.getCount() << std::endl;
    }

    if(stack.isEmpty())
        std::cout << "Stack is empty" << std::endl;
    return 0;
}

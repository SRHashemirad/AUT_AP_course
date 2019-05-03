#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <stdio.h>


template<typename T>
unsigned long vSizePrint(const std::vector<T> &vec);

template<typename T>
unsigned long vCapPrint(const std::vector<T> &vec);

template<typename T>
void vPrint(const std::vector<T> &vec);

std::string format3DString(const std::string s, const int i);

int main() {
    //Fisrt part without reserving!
    std::vector<std::unique_ptr<std::string>> v;
    for (size_t i{}; i < 1000; ++i) {
        std::string str {format3DString("STR", i)};
        auto pStr{std::make_unique<std::string>(str)};
        v.push_back(std::move(pStr));
                //Because of unique_ptr format, for push_back it to vector std::move must be used!
                //It can't be copied!
        vSizePrint(v);
        std::cout << ", ";
        vCapPrint(v);
        std::cout << std::endl;
    }

    //Use this function to print vectors
    //vPrint(v);

    //Second part with reserving!
    std::vector<std::unique_ptr<std::string>> v2;
    v2.reserve(1000);
    for (size_t i{}; i < 1000; ++i) {
        std::string str {format3DString("STR", i)};
        auto pStr{std::make_unique<std::string>(str)};
        v2.push_back(std::move(pStr));
                //Because of unique_ptr format, for push_back it to vector std::move must be used!
                //It can't be copied!
        vSizePrint(v2);
        std::cout << ", ";
        vCapPrint(v2);
        std::cout << std::endl;
    }

    return 0;
}

template<typename T>
unsigned long vSizePrint(const std::vector<T> &vec) {
    std::cout << "Size: " << vec.size();
    return vec.size();
}

template<typename T>
unsigned long vCapPrint(const std::vector<T> &vec) {
    std::cout << "Capacity: " << vec.capacity();
    return vec.capacity();
}

//Use this function to print vectors
template<typename T>
void vPrint(const std::vector<T> &vec) {
    for (int i{}; i < vec.size(); ++i) {
        std::cout << *vec[i] << std::endl;
    }
    std::cout << std::endl;
}

//Formating strings in form of 'STR 000' to 'STR 999'
std::string format3DString(const std::string s, const int i) {
    std::string iStr{};
    if (i < 10)
    {
        iStr = "00" + std::to_string(i);
    }
    else if (i < 100)
    {
        iStr = "0" + std::to_string(i);
    }
    else
    {
        iStr = std::to_string(i);
    }
    std::string str{s + " " + iStr};
    return str;
}
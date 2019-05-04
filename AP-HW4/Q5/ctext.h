//
// Created by SeyedReza on 5/4/2019.
//

#ifndef HW4Q5_CTEXT_H
#define HW4Q5_CTEXT_H

#include <string>
#include <iostream>

class Ctext {
private:
    std::string str;

public:
    Ctext(std::string s) : str{s} { };
    std::string getText();
};


#endif //HW4Q5_CTEXT_H

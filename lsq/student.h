//
// Created by rashadalsharpini on 25/12/23.
//

#ifndef DYNAMICARRAY_STUDENT_H
#define DYNAMICARRAY_STUDENT_H

#include <iostream>
using namespace std;
class student{
private:
    string name;
    int id;
public:
    void set();
    void get();
    string returnName(){ return name;}
    int returnID(){return id;}
    friend ostream&operator<<(ostream&os, student stu);
};

#endif //DYNAMICARRAY_STUDENT_H

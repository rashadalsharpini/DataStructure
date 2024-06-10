//
// Created by rashadalsharpini on 25/12/23.
//

#include "student.h"
void student::set() {
    cout<<"enter the name : ";
    cin>>name;
    cout<<"enter the id : ";
    cin>>id;
}
void student::get() {
    cout<<"the name is : "<<name<<endl
        <<"the id is : "<<id<<endl;
}

ostream &operator<<(ostream &os, student stu) {
    os<<"the name is : "<<stu.returnName()<<endl
        <<"the id is : "<<stu.returnID()<<endl;
    return os;
}

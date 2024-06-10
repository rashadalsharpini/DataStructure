//
// Created by rashadalsharpini on 01/01/24.
//

#include "student.h"
string student::returnFirstName() {
    return firstName;
}
void student::set() {
    cout<<"enter the first name : ";
    cin>>firstName;
    cout<<"enter the last name : ";
    cin>>lastName;
    cout<<"enter the id : ";
    cin>>id;
}

void student::get() {
    cout<<"the name is : "<<firstName<<" "<<lastName<<endl;
    cout<<"the id is : "<<id<<endl;
}

ostream &operator<<(ostream &os, const student &obj) {
    os<<"the name is : "<<obj.firstName<<" "<<obj.lastName<<endl
      <<"the id is : "<<obj.id<<endl;
    return os;
}

istream &operator>>(istream &os, student &obj) {
    cout<<"enter the first name : ";
    os>>obj.firstName;
    cout<<"enter the last name : ";
    os>>obj.lastName;
    cout<<"enter the id : ";
    os>>obj.id;
    return os;
}

bool student::operator<(const student &other) const {
    if(this->lastName<other.lastName)
        return true;
    else
        return false;
}

bool student::operator>(const student &other) const {
    if(this->lastName>other.lastName)
        return true;
    else
        return false;
}

student &student::operator=(const student &other) {
    this->firstName=other.firstName;
    this->lastName=other.lastName;
    this->id=other.id;
    return*this;
}

bool student::operator<=(const student &other) const {
    return this->lastName<=other.lastName;
}

bool student::operator>=(const student &other) const {
    return this->lastName>=other.lastName;
}

bool student::operator==(const student &other) const {
    return this->lastName==other.lastName;
}

bool student::compareByName(const student &obj1, const student &obj2) {
    return obj1.firstName<obj2.firstName;
}

bool student::compareById(const student &obj1, const student &obj2) {
    return obj1.id<obj2.id;
}

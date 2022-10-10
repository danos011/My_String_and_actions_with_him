#include "Person.h"

StringPerson::StringPerson() {
    surname_ = "";
    name_ = "";
    birthYear_ = "";
}

StringPerson::StringPerson(const String &surname,const String &name, const String birthYear) {
    surname_ = surname;
    name_ = name;
    birthYear_ = birthYear;
}

void StringPerson::setSurname(String str)
{
    surname_ = str;
}

void StringPerson::setName(String str)
{
    name_ = str;
}

void StringPerson::setBirthYear(String str)
{
    birthYear_ = str;
}

String StringPerson::getName()
{
    return name_;
}

String StringPerson::getSurname()
{
    return surname_;
}

String StringPerson::getBirthYear()
{
    return birthYear_;
}


bool StringPerson::operator<(StringPerson &str) {
    if (name_.compare(str.name_) == 0 ) {
        if (birthYear_.compare(str.name_) == 0) {
            if (surname_.compare(str.name_) == -1) {
                return true;
            } else {
                return false;
            }
        }
        else if (birthYear_.compare(str.name_) == -1) {
            return true;
        }
        else{
            return false;
        }
    }
    else if(name_.compare(str.name_) == -1){
        return true;
    }
    else{
        return false;
    }
}

Person::Person() {
    surname_ = "";
    name_ = "";
    birthYear_ = "";
}

Person::Person(const std::string &surname,const std::string &name, const std::string birthYear) {
    surname_ = surname;
    name_ = name;
    birthYear_ = birthYear;
}

void Person::setSurname(std::string str)
{
    surname_ = str;
}

void Person::setName(std::string str)
{
    name_ = str;
}

void Person::setBirthYear(std::string str)
{
    birthYear_ = str;
}

std::string Person::getName()
{
    return name_;
}

std::string Person::getSurname()
{
    return surname_;
}

std::string Person::getBirthYear()
{
    return birthYear_;
}

bool Person::operator<(Person &str) {
    if (name_ == str.name_) {
        if (birthYear_ == str.birthYear_) {
            if (surname_ < str.surname_) {
                return true;
            } else {
                return false;
            }
        }
        else if (birthYear_ < str.birthYear_) {
            return true;
        }
        else{
            return false;
        }
    }
    else if(name_ < str.name_){
        return true;
    }
    else{
        return false;
    }
}

#ifndef LAB7FINAL_PERSON_H
#define LAB7FINAL_PERSON_H

#include "String.h"
#include <string>

class StringPerson {
private:
    String surname_;
    String name_;
    String birthYear_;
public:
    StringPerson();
    StringPerson(const String &surname,const String &name, const String birthYear);
    void StringPerson::setSurname(String str);
    void StringPerson::setName(String str);
    void StringPerson::setBirthYear(String str);
    String StringPerson::getName();
    String StringPerson::getSurname();
    String StringPerson::getBirthYear();
    bool StringPerson::operator<(StringPerson &str);
};


class Person {
private:
    std::string surname_;
    std::string name_;
    std::string birthYear_;
public:
    Person();
    Person(const std::string &surname,const std::string &name, const std::string birthYear);
    void Person::setSurname(std::string str);
    void Person::setName(std::string str);
    void Person::setBirthYear(std::string str);
    std::string Person::getName();
    std::string Person::getSurname();
    std::string Person::getBirthYear();
    bool Person::operator<(Person &str);
};
#endif //LAB7FINAL_PERSON_H

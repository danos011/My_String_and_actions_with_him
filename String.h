#ifndef LAB7FINAL_STRING_H
#define LAB7FINAL_STRING_H

#include <cstring>
#include <ostream>
#include <iostream>
#include <cstdlib>

class String
{
private:
    size_t size_;
    char *str_;
    static const int INLIM_ = 80;
public:

    String();
    String(char* otherStr);
    String(const String &otherStr);
    String(String &&otherStr) noexcept;
    ~String();
    String& operator=(const String &otherStr) noexcept;
    String operator+(const String &otherStr) noexcept;
    int compare(String &otherStr);
    friend std::istream& operator>>(std::istream & is, String &st);
    friend std::ostream& operator<<(std::ostream& out, const String& str);
    const char& String::operator[](int i) const;
    char& String::operator[](int i);
    size_t String::length() const;
    bool String::operator==(const char* str) const;
    bool String::operator<(const char* str) const;
    bool String::operator>(const char* str) const;
};

#endif //LAB7FINAL_STRING_H

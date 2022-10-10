#include "String.h"

String::String()
{
    str_= nullptr;
    size_ = 0;
}

String::String(char* otherStr)
{
    size_ = strlen(otherStr);
    str_ = new char[size_ + 1];
    strcpy(str_ , otherStr);
}

String::String(const String &otherStr)
{
    size_ = otherStr.size_;
    str_ = new char[size_ + 1];
    strcpy(str_ , otherStr.str_);
}
String::String(String &&otherStr) noexcept
{
    size_ = otherStr.size_;
    str_ = new char[size_ + 1];
    strcpy(str_, otherStr.str_);

    otherStr.str_ = nullptr;
    otherStr.size_ = 0;
}
String::~String()
{
    delete[] str_;
}

String& String::operator=(const String &otherStr) noexcept
{
    if (this != &otherStr)
    {
        delete[] str_;

        size_ = otherStr.size_;
        str_ = new char [size_ + 1];
        strcpy(str_, otherStr.str_);
    }
    return *this;
}

String String::operator+(const String &otherStr) noexcept
{
    String s;
    s.size_ = size_ + otherStr.size_;
    s.str_ = new char[s.size_ + 1];

    strcpy(s.str_, str_);
    strcat(s.str_, otherStr.str_);
    return s;
}

std::istream& operator>>(std::istream& in, String& str)
{
    char temp[String::INLIM_];
    in.get(temp, String::INLIM_);
    if (in)
        str = temp;
    while (in && in.get() != '\n')
        continue;
    return in;
}

std::ostream& operator<<(std::ostream& out, const String& str)
{
    out << str.str_;
    return out;
}

char& String::operator[](int i)
{
    return str_[i];
}

const char& String::operator[](int i) const
{
    return str_[i];
}

bool String::operator==(const char* str) const
{
    if(strcmp(str_,str) == 0) {
        return true;
    }
    else{
        return false;
    }
}

bool String::operator<(const char* str) const
{
    if(strcmp(str_,str) == -1) {
        return true;
    }
    else{
        return false;
    }
}

bool String::operator>(const char* str) const
{
    if(strcmp(str_,str) == 1) {
        return true;
    }
    else{
        return false;
    }
}

int String::compare(String &otherStr)
{
    if(strcmp(str_, otherStr.str_) == 0){
        return 0;
    }
    else if(strcmp(str_, otherStr.str_) == -1){
        return -1;
    }
    else if(strcmp(str_, otherStr.str_) == 1){
        return 1;
    }
}

size_t String::length() const{
    return size_;
}


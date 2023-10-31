#pragma once
#include <iostream>

using namespace std;

class String
{
    char* str;
    size_t size;

    void copy(const char* st);

public:
    String();
    String(size_t size);
    ~String();
    String(const char* str);
    String(const String& obj);
    //void set();
    void print();

    String& operator=(const String& obj);

    int compare(const String& str);

    bool operator<(const String& str);
    bool operator>(const String& str);
    bool operator<=(const String& str);
    bool operator<=(const String& str);
    bool operator==(const String& str);
    bool operator!=(const String& str);

    String operator+(const String& str);
    void operator+=(const String& str);
    String operator*(int n);
    char operator[](size_t index);
    void operator()(const char* s);
    size_t length();

    friend ostream& operator<<(ostream& out, const String& st);
    friend istream& operator>>(istream& in, String& st);
    
};

String::String() : String(80) {}


String::String(size_t size) : size(size)
{
    str = new char[size + 1];
    for (size_t i = 0; i < size; i++)
    {
        str[i] = ' ';
    }
    str[size] = '\0';
}

String::String(const char* str)
{
    size = strlen(str);
    copy(str);
}

String::~String()
{
    delete[] str;
}

void String::print()
{
    cout << str;
}

void String::copy(const char* st)
{
    str = new char[size + 1];
    for (size_t i = 0; i < size + 1; i++)
    {
        str[i] = st[i];
    }
}

String::String(const String& obj)
{
    size = obj.size;
    copy(obj.str);
}

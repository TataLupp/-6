#pragma once
#include <iostream>

class String {
public:
    String(const char* s);
    String();
    String(const String&);
    ~String();
    int length() const { return len; }

    String& operator=(const String&);
    String& operator=(const char*);
    char& operator[](int i);
    const char& operator[](int i) const;
    
    friend bool operator<(const String& st, const String& st2);
    friend bool operator>(const String& st1, const String& st2);
    friend bool operator==(const String& st, const String& st2);
    friend std::ostream& operator<<(std::ostream& os, const String& st2);
    friend std::istream& operator>>(std::istream& is, String& st);
    
private:
	char* str;
	int len;
	static const int CINLIM = 80;
};


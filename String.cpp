#include "String.h"
#include <iostream>
#include <cstring>
#pragma warning(disable : 4996)
String::String(const char* s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
}

String::String()
{
	len = 0;
	str = new char[1];
	str[0] = '\0';
}

String::String(const String& st)
{
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
}

String::~String()
{

	delete[] str;
}


String& String::operator=(const String& st)
{
	if (this == &st)
		return *this;
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}

String& String::operator=(const char* s)
{
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}


char& String::operator[](int i)
{
	return str[i];
}

const char& String::operator[](int i) const
{
	return str[i];
}

bool operator<(const String& st1, const String& st2)
{
	return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String& st1, const String& st2)
{
	return st2 < st1;
}

bool operator==(const String& st1, const String& st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);
}


std::ostream& operator<<(std::ostream& out, const String& st)
{
	out << st.str;
	return out;
}


std::istream& operator>>(std::istream& in, String& st)
{
	char temp[String::CINLIM];
	in.get(temp, String::CINLIM);
	if (in)
		st = temp;
	while (in && in.get() != '\n' && in.get() != '\0')
		continue;
	return in;
}

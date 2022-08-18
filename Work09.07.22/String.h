#pragma once
#include<iostream>


using namespace std;


class MyString
{

	char* str = nullptr;
	int size = 0;
	static int count;

public:
	
	MyString(){}
	MyString(int size);
	MyString(const char* str);
	MyString(const MyString& other);
	~MyString();

	void set();
	void set(const char* str);
	void print();
	char* get();
	
	MyString& operator=(const MyString& other);
	MyString operator+(const MyString& other);
	MyString operator-(const MyString& other);
	MyString operator+(const char* str);
	MyString operator-(const char* str);
	MyString(MyString&& other);
	void operator+=(const MyString& other);
	void operator+=(const char* str);
	void operator()(MyString& str);
	void operator()(const char* str);
	bool operator==(const MyString& other);
	bool operator!=(const MyString& other);
	bool operator>(const MyString& other);
	bool operator<(const MyString& other);
	char& operator[](int index);
	
};

int MyString::count = 0;

MyString::MyString(int size)
{
	this->size = size;
	str = new char[size + 1];
	str[0] = '\0';
	count++;
}

MyString::MyString(const char* str)
{
	if (this->str)
		delete this->str;
	this->size = strlen(str) + 1;
	this->str = new char[size];
	strcpy_s(this->str, size, str);
	count++;
}

MyString::MyString(const MyString& other)
{
	if (this->str)
		delete this->str;

	this->size = strlen(other.str) + 1;
	this->str = new char[size];
	strcpy_s(this->str, size, other.str);
}

 MyString::~MyString()
{
	 delete this->str;
	 count--;
}

 void MyString::set()
 {
	 char buff[255];
	 this->size = strlen(buff) + 1;
	 this->str = new char[size];
	 cout << "Enter string" << endl;
	 cin.getline(buff, size);
	 strcpy_s(this->str, size, buff);
	 count++;
 }

 void MyString::set(const char* str)
 {
	 if (this->str)
		 delete this->str;

	 this->size = strlen(str) + 1;
	 this->str = new char[size];
	 strcpy_s(this->str, size, str);
 }

 void MyString::print()
 {
	 cout << this->str << endl;
 }

 char* MyString::get()
 {
	 return str;
 }

 MyString& MyString::operator=(const MyString& other)
 {
	 if (this->str != nullptr)
		 delete str;

	 this->size = strlen(other.str) + 1;
	 this->str = new char[size];
	 strcpy_s(this->str, size, other.str);
	 return *this;
 }

 MyString MyString::operator+(const MyString& other)
 {
	 MyString newString;
	 int thlen = strlen(this->str);
	 int otlen = strlen(other.str);
	 size = thlen + otlen + 1;
	 newString = new char[size];
	 strcpy_s(newString.str, thlen + 1, this->str);
	 for (int i = thlen, j = 0; i < size; i++, j++)
	 {
		 newString.str[i] = other.str[j];
	 }
	 return newString;
 }

 MyString MyString::operator-(const MyString& other)
 {
	 MyString newString;
	 if (strlen(this->str) >= strlen(other.str))
	 {
		 this->size = strlen(this->str) - strlen(other.str);
		 newString = new char[size];
		 for (int i = 0; i < size; i++)
		 {
			 newString.str[i] = this->str[i];
		 }
		 newString[size] = '\0';
		 return newString;
	 }
	 else
	 {
		 this->size = strlen(other.str)- strlen(this->str);
		 newString = new char[size];
		 
		 for (int i = 0; i < size; i++)
		 {
			 newString.str[i] = other.str[strlen(this->str) + i];
		 }
		 newString[size] = '\0';
		 return newString;
	 }
 }

 MyString MyString::operator+(const char* str)
 {
	 this->size = strlen(this->str) + strlen(str) + 1;
	 int len = strlen(str);
	 char* newStr = new char[size];
	 strcpy_s(newStr, size, this->str);
	 for (int i = len, j = 0; i < size; i++, j++)
	 {
		 newStr[i] = str[j];
	 }
	 newStr[size] = '\0';
	 return newStr;
 }

 MyString MyString::operator-(const char* str)
 {
	 this->size = strlen(this->str) - strlen(str);
	 int len = strlen(str);
	 char* newStr = new char[size];
	 for (int i = 0, j = 0; i < size; i++, j++)
	 {
		 newStr[i] = this->str[j];
	 }
	 newStr[size]='\0';
	 return newStr;
 }

 bool MyString::operator==(const MyString& other)
 {
	 if (this->size != other.size)
		 return false;

	 for (int i = 0; i < this->size; i++)
	 {
		 if (this->str[i] != other.str[i])
			 return false;
	 }
	 return true;
 }

 bool MyString::operator!=(const MyString& other)
 {
	 if (this->size == other.size)
		 return false;

	 for (int i = 0; i < this->size; i++)
	 {
		 if (this->str[i] == other.str[i])
			 return false;
	 }
	 return true;
 }

 bool MyString::operator>(const MyString& other)
 {
	 if (this->size > other.size)
		 return true;
	 else
		return false;
 }

 bool MyString::operator<(const MyString& other)
 {
	 if (this->size < other.size)
		 return true;
	 else
		 return false;
 }

 char& MyString::operator[](int index)
 {
	 return this->str[index];
 }

 MyString::MyString(MyString&& other)
 {
	 this->str = other.str;
	 this->size = other.size;
	 other.str = nullptr;
 }

 void MyString::operator+=(const MyString& other)
 {
	 MyString newString;
	 int len1 = strlen(other.str);
	 int len2 = strlen(other.str);
	 this->size = len1 + len2;
	 newString = new char[size];
	 strcpy_s(newString.str, size, this->str);
	 for (int i = size - 1, j = 0; i < size; i++, j++)
	 {
		 newString.str[i] = other.str[j];
	 }
	 newString.str[size] = '\0';
	 strcpy_s(this->str, this->size + 1, newString.str);
 }

 void MyString::operator+=(const char* str)
 {
	 int len = strlen(this->str);
	 int len2 = strlen(str);
	 this->size = len + len2;
	 char* newstr = new char[size];
	 strcpy_s(newstr, len + 1, this->str);
	 for (int i = len, j = 0; i < size + 1; i++, j++)
	 {
		 newstr[i] = str[j];
	 }
	 this->str = newstr;
 }

 void MyString::operator()(MyString& str)
 {
	 if (this->str != nullptr)
	 {
		 this->str = nullptr;
		 this->size = 0;
	 }
	 this->size = strlen(str.str) + 1;
	 this->str = new char[size];
	 strcpy_s(this->str, size, str.str);
 }

 void MyString::operator()(const char* str)
 {
	 if (this->str != nullptr)
	 {
		 this->str = nullptr;
		 this->size = 0;
	 }
	 this->size = strlen(str) + 1;
	 char* newstr = new char[size];
	 strcpy_s(newstr, size, str);
	 this->str = newstr;
 }

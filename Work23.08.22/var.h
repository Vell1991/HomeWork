#pragma once


enum TYPE
{
	_NULL,
	_INT,
	_DOUBLE,
	_STRING
};

class var
{
	void* value;
	TYPE type;
	void copy(const var& other);
	int str_to_int(const char* str);
	double str_to_double(const char* str);
	char int_to_str(const var& other);

public:
	var();
	var(int i);
	var(double d);
	var(const char* s);
	var(const var& other);
	var& operator=(const var& other);
	var operator+(const var& other);
	friend ostream& operator <<(ostream& out, const var& str);
};

void var::copy(const var& other)
{
	switch (other.type)
	{
	case _INT:
		value = new int;
		*((int*)value) = *((int*)other.value);
		break;
	case _DOUBLE:
		value = new double;
		(*(double*)value) = *((double*)other.value);
		break;
	case _STRING:
		value = new char[strlen((char*)other.value) + 1];
		strcpy_s((char*)value, strlen((char*)other.value) + 1, (char*)other.value);
		break;
	default:
		value = nullptr;
		break;
	}
	type = other.type;
}

int var::str_to_int(const char* str)
{
	char buff[80];
	int count = 0;
	for (size_t i = 0; i < strlen(str); i++)
	{
		if (isdigit(str[i]))
			buff[count++] = str[i];
	}
	buff[count] = '\0';
	return atoi(buff);
}

double var::str_to_double(const char* str)
{
	char buff[80];
	int count = 0;
	int kol = 0;
	for (size_t i = 0; i < strlen(str); i++)
	{
		if (isdigit(str[i]) || ((str[i] == ',' || str[i] == '.')&&( kol < 1)))
		{
			if (str[i] == ',' || str[i] == '.')
				kol++;

			buff[count++] = str[i];
		}
	}
	buff[count] = '\0';
	return atof(buff);
}

char var::int_to_str(const var& other)
{
	char buff[80];
	itoa(*(int*)other.value, buff, 10);
	return (char)value;
}


var::var()
{
	value = NULL;
	type = TYPE::_NULL;
}

var::var(int i)
{
	value = new int;
	*((int*)value) = i;
	type = TYPE::_INT;
}

var::var(double d)
{
	value = new double;
	*((double*)value) = d;
	type = TYPE::_DOUBLE;
}

var::var(const char* s)
{
	value = new char[strlen(s) + 1];
	strcpy_s((char*)value, strlen(s) + 1, s);
	type = TYPE::_STRING;
}

var::var(const var& other)
{
	copy(other);
}

var& var::operator=(const var& other)
{
	if (this == &other)
		return *this;

	delete value;
	copy(other);
	return *this;
}

var var::operator+(const var& other)
{
	switch (this->type)
	{
	
	case _INT:
		switch (other.type)
		{
		case _INT:   return var(*(int*)value + *(int*)other.value);
		case _DOUBLE:return var(*(int*)value + *(double*)other.value);
		case _STRING:return var(*(int*)value + str_to_int((char*)other.value));
		}
		break;
	case _DOUBLE:
		switch (other.type)
		{
		case _INT:   return var(*(double*)value + *(int*)other.value);
		case _DOUBLE:return var(*(double*)value + *(double*)other.value);
		case _STRING:return var(*(double*)value + str_to_double((char*)other.value));
		}
		break;
	case _STRING:
		int a, length;
		switch (other.type)
		{
		case _INT:  a = strlen((char*)value);
			length = strlen((char*)other.value) + a;
			strcat_s(((char*)value), length + 1, (char*)other.value);
			return var((char*)value);
		case _DOUBLE:return var(*(char*)value + *(double*)other.value);
		case _STRING:
			a = strlen((char*)value);
			length = strlen((char*)other.value) + a;
			strcat_s(((char*)value), length + 1, (char*)other.value);
			return var((char*)value);
		}
		break;
	default:
		*this = other;
		break;
	}
}

ostream& operator <<(ostream& out, const var& str)
{
	switch (str.type)
	{
	case _INT:
		cout << *((int*)str.value);
		break;
	case _DOUBLE:
		cout << *((double*)str.value);
		break;
	case _STRING:
		cout << (char*)str.value;
		break;
	default:
		break;
	}
	return out;
}

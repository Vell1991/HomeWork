#pragma once
#include <iostream>
#include<iomanip>
#include <cstring>
#include"../Library/Function.h"

using namespace std;

class Abonents
{
	char* surname = nullptr;
	char* name = nullptr;
	char* number = nullptr;
	char* compani = nullptr;
	

public:
	Abonents() {}
	void SetSurname();
	void SetSurname(const char* surname);
	void SetName();
	void SetName(const char* name);
	void SetNumber();
	void SetNumber(const char* number);
	void SetCompani();
	void SetCompani(const char* compani);
	void print();
	
};



void Abonents::SetSurname()
{
	char str[50];
	cout << "Enter you surname " << endl;
	cin.ignore();
	cin.getline(str, 50);
	SetSurname(str);
}
void Abonents::SetSurname(const char* surname)
{
	if (this->surname)
		delete this->surname;
	int len = strlen(surname) + 1;
	this->surname = new char[len];
	strcpy_s(this->surname, len, surname);
}

void Abonents::SetName()
{
	char str[50];
	cout << "Enter you name" << endl;
	cin.getline(str, 50);
	SetName(str);
}
void Abonents::SetName(const char* name)
{
	if (this->name)
		delete this->name;
	int len = strlen(name) + 1;
	this->name = new char[len];
	strcpy_s(this->name, len, name);
}

void Abonents::SetNumber()
{
	char str[50];
	cout << "Enter you number" << endl;
	cin.getline(str, 50);
	SetNumber(str);
}
void Abonents::SetNumber(const char* number)
{
	if (this->number)
		delete this->number;
	int len = strlen(number) + 1;
	this->number = new char[len];
	strcpy_s(this->number, len, number);
}

void Abonents::SetCompani()
{
	char str[50];
	cout << "Enter you Compani " << endl;;
	cin.getline(str, 50);
	SetCompani(str);
}
void Abonents::SetCompani(const char* compani)
{
	if (this->compani)
		delete this->compani;
	int len = strlen(compani) + 1;
	this->compani = new char[len];
	strcpy_s(this->compani, len, compani);
}

void Abonents::print()
{
	cout << "Surname:" << surname << setw(12)
		 << "Name:"<< name << setw(12)
		 << "Number:"<< number << setw(12)
		 << "Compani: "<< compani << endl;
}

class PhoneBook
{
	Abonents** abonents = nullptr;
	int size = 0;

public:
	PhoneBook(){}
	~PhoneBook()
	{
		delete[] abonents;
	}
	void addAbonent();
	void dellAbonent();
	void print();
	void menu();
};
void PhoneBook::addAbonent()
{
	Abonents* abonent = new Abonents;
	abonent->SetSurname();
	abonent->SetName();
	abonent->SetNumber();
	abonent->SetCompani();
	addElem(abonents, size, abonent);
}
void PhoneBook::dellAbonent()
{
	if (size)
	{
		int value = 0;
		do
		{
			
			cin >> value;

		} while (value > size);
		dellElem(abonents, size, value);
	}
	else
	{
		cout << "Zero" << endl;
		system("pause");
	}
	
}

void PhoneBook::print()
{
	system("cls");
	cout << "Phone Book" << endl;
	for (size_t i = 0; i < size; i++)
	{
		abonents[i]->print();
	}
	system("pause");
}

void PhoneBook::menu()
{
	while (true)
	{
		system("cls");
		cout << "1. Add abonents\n" << "2. Delete abonents\n" << "3. Print\n" << "4. Exit" << endl;
		int b = 0;
		cin >> b;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			system("cls");
			cout << "1. Add abonents\n" << "2. Delete abonents\n" << "3. Print\n" << "4. Exit" << endl;
			cin >> b;
		}
		switch (b)
		{case 1:
			system("cls");
			addAbonent();
			break;
		case 2:
			system("cls");
			if (abonents)
			{
				print();
				cout << "Enter the serial number of the subscriber you want to delete" << endl;
				dellAbonent();
			}
			else
			{
				cout << "Phonebook zero" << endl;
				system("pause");
			}
			break;
		case 3:
			print();
			break;
		case 4:
		default:
			break;
		}
		if (b == 4)
			break;
	}

}

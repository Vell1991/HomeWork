#pragma once
#include<iostream>
#include"../Library/Function.h"


using namespace std;


class Humans
{
	char* surname = nullptr;
	char* name = nullptr;
	char* age = nullptr;
	
public:
	Humans(){}
	Humans(const char* surname, const char* name, const char* age) {}
	void SetSurname();
	void SetSurname(const char* surname);
	void SetName();
	void SetName(const char* name);
	void SetAge();
	void SetAge(const char* age);
	void print();
	
};

void Humans::SetSurname()
{
	char str[50];
	cout << "Enter Surname" << endl;
	cin.getline(str, 50);
	SetSurname(str);
}
void Humans::SetSurname(const char* surname)
{
	int len = strlen(surname) + 1;
	this->surname = new char[len];
	strcpy_s(this->surname, len, surname);
}

void Humans::SetName()
{
	char str[50];
	cout << "Enter Name " << endl;
	cin.getline(str, 50);
	SetName(str);
}
void Humans::SetName(const char* name)
{
	int len = strlen(name) + 1;
	this->name = new char[len];
	strcpy_s(this->name, len, name);
}

void Humans::SetAge()
{
	char str[50];
	cout << "Enter Age " << endl;
	cin.getline(str, 50);
	SetAge(str);
}
void Humans::SetAge(const char* age)
{
	int len = strlen(age) + 1;
	this->age = new char[len];
	strcpy_s(this->age, len, age);
}

void Humans::print()
{
	cout << "Surname - " << surname << " Name - " << name << " Age - " << age << endl;
}



class Flat
{
	Humans** humans = nullptr;
	
	int size = 0;
	char* numberFlat;
	char* numberRooms;
	float* square;

	
public:
	Flat(){}
	void SetNumberFlat();
	void SetNumberFlat(const char* numberFlat);
	void SetNumberofRooms();
	void SetNumberofRooms(const char* numberRooms);
	void addHumans();
	void print();
	
	
};


void Flat::SetNumberFlat()
{
	char flat[10];
	cout << "Enter number flat" << endl;
	cin.ignore();
	cin.getline(flat, 10);
	SetNumberFlat(flat);
}
void Flat::SetNumberFlat(const char* numberFlat)
{
	int len = strlen(numberFlat) + 1;
	this->numberFlat = new char[len];
	strcpy_s(this->numberFlat, len, numberFlat);
}

void Flat::SetNumberofRooms()
{
	char flat[10];
	cout << "Enter number of rooms" << endl;
	cin.getline(flat, 10);
	SetNumberofRooms(flat);
}
void Flat::SetNumberofRooms(const char* numberRooms)
{
	int len = strlen(numberRooms) + 1;
	this->numberRooms = new char[len];
	strcpy_s(this->numberRooms, len, numberRooms);
}

void Flat::addHumans()
{
	Humans* human = new Humans;
	human->SetSurname();
	human->SetName();
	human->SetAge();
	addElem(humans, size, human);
}

void Flat::print()
{
	cout << "Flat " << this->numberFlat << " Rooms " << this->numberRooms << endl;
	for (int i = 0; i < size; i++)
	{
		humans[i]->print();
	}
}

class House
{
	Flat** flats = nullptr;
	int sizeFlat = 0;
	char floor;
	char entrance;
	
public: 
	House(){}
	void SetHouse();
	void addFlat();
	void infoOfFlat();
	void addHumanofFlat();
	void print();
	void menu();
	
};

void House::SetHouse()
{
	char flat[10];
	cout << "Enter number floor" << endl;
	cin.getline(flat, 10);
}

void House::addFlat()
{
	Flat* flat = new Flat;
	flat->SetNumberFlat();
	flat->SetNumberofRooms();
	while (true)
	{
		system("cls");
		cout << "Do you want to add a resident\n1.Yes\n2.No" << endl;
		int i = 0;
		cin >> i;
		cin.ignore();
		system("cls");
		if (i == 1)
		{
			flat->addHumans();
		}
		else
		{
			break;
		}
	}
	addElem(flats, sizeFlat, flat);
}
void House::infoOfFlat()
{
	cout << "Info of flat" << endl;
	int i;
	cin >> i;
	flats[i - 1]->print();
	system("pause");
}

void House::addHumanofFlat()
{
	cout << "Enter flat" << endl;
	int i;
	cin >> i;
	cin.ignore();
	flats[i - 1]->addHumans();
	system("pause");

}

void House::print()
{
	for (int i = 0; i < sizeFlat; i++)
	{
		flats[i]->print();
	}
	system("pause");
}

void House::menu()
{
	while (true)
	{
		system("cls");
		cout << "1.Add Flat\n" << "2.Print Flat\n" <<"3.Info of flat\n"<<"4.Add resident on flat\n" << "5.Exit" << endl;
		int c = 0;
		cin >> c;
		switch (c)
		{
		case 1:
			addFlat();
			break;
		case 2:
			print();
			break;
		case 3:
			infoOfFlat();
			break;
		case 4:
			addHumanofFlat();
			break;
		case 5:
			break;
		}
		if (c == 5)
			break;
	}
}
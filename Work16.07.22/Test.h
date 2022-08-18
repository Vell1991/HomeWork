#pragma once
#include<iostream>
#include<string>
#include"../Library/Function.h"

using namespace std;



class Humans
{  
	char* surname = nullptr;
	char* name = nullptr;
	char* age = nullptr;
	
public:
	Humans() {}
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
	cin.ignore();
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


class Test
{
	Humans** humans = nullptr;
	int size = 0;
	Test** tests = nullptr;
	int flat = 0;
	int sizeflat = 0;
	int count = 0;
	int kol = 0;
	int sizeflat1 = 0;
	int rooms = 0;
public:
	Test(){}
	~Test()
	{
		humans = nullptr;
		delete[]humans;
		tests = nullptr;
		delete[]tests;
	}
	void SetFlat();
	void SetRooms();
	void SetHouse();
	void addHumans();
	void dellHumans();
	void addHumansInFlat();
	void dellHumansInFlat();
	void exammination();
	void changeApartmentnumber();
	void Sort();
	void print();
	void print1();
	void menu();
};

void Test::SetFlat()
{
	cout << "Enter the number of apartamets" << endl;
	int fl = 0;
	cin >> fl;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		system("cls");
		cout << "You didn't enter a number" << endl;
		cout << "Enter the number of apartamets" << endl;
		cin >> fl;
	}
	this->flat = fl;	
}

void Test::SetRooms()
{
	
	cout << "Enter the number of rooms" << endl;
	int f = 0;
	cin >> f;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		system("cls");
		cout << "You didn't enter a number" << endl;
		cout << "Enter the number of rooms" << endl;
		cin >> f;
	}
	this->rooms = f;
	system("cls");
}

void Test::SetHouse()
{
	system("cls");
	cout << "Create a house. Enter numbers of apartaments" << endl;
	int c = 0;
	cin >> c;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		system("cls");
		cout << "You didn't enter a number" << endl;
		cout << "Try again" << endl;
		cin >> c;
	}
	for (int i = 0; i < c; i++)
	{
		Test* test = new Test;
		test->SetFlat();
		test->SetRooms();
		addElem(tests, sizeflat1, test);
		print1();
	}
	do
	{
		exammination();
	} while (kol > 0);
	
	system("pause");
}


void Test::addHumans()
{
	Humans* human = new Humans;
	human->SetSurname();
	human->SetName();
	human->SetAge();
	addElem(humans, size, human);
}

void Test::dellHumans()
{
	int d = 0;
	cout << "Enter number humans" << endl;
	cin >> d;
	dellElem(humans, size, d);
}

void Test::addHumansInFlat()
{
	int c = 0;
	cin >> c;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		system("cls");
		cout << "You didn't enter a number" << endl;
		cout << "Try again" << endl;
		cin >> c;
	}
	tests[c - 1]->addHumans();
}

void Test::dellHumansInFlat()
{
	cout << "Enter number of the apartment where you want to delete a resident" << endl;
	int c = 0;
	cin >> c;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		system("cls");
		cout << "You didn't enter a number" << endl;
		cout << "Try again" << endl;
		cin >> c;
	}
	tests[c - 1]->dellHumans();

}

void Test::exammination()
{
	
	for (int i = 0; i < sizeflat1; i++)
	{
		this->count = i + 1;
		for (int j = i + 1; j < sizeflat1; j++)
		{
			count++;
			if (tests[i]->flat == tests[j]->flat)
			{
				cout << count<<" Same number"<<endl;
				kol++;
				while (kol > 0)
				{
					changeApartmentnumber();
					kol--;
				}
			}
		}
	}
}

void Test::changeApartmentnumber()
{
	do
	{
		cout << "Enter change apartment number" << endl;
		cin >> sizeflat;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore();
			system("cls");
			cout << "You didn't enret a number" << endl;
			cout << "Enter change apartment number" << endl;
			cin >> sizeflat;
		}
		for (int i = 0; i < sizeflat1; i++)
		{
			if (sizeflat == tests[i]->flat)
			{
				while (true)
				{
					system("cls");
					cout << "This apartment number already exists, please enter another" << endl;
					cin >> sizeflat;
					i = 0;
					break;
				}
            }
		}
		
		if (sizeflat <= sizeflat1)
		{
			tests[this->count - 1]->flat = sizeflat;
		}

	} while (sizeflat > sizeflat1);
}

void Test::Sort()
{
	int x;
	int y;
	for (int i = 1; i < sizeflat1; i++)
	{
		x = tests[i]->flat;
		y = tests[i]->rooms;
		int j = i - 1;
		while (x < tests[j]->flat)
		{
			tests[j + 1]->flat = tests[j]->flat;
			tests[j + 1]->rooms = tests[j]->rooms;
			j--;
			if (j < 0)
				break;
		}
		tests[j + 1]->flat = x;
		tests[j + 1]->rooms = y;
	}
}

void Test::print()
{
	cout << "Flat numbr " << flat << "  Rooms  " << rooms << endl;
		
	for (int i = 0; i < size; i++)
	{
		humans[i]->print();
	}
	cout << "-------------------------------------" << endl;
}

void Test::print1()
{
	for (int i = 0; i < sizeflat1; i++)
	{
		tests[i]->print();
	}
}

void Test::menu()
{
	while (true)
	{
		system("cls");
		cout << "1.Create a house\n2.Add human in flat\n3.Print flat\n4.Sort\n5.Dell human\n6.Exit" << endl;
		int c = 0;
		cin >> c;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "You didn'n enter a number" << endl;
			system("pause");
			system("cls");
			cout << "1.Create a house\n2.Add human in flat\n3.Print flat\n4.Sort\n5.Exit" << endl;
			cin >> c;
		}
		switch (c)
		{
		case 1:
			system("cls");
			cout << "Create a house" << endl;
			SetHouse();
			break;
		case 2:
			system("cls");
			cout << "Add human in flat" << endl;
			print1();
			addHumansInFlat();
			break;
		case 3:
			system("cls");
			cout << "Print flat" << endl;
			print1();
			system("pause");
			break;
		case 4:
			system("cls");
			Sort();
			break;
		case 5:
			system("cls");
			print1();
			dellHumansInFlat();
			break;
		case 6:
			system("cls");
			cout << "Exit" << endl;
			break;
		}
		if (c == 6)
			break;
	}
}



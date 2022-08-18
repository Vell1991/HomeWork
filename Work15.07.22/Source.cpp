#include <iostream>
#include"Header.h"


using namespace std;



int main()
{
	setlocale(LC_ALL, "ru");
	
	Fraction f1(-1, 2, 6);
	f1.print();
	Fraction f2(3, 5);
	f2.print();
	f1.operator+(f2);
	f1.print();
	
	system("pause");
	return 0;
}
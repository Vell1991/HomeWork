#include <iostream>
#include"Header.h"
#include"Function.h"


using namespace std;



int main()
{
	setlocale(LC_ALL, "ru");
	
	Fraction f1(2, 4);
	f1.print();
	Fraction f2(-1, 3, 7);
	f2.print();
	Fraction f3;
	transformation(f1);
	transformation(f2);
	f3 = f1 - f2;
	f3.print();
	f2.print();
	f1.print();
	transformation(f1);
	transformation(f2);
	f3 = f1 * f2;
	f3.print();
	f2.print();
	f1.print();
	transformation(f1);
	transformation(f2);
	bool result = f1 >= f2;
	transformation(f3);
	transformation(f2);
	f3 *= f2;
	f3.print();
	transformation(f3);
	f3 /= f2;
	f3.print();
	transformation(f1);
	transformation(f2);
	f3 = f1 % 3;
	f3.print();
	transformation(f3);
	++f3;
	f3.print();
	transformation(f3);
	f3++;
	f3.print();
	transformation(f3);
	--f3;
	f3.print();
	transformation(f3);
	f3--;
	f3.print();

	system("pause");
	return 0;
}
#include <iostream>
#include<time.h>
#include<string>
#include"Array.h"
#include"var.h"


using namespace std;



int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	Array arr(3);
	arr.print();
	arr[2];
	arr(3);
	arr.print();
	cout << arr[2] << endl;
	Array arr2;
	arr2.print();
	cout << arr.operator int() << endl;
	arr.print();
	cout << arr["one"] << endl;

	var a(1);
	var b("World");
	var c("Hello10,1.2");
	var d;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	b = c + a;
	cout << b << endl;
	
	system("pause");
	return 0;
}
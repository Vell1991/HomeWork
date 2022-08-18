#include"String.h"


int main()
{
	setlocale(LC_ALL, "ru");

	MyString str1("Hello");
	str1.print();

	MyString str2("World");
	str2.print();



	bool result = str1 == str2;
	cout << result << endl;

	MyString str3 = str1 + str2;
	str3.print();

	str3 = str2 - "H";
	str3.print();

	MyString str4;
	str4.set();
	str4.print();
	str3 = str2 + str4 + str1;
	str3.print();

	bool result2 = str2 == str4;
	cout << result2 << endl;

	MyString str5(5);
	str5.print();

	MyString str6("privet");

	cout << str6.get() << endl;
	str6[0] = 'T';
	str6.print();

	MyString str7("5");
	MyString str11;
	str11 = str7.operator+(str6);
	str11.print();

	MyString str8("Y");
	str8.operator+=(str8);
	str8.print();

	MyString str9("125");
	MyString str10("3632");
	str9.operator>(str10);

	str10.operator+=("h");
	str10.print();

	str10(str9);
	str10.print();

	str10.operator()("h");
	str10.print();
	
	system("pause");
	return 0;
}
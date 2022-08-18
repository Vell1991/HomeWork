#include <iostream>
#include "Header.h"


using namespace std;



int main()
{
	setlocale(LC_ALL, "ru");
	
	Fractions frac1(7, 1, 5);
	Fractions frac2(9, 3, 4);
	Fractions frac3(0,0,0);
	Fractions f;
	

	/*cout << "Сложение дробей" << endl;
	frac3.additionFractions(frac1, frac2);
	frac3.reduction(frac3);
	frac3.transformationFractions(frac3);
	frac3.print();*/

	cout << "Вычитание дробей" << endl;
	frac3.subtractionFractions(frac1, frac2);
	frac3.reduction(frac3);
	frac3.transformationFractions(frac3);
	frac3.print();

	/*cout << "Умножение дробей" << endl;
	frac3.multiplyFractions(frac1, frac2);
	frac3.reduction(frac3);
	frac3.transformationFractions(frac3);
	frac3.print();*/

	/*cout << "Деление дробей" << endl;
	frac3.divisionFractions(frac1, frac2);
	frac3.reduction(frac3);
	frac3.transformationFractions(frac3);
	frac3.print();*/
	
	
	system("pause");
	return 0;
}
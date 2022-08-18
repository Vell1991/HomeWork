#pragma once
#include <iostream>

using namespace std;

class Fractions
{
	int numerator;
	int denominator;
	int integer = 0;

public:
	Fractions();
	Fractions(int numerator, int denominator)
	{
		SetNumerator(numerator);
		Setdenominator(denominator);
		print();
	}
	Fractions(int integer, int numerator, int denominator)
	{
		SetInteger(integer);
		SetNumerator(numerator);
		Setdenominator(denominator);
		print();
	}
	
	void SetInteger(int integer)
	{
		if(integer !=0)
		this->integer = integer;
	}
	int GetInteger()
	{
		if (integer != 0)
		{
			return this-> integer;
		}
	}

	void SetNumerator(int numerator)
	{
		this->numerator = numerator;
	}
	int GetNumerator()
	{
		return numerator;
	}

	void Setdenominator(int denominator)
	{
		this->denominator = denominator;
	}
	int Getdenominator()
	{
		return denominator;
	}

	void print()
	{
		if (integer == 0 && numerator != 0)
			cout << "Дробь " << numerator << "/" << denominator << endl;
		else if (integer != 0 && numerator == 0)
			cout << "Дробь " << integer << endl;
		else if (numerator == 0)
			cout << "Дробь " << numerator << endl;
		else
			cout << "Дробь " << integer << ", " << numerator << "/" << denominator << endl;
		cout << "----------------------------------------" << endl;
	}

	void additionFractions(Fractions one, Fractions two)
	{
		if (one.denominator == two.denominator)
		{
			this->integer = one.integer + two.integer;
			this->numerator = one.numerator + two.numerator;
			this->denominator = one.denominator;
		}
		else if (one.denominator != two.denominator)
		{
			for (int i = 1; i <= (one.denominator * two.denominator); i++)
			{
				if ((i % one.denominator == 0) && (i % two.denominator == 0))
				{
					this->denominator = i;
					one.numerator = one.numerator * (i / one.denominator);
					two.numerator = two.numerator * (i / two.denominator);
					break;
				}
			}
			this->integer = one.integer + two.integer;
			this->numerator = one.numerator + two.numerator;
		}
	}
	void subtractionFractions(Fractions one, Fractions two)
	{

		if (one.denominator == two.denominator)
		{
			this->integer = one.integer - two.integer;
			this->numerator = one.numerator - two.numerator;
			this->denominator = one.denominator;
		}
		else if (one.denominator != two.denominator)
		{
			for (int i = 1; i <= (one.denominator * two.denominator); i++)
			{
				if ((i % one.denominator == 0) && (i % two.denominator == 0))
				{
					this->denominator = i;
					one.numerator = one.numerator * (i / one.denominator);
					two.numerator = two.numerator * (i / two.denominator);
					break;
				}
			}
			this->integer = one.integer - two.integer;
			this->numerator = one.numerator - two.numerator;
		}
	}
	void multiplyFractions(Fractions& one, Fractions& two) // умножение дробей
	{
		if (one.integer == 0 && two.integer == 0)
		{
			this->numerator = one.numerator * two.numerator;
			this->denominator = one.denominator * two.denominator;
	    }
		else if(one.numerator == 0 && one.integer != 0 && two.integer == 0)
		{
			this->numerator = one.integer * two.numerator;
			this->denominator = two.denominator;
		}
		else if (two.numerator == 0 && two.integer != 0 && one.numerator != 0)
		{
			this->numerator = one.numerator * two.integer;
			this->denominator = one.denominator;
		}
		else if (one.integer != 0 && one.numerator != 0 && two.integer == 0)
		{
			this->numerator = dereduction(one) * two.numerator;
			this->denominator = one.denominator * two.denominator;
		}
		else if (two.integer != 0 && two.numerator != 0 && one.integer == 0)
		{
			this->numerator = dereduction(two) * one.numerator;
			this->denominator = one.denominator * two.denominator;
		}
		else if (one.integer != 0 && one.numerator != 0 && two.integer != 0 && two.numerator == 0)
		{
			this->numerator = dereduction(one) * two.integer;
			this->denominator = one.denominator;
		}
		else if (two.integer != 0 && two.numerator != 0 && one.integer != 0 && one.numerator == 0)
		{
			this->numerator = dereduction(two) * one.integer;
			this->denominator = two.denominator;
		}
		else if (one.integer != 0 && one.numerator != 0 && two.integer != 0 && two.numerator != 0 && one.denominator != 0 && two.denominator != 0)
		{
			this->numerator = dereduction(one) * dereduction(two);
			this->denominator = one.denominator * two.denominator;
		}
		else if ((one.denominator == 0 || two.denominator == 0) && (one.integer == 0 && two.integer == 0))
		{
			cout << "Eror 404" << endl;
		}
		else if ((one.integer != 0 && two.integer != 0) && (one.numerator == 0 && two.numerator == 0) && (one.denominator == 0 && two.denominator == 0))
		{
			this->integer = one.integer * two.integer;
		}
	}
	void divisionFractions(Fractions& one, Fractions& two) //деление дробей
	{
		if ((one.integer == 0 && one.numerator != 0 && one.denominator != 0) && (two.integer == 0 && two.numerator != 0 && two.denominator != 0))
		{
			this->numerator = one.numerator * two.denominator;
			this->denominator = one.denominator * two.numerator;
		}
		else if ((one.integer != 0 && one.numerator != 0 && one.denominator != 0) && (two.integer == 0 && two.numerator != 0 && two.denominator != 0))
		{
			this->numerator = dereduction(one) * two.denominator;
			this->denominator = one.denominator * two.numerator;
		}
		else if ((one.integer == 0 && one.numerator != 0 && one.denominator != 0) && (two.integer != 0 && two.numerator != 0 && two.denominator != 0))
		{
			this->numerator = one.numerator * two.denominator;
			this->denominator = one.denominator * dereduction(two);
		}
		else if ((one.integer != 0 && one.numerator != 0 && one.denominator != 0) && (two.integer != 0 && two.numerator != 0 && two.denominator != 0))
		{
			this->numerator = dereduction(one) * two.denominator;
			this->denominator = one.denominator * dereduction(two);
		}
		else if ((one.integer != 0) && (two.integer != 0 && two.numerator != 0 && two.denominator != 0))
		{
			this->numerator = one.integer * two.denominator;
			this->denominator = dereduction(two);
		}
		else if ((one.integer != 0) && (two.integer == 0 && two.numerator != 0 && two.denominator != 0))
		{
			this->numerator = one.integer * two.denominator;
			this->denominator = two.numerator;
		}
		else if ((one.integer != 0 && one.numerator != 0 && one.denominator != 0) && (two.integer !=0 ))
		{
			this->numerator = dereduction(one);
			this->denominator = one.denominator * two.integer;
		}
		else if ((one.integer == 0 && one.numerator != 0 && one.denominator != 0) && (two.integer != 0))
		{
			this->numerator = one.numerator;
			this->denominator = one.denominator * two.integer;
		}
		else if ((one.integer != 0 && one.numerator == 0 && one.denominator == 0) && (two.integer != 0 && two.numerator == 0 && two.denominator == 0))
		{
			this->numerator = one.integer;
			this->denominator = two.integer;
		}

	}

	void transformationFractions(Fractions three) // преобразование дроби с неправильной в правильную
	{
		if (three.denominator != 0)
		{
			while (three.numerator >= three.denominator)
			{
				this->numerator = three.numerator - three.denominator;
				three.numerator = three.numerator - three.denominator;
				if (numerator == 0)
				{
					this->denominator = 0;
				}
				this->integer++;
			}
		}
	}
	void reduction(Fractions three) // сокращение дроби
	{	
		for (int i = 2; i <= (three.numerator + three.denominator); i++)
			{
			if ((three.numerator % i == 0) && (three.denominator % i == 0))
			{
				this->numerator = three.numerator / i;
				this->denominator = three.denominator / i;
			}
		}
	}
	int dereduction(Fractions three) // превращение в неправильную дробь
	{
		return three.numerator = three.denominator * three.integer + three.numerator;
	}
};
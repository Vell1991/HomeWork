#pragma once
#include"Header.h"

void transformation(Fraction& other)
{
	if (other.integer > 0)
	{
		other.nom = other.nom + other.integer * other.den;
		other.integer = 0;
	}
	else if (other.integer < 0)
	{
		other.nom = other.nom *-1 + other.integer * other.den;
		other.integer = 0;
	}
}

void transformProperFract(Fraction& other)
{
	if (other.nom < 0)
	{

		if ((other.nom * -1) > other.den)
		{
			other.integer = (other.nom / other.den);
			other.nom -= other.integer * other.den;
			other.nom *= -1;
		}
	}
	else
	{
		if (other.nom > other.den)
		{
			other.integer = (other.nom / other.den);
			other.nom -= other.integer * other.den;
		}
	}
}

void rounding(Fraction& other)
{
	if (other.den < 0)
	{
		other.den *= -1;
		other.nom *= -1;
	}
	for (int i = other.den; i > 0; i--)
	{
		if (other.nom % i == 0 && other.den % i == 0)
		{
			other.nom = other.nom / i;
			other.den = other.den / i;
		}
	}
}

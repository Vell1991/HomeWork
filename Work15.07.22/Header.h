#pragma once

using namespace std;

class Fraction
{
	int nom = 0;
	int den = 0;
	int integer = 0;
public:
	Fraction(){}
	Fraction(int nom, int den) : nom(nom), den(den) {}
	Fraction(int integer, int nom, int den) : integer(integer), nom(nom), den(den){}
	Fraction (Fraction& other) :integer(other.integer), nom(other.nom), den(other.den) {}
	

	Fraction operator=(Fraction& other);
	Fraction operator+(Fraction& other);
	Fraction operator-(Fraction& other);
	Fraction operator*(Fraction& other);
	Fraction operator/(Fraction& other);
	Fraction operator+=(Fraction& other);
	Fraction operator-=(Fraction& other);
	void transformation(Fraction& other);
	void transformProperFract(Fraction& other);
	void rounding(Fraction& other);
	void print();
};

Fraction Fraction::operator=(Fraction& other)
{
	this->nom = other.nom;
	this->den = other.den;
	return *this;
}

Fraction Fraction::operator+(Fraction& other)
{
	transformation(*this);
	transformation(other);
	if (this->den == other.den || (this->den == 0 || other.den == 0))
	{
		this->nom = this->nom + other.nom;
		if (this->den == 0 || other.den == 0)
			this->den = this->den + other.den;
	}
	else
	{
		this->nom = this->nom * other.den + other.nom * this->den;
		this->den = this->den * other.den;
	}
	rounding(*this);
	transformProperFract(*this);
	return *this;
}

Fraction Fraction::operator-(Fraction& other)
{
	if (this->den == other.den)
	{
		this->nom -= other.nom;
		this->den = other.den;
	}
	else
	{
		this->nom = this->nom * other.den - other.nom * this->den;
		this->den *= other.den;
	}
	return *this;
}

Fraction Fraction::operator*(Fraction& other)
{
	this->nom *= other.nom;
	this->den *= other.den;
	rounding(*this);
	return *this;
}

Fraction Fraction::operator/(Fraction& other)
{
	this->nom *= other.den;
	this->den *= other.nom;
	rounding(*this);
	return *this;
}

Fraction Fraction::operator+=(Fraction& other)
{

	if (this->den == other.den || (this->den == 0 || other.den == 0))
	{
		this->nom += other.nom;
		if (this->den == 0 || other.den == 0)
			this->den += other.den;
	}
	else
	{
		this->nom = this->nom * other.den + other.nom * this->den;
		this->den = this->den * other.den;
	}
	rounding(*this);
	return *this;
}

void Fraction::transformation(Fraction& other)
{
	if (other.integer)
	{
		other.nom =(other.nom * other.integer) + other.integer * other.den;
		other.integer = 0;
	}
}

void Fraction::transformProperFract(Fraction& other)
{
	if (other.nom > other.den)
		other.integer = other.nom / other.den;
	other.nom -= other.integer * other.den;
}

void Fraction::rounding(Fraction& other)
{
	for (int i = 1; i < other.den; i++)
	{
		if (other.nom % i == 0 && other.den % i == 0)
		{
			this->nom = other.nom / i;
			this->den = other.den / i;
		}
	}
}

void Fraction::print()
{
	if (this->integer != 0)
		cout << integer << "," << nom << "/" << den << endl;
	else
		cout << nom << "/" << den << endl;
 }
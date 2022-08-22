#pragma once

using namespace std;

class Fraction
{
	int nom = 0;
	int den = 0;
	int integer = 0;
public:
	Fraction() {}
	Fraction(int nom, int den) : nom(nom), den(den) {}
	Fraction(int integer, int nom, int den) : integer(integer), nom(nom), den(den){}
	~Fraction(){}
	
	Fraction(Fraction& other);
	Fraction operator()(Fraction& other);
	Fraction operator+(const Fraction& other);
	Fraction operator-(const Fraction& other);
	Fraction operator*(const Fraction& other);
	Fraction operator*=(const Fraction& other);
	Fraction operator/(const Fraction& other);
	Fraction operator/=(const Fraction& other);
	Fraction operator+=(const Fraction& other);
	Fraction operator-=(const Fraction& other);
	const bool operator!();
	operator bool();
	const bool operator&&(Fraction& other);
	const bool operator||(Fraction& other);
	Fraction operator++();
	Fraction operator++(int);
	Fraction operator--();
	Fraction operator--(int);
	Fraction operator%(int s);
	bool operator==(Fraction& other);
	bool operator!=(Fraction& other);
	bool operator>(Fraction& other);
	bool operator<(Fraction& other);
	bool operator>=(Fraction& other);
	bool operator<=(Fraction& other);
	
	void print();

	friend void transformation(Fraction& other);
	friend void transformProperFract(Fraction& other);
	friend void rounding(Fraction& other);
};

Fraction::Fraction(Fraction& other)
{
	this->nom = other.nom;
	this->den = other.den;
	this->integer = other.integer;
}

Fraction Fraction::operator()(Fraction& other)
{
	this->nom = other.nom;
	this->den = other.den;
	this->integer = other.integer;
	return *this;
}

Fraction Fraction::operator+(const Fraction& other)
{
	Fraction temp;
	if (this->den == other.den || (this->den == 0 || other.den == 0))
	{
		temp.nom = this->nom + other.nom;
		if (this->den == 0 || other.den == 0)
			temp.den = this->den + other.den;
	}
	else
	{
		temp.nom = this->nom * other.den + other.nom * this->den;
		temp.den = this->den * other.den;
	}
	rounding(temp);
	return temp;
}

Fraction Fraction::operator-(const Fraction& other)
{
	Fraction temp;
	if (this->den == other.den)
	{
		temp.nom =this->nom - other.nom;
		temp.den = other.den;
	}
	else
	{
		temp.nom = this->nom * other.den - other.nom * this->den;
		temp.den = this->den * other.den;
	}
	rounding(temp);
	return temp;
}

Fraction Fraction::operator*(const Fraction& other)
{
	Fraction temp;
	temp.nom =this->nom * other.nom;
	temp.den = this->den * other.den;
	rounding(temp);
	return temp;
}

Fraction Fraction::operator*=(const Fraction& other)
{
	this->nom *= other.nom;
	this->den *= other.den;
	rounding(*this);
	return *this;
}

Fraction Fraction::operator/(const Fraction& other)
{
	Fraction temp;
	temp.nom = this->nom * other.den;
	temp.den = this->den * other.nom;
	rounding(temp);
	return temp;
}

Fraction Fraction::operator++()
{
	this->nom += this->den;
	return *this;
}

Fraction Fraction::operator++(int)
{
	Fraction temp;
	temp(*this);
	this->nom += this->den;
	return temp;
}

Fraction Fraction::operator--()
{
	this->nom -= this->den;
	return *this;
}

Fraction Fraction::operator--(int)
{
	Fraction temp;
	temp(*this);
	this->nom -= this->den;
	return temp;
}

const bool Fraction::operator!()
{
	return !this;
}

Fraction::operator bool()
{
	if (this->integer != 0 || (this->nom != 0 && this->den != 0))
		return true;
	else
		return false;
}

const bool Fraction::operator&&(Fraction& other)
{
	return *this && other;
}

const bool Fraction::operator||(Fraction& other)
{
	return *this || other;
}

Fraction Fraction::operator%(int s)
{
	Fraction temp;
	temp.nom = this->nom % s;
	temp.den = this->den % s;
	rounding(temp);
	return temp;
}

Fraction Fraction::operator/=(const Fraction& other)
{
	this->nom = this->nom * other.den;
	this->den = this->den * other.nom;
	rounding(*this);
	return *this;
}

Fraction Fraction::operator+=(const Fraction& other)
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

bool Fraction::operator==(Fraction& other)
{
	return this->integer == other.integer && this->nom == other.nom && this->den == other.den;
}

bool Fraction::operator!=(Fraction& other)
{
	return !(this->integer == other.integer && this->nom == other.nom && this->den == other.den);
}

bool Fraction::operator>(Fraction& other)
{
	return (float(this->nom)/float(this->den)) > (float(other.nom)/float(other.den));
}

bool Fraction::operator<(Fraction& other)
{
	return !((float(this->nom) / float(this->den)) > (float(other.nom) / float(other.den)));
}

bool Fraction::operator>=(Fraction& other)
{
	return (float(this->nom) / float(this->den)) >= (float(other.nom) / float(other.den));
}

bool Fraction::operator<=(Fraction& other)
{
	return !((float(this->nom) / float(this->den)) >= (float(other.nom) / float(other.den)));
}

void Fraction::print()
{
	transformProperFract(*this);
	if (this->integer != 0 && this->nom != 0)
		cout << integer << "," << nom << "/" << den << endl;
	else if (this->nom == 0)
		cout << integer << endl;
	else
		cout << nom << "/" << den << endl;
 }
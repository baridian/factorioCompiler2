#include <iostream>

using namespace std;



class Fraction

{

private:

	int numerator;

	int denominator;

public:

	Fraction()

	{

		numerator = 0;

		denominator = 1;

	}

	Fraction(int numerator, int denominator)

	{

		this->numerator = numerator;

		this->denominator = denominator;

	}



	void print()

	{

		cout << numerator / denominator << " " << numerator % denominator << "/" << denominator;

	}



	Fraction operator+(Fraction second)

	{

		Fraction temp;

		temp.setNumerator(numerator * second.getDenominator() + denominator * second.getNumerator());

		temp.setDenominator(denominator * second.getDenominator());

		return temp.reduce();

	}

	Fraction operator-(Fraction second)

	{

		Fraction temp;

		temp.setNumerator(numerator * second.getDenominator() - denominator * second.getNumerator());

		temp.setDenominator(denominator * second.getDenominator());

		return temp.reduce();

	}

	Fraction operator*(Fraction second)

	{

		Fraction temp;

		temp.setNumerator(numerator * second.getNumerator());

		temp.setDenominator(denominator * second.getDenominator());

		return temp.reduce();

	}

	Fraction operator/(Fraction second)

	{

		Fraction temp;

		temp.setNumerator(numerator * second.getDenominator());

		temp.setDenominator(denominator * second.getNumerator());

		return temp.reduce();

	}

	bool operator<(Fraction second)

	{

		return ((double)numerator / denominator) < ((double)second.getNumerator() / second.getDenominator());

	}

	bool operator<=(Fraction second)

	{

		return ((double)numerator / denominator) <= ((double)second.getNumerator() / second.getDenominator());

	}

	bool operator>(Fraction second)

	{

		return ((double)numerator / denominator) > ((double)second.getNumerator() / second.getDenominator());

	}

	bool operator>=(Fraction second)

	{

		return ((double)numerator / denominator) >= ((double)second.getNumerator() / second.getDenominator());

	}



	bool operator==(Fraction second)

	{

		return ((double)numerator / denominator) == ((double)second.getNumerator() / second.getDenominator());

	}

	bool operator!=(Fraction second)

	{

		return ((double)numerator / denominator) != ((double)second.getNumerator() / second.getDenominator());

	}



	void setNumerator(int num)

	{

		numerator = num;

	}

	void setDenominator(int den)

	{

		denominator = den;

	}

	int getNumerator()

	{

		return numerator;

	}

	int getDenominator()

	{

		return denominator;

	}

	//Method to reduce fraction

	int gcd()

	{

		int mn = min();

		int mx = max();

		for (int x = mn; x > 0; x--)

			if (mx % x == 0 && mn % x == 0) return x;

		return 1;

	}

	Fraction reduce()

	{

		int tmp = gcd();

		return Fraction(numerator / tmp, denominator / tmp);

	}

	int max() { return (numerator >= denominator) ? numerator : denominator; }

	int min() { return (numerator >= denominator) ? denominator : numerator; }

	//Stream Insertion

	friend ostream& operator<<(ostream&, const Fraction&);

	//Stream Extraction

	friend istream& operator>>(istream&, Fraction&);

};

ostream& operator<<(ostream& output, Fraction& c)

{

	output << c.getNumerator() << "/" << c.getDenominator();

	return output;

}

istream& operator>>(istream& input, Fraction& c)

{

	char ch;

	input >> c.numerator >> ch >> c.denominator;

	return input;

}



int main()

{

	Fraction f1, f2, summation, difference, product, quotient;

	cout << "Enter The First Fraction in The Form Numerator/Denominator: ";

	cin >> f1;

	cout << "Enter The Second Fraction in The Form Numerator/Denominator: ";

	cin >> f2;

	cout << "The First fraction is: " << f1 << endl << endl;

	cout << "The Second fraction is: " << f2 << endl << endl;

	summation = f1 + f2;

	difference = f1 - f2;

	product = f1 * f2;

	quotient = f1 / f2;

	cout << "The sum of both fractions is: " << summation << endl << endl;

	cout << "The difference of both fracions is: " << difference << endl << endl;

	cout << "the product of both fractions is: " << product << endl << endl;

	cout << "The quotient of both fractions is: " << quotient << endl << endl;



	if (f1 < f2)

		cout << f1 << " < " << f2 << endl;

	else

		cout << f1 << " < " << f2 << endl;



	if (f1 <= f2)

		cout << f1 << " <= " << f2 << endl;

	else

		cout << f1 << " <= " << f2 << endl;



	if (f1 > f2)

		cout << f1 << " > " << f2 << endl;

	else

		cout << f1 << " > " << f2 << endl;



	if (f1 >= f2)

		cout << f1 << " >= " << f2 << endl;

	else

		cout << f1 << " >= " << f2 << endl;



	if (f1 == f2)

		cout << "fraction 1 equals fraction 2" << endl;

	else

		cout << "fraction 1 does not equal fraction 2" << endl;

	if (f1 != f2)

		cout << "fraction 1 does not equal faction 2" << endl;

	else

		cout << "fraction 1 equals fraction 2" << endl;



	return 0;

}


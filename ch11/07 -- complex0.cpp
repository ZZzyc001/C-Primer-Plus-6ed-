// complex0.cpp
#include "complex0.h"

complex::complex()
{
	real = image = 0.0;
}

complex::complex(double x, double y)
{
	real = x, image = y;
}

complex complex::operator+(const complex& c) const
{
	return complex(real + c.real, image + c.image);
}

complex complex::operator-(const complex& c) const
{
	return complex(real - c.real, image - c.image);
}

complex complex::operator~() const
{
	return complex(real, -image);
}

complex complex::operator*(const complex& c) const
{
	return complex(real * c.real - image * c.image, real * c.image + image * c.real);
}

complex complex::operator*(double d) const
{
	return complex(real * d, image * d);
}

complex operator*(double d, const complex& c)
{
	return c * d;
}

std::istream& operator>>(std::istream& is, complex& c)
{
	std::cout << "real: ";
	is >> c.real;
	if (!is)
		return is;
	std::cout << "imaginary: ";
	is >> c.image;
	return is;
}

std::ostream& operator<<(std::ostream& os, const complex& c)
{
	os << '(' << c.real << ',' << c.image << "i)";
	return os;
}

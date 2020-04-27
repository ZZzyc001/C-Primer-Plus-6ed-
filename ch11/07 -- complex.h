// complex0.h
#ifndef COMPLEX0_H_
#define COMPLEX0_H_
#include <iostream>
struct complex
{
private:
	double real;
	double image;
public:
	complex();
	complex(double x, double y);
	~complex() {}
	complex operator+ (const complex& c) const;
	complex operator- (const complex& c) const;
	complex operator~ () const;
	complex operator* (const complex& c) const;
	complex operator* (double d) const;
	friend complex operator* (double d, const complex& c);
	friend std::istream& operator>> (std::istream& is, complex& c);
	friend std::ostream& operator<< (std::ostream& os, const complex& c);
};
#endif 

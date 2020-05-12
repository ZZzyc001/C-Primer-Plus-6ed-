// winec.h
#ifndef WINEC_H_
#define WINEC_H_
#include <iostream>
#include <string>
#include <valarray>

// pairs class
template <class T1, class T2>
class Pair
{
private:
	T1 a;
	T2 b;
public:
	T1& first() { return a; }
	T2& second() { return b; }
	T1 first() const { return a; }
	T2 second() const { return b; }
	Pair(const T1& aval, const T2& bval) : a(aval), b(bval) {}
	Pair() {}
};

class Wine : private std::string,
	private Pair< std::valarray<int>, std::valarray<int> >
{
private:
	typedef std::valarray<int> ArrayInt;
	typedef Pair<ArrayInt, ArrayInt> PairArray;
	int num;
public:
	Wine() : std::string(""), num(0) {}
	Wine(const char* l, int y, const int yr[], const int bot[]);
	Wine(const char* l, int y);
	void GetBottles();
	const std::string& Lable() const;
	int sum() const;
	void Show() const;
};
#endif // !WINEC_H_

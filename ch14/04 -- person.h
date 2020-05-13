// person.h
#ifndef PERSON_H_
#define PERSON_H_
#include <string>
using std::string;

class Person
{
private:
	string firstname;
	string lastname;
protected:
	virtual void Data() const;
	virtual void Get();
public:
	Person() : firstname(""), lastname("") {}
	Person(const string& fn, const string& ln)
		: firstname(fn), lastname(ln) {}
	Person(const char* fn, const char* ln)
		: firstname(fn), lastname(ln) {}
	virtual ~Person() = 0;
	virtual void Show() const = 0;
	virtual void Set() = 0;
};

class Gunslinger : virtual public Person
{
private:
	double draw;
	int mark;
protected:
	void Data() const;
	void Get();
public:
	Gunslinger() : Person(), draw(0), mark(0) {}
	Gunslinger(const string& fn, const string& ln, double d = 0, int n = 0)
		: Person(fn, ln), draw(d), mark(n) {}
	Gunslinger(const Person& p, double d = 0, int n = 0)
		: Person(p), draw(d), mark(n) {}
	double Draw() const { return draw; }
	void Show() const;
	void Set();
};

class PokerPlayer : virtual public Person
{
private:
	int num;
protected:
	void Data() const;
	void Get();
public:
	PokerPlayer() : Person(), num(0) {}
	PokerPlayer(const string& fn, const string& ln, int n = 0)
		: Person(fn, ln), num(n) {}
	PokerPlayer(const Person& p, int n = 0)
		: Person(p), num(n) {}
	void Set();
	int Draw() { return num = rand() % 52 + 1; }
	void Show() const;
};

class BadDude : public Gunslinger, public PokerPlayer
{
protected:
	void Data() const;
	void Get();
public:
	BadDude() {}
	BadDude(const string& fn, const string& ln, double d = 0, int m = 0, int n = 0)
		: Person(fn, ln), Gunslinger(fn, ln, d, m), PokerPlayer(fn, ln, n) {}
	BadDude(const Person& p, double d = 0, int m = 0, int n = 0)
		: Person(p), Gunslinger(p, d, m), PokerPlayer(p, n) {}
	BadDude(const Gunslinger& gs, int n = 0)
		: Person(gs), Gunslinger(gs), PokerPlayer(gs, n) {}
	BadDude(const PokerPlayer& pp, double d = 0, int m = 0)
		: Person(pp), Gunslinger(pp, d, m), PokerPlayer(pp) {}
	void Set();
	double Gdraw() { return Gunslinger::Draw(); }
	int Cdraw() { return PokerPlayer::Draw(); }
	void Show() const;
};
#endif
// !PERSON_H_

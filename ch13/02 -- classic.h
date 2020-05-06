// classic.h

// base class
class Cd
{
private:
	char* performers;
	char* label;
	int selections;
	double playtime;
public:
	Cd(const char* s1, const char* s2, int n, double x);
	Cd(const Cd& d);
	Cd();
	~Cd();
	virtual void Report() const;
	Cd& operator=(const Cd& d);
};

// Classic class
class Classic : public Cd
{
private:
	char* mainlabel;
public:
	Classic(const char* s, const char* s1,
		const char* s2, int n, double x);
	Classic(const char* s, const Cd& d);
	Classic(const Classic& c);
	Classic();
	~Classic();
	virtual void Report() const;
	Classic& operator=(const Classic& c);
};

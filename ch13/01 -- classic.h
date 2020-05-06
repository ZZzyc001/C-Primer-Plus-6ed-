// classic.h

// base class
class Cd
{
private:
	char performers[50];
	char label[20];
	int selections;
	double playtime;
public:
	Cd(const char* s1, const char* s2, int n, double x);
	Cd();
	virtual void Report() const;
};

// Classic class
class Classic : public Cd
{
private:
	char mainlabel[40];
public:
	Classic(const char* s, const char* s1,
		const char* s2, int n, double x);
	Classic();
	virtual void Report() const;
};

// plorg.h
#ifndef PLORG_H_
#define PLORG_H_

class Plorg
{
private:
	char name[20];
	int CI;
public:
	Plorg(const char* ar = "Plorga", int c = 50);
	void setCI(int c);
	void show() const;
};
#endif 

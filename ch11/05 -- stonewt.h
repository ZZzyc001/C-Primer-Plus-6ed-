// stonewt.h
#ifndef STONEWT_H_
#define STONEWT_H_
#include <iostream>
class Stonewt
{
private:
	enum { Lbs_per_stn = 14 };
	enum Mode { LBS, STN };
	int stone;
	double pds_left;
	double pounds;
	Mode form;
public:
	Stonewt(double lbs, Mode m = LBS);
	Stonewt(int stn, double lbs, Mode m = LBS);
	Stonewt();
	~Stonewt();
	void LBSmode();
	void STNmode();
	Stonewt operator+(const Stonewt& t) const;
	Stonewt operator-(const Stonewt& t) const;
	Stonewt operator*(double n) const;
	friend Stonewt operator*(double n, const Stonewt& t);
	friend std::ostream& operator<<(std::ostream& os, const Stonewt& t);
};
#endif

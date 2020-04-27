// stonewt.cpp
#include "stonewt.h"
using std::cout;

Stonewt::Stonewt(double lbs, Mode m)
{
	stone = int(lbs) / Lbs_per_stn;
	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
	form = m;
}

Stonewt::Stonewt(int stn, double lbs, Mode m)
{
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn + lbs;
	form = m;
}

Stonewt::Stonewt()
{
	stone = pounds = pds_left = 0;
	form = LBS;
}

Stonewt::~Stonewt()
{
}

void Stonewt::LBSmode()
{
	form = LBS;
}

void Stonewt::STNmode()
{
	form = STN;
}

Stonewt Stonewt::operator+(const Stonewt& t) const
{
	return Stonewt(pounds + t.pounds);
}

Stonewt Stonewt::operator-(const Stonewt& t) const
{
	return Stonewt(pounds - t.pounds);
}

Stonewt Stonewt::operator*(double n) const
{
	return Stonewt(n * pounds);
}

Stonewt operator*(double n, const Stonewt& t)
{
	return t * n;
}

std::ostream& operator<<(std::ostream& os, const Stonewt& t)
{
	if (t.form == Stonewt::Mode::LBS)
		os << t.pounds << " pounds\n";
	else if (t.form == Stonewt::Mode::STN)
		os << t.stone << " stone, " << t.pds_left << " pounds\n";
	return os;
}

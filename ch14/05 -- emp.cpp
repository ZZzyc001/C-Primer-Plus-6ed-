#include "emp.h"

using std::cin;
using std::cout;
using std::endl;

abstr_emp::~abstr_emp() {}

abstr_emp::abstr_emp() : fname(""), lname(""), job("") {}

abstr_emp::abstr_emp(const std::string& fn,
	const std::string& ln, const std::string& j)
	: fname(fn), lname(ln), job(j) {}

void abstr_emp::ShowAll() const
{
	cout << "First Name: " << fname << endl;
	cout << "Last Name: " << lname << endl;
	cout << "Job: " << job << endl;
}

void abstr_emp::SetAll()
{
	cout << "Please enter the first name: ";
	getline(cin, fname);
	cout << "Please enter the last name: ";
	getline(cin, lname);
	cout << "Please enter the job: ";
	getline(cin, job);
}

std::ostream& operator<<(std::ostream& os, const abstr_emp& e)
{
	os << "first name: " << e.fname << ", last name: "
		<< e.lname << ", job: " << e.job;
	return os;
}

employee::employee() : abstr_emp() {}

employee::employee(const std::string& fn,
	const std::string& ln, const std::string& j)
	: abstr_emp(fn, ln, j) {}

void employee::ShowAll() const
{
	cout << "This is employee\n";
	abstr_emp::ShowAll();
}

void employee::SetAll()
{
	cout << "This is employee\n";
	abstr_emp::SetAll();
}

manager::manager() : abstr_emp(), inchargeof(0) {}

manager::manager(const std::string& fn,
	const std::string& ln, const std::string& j,
	int ico) : abstr_emp(fn, ln, j), inchargeof(ico) {}

manager::manager(const abstr_emp& e, int ico)
	: abstr_emp(e), inchargeof(ico) {}

manager::manager(const manager& m)
	: abstr_emp(m), inchargeof(m.inchargeof) {}

void manager::ShowAll() const
{
	cout << "This is manager\n";
	abstr_emp::ShowAll();
	cout << "In Charge Of is " << inchargeof << endl;
}

void manager::SetAll()
{
	cout << "This is manager\n";
	abstr_emp::SetAll();
	cout << "Please enter the in charge of: ";
	cin >> inchargeof;
	cin.get();
}

fink::fink() : abstr_emp(), reportsto("") {}

fink::fink(const std::string& fn, const std::string& ln,
	const std::string& j, const std::string& rpo)
	: abstr_emp(fn, ln, j), reportsto(rpo) {}

fink::fink(const abstr_emp& e, const std::string& rpo)
	: abstr_emp(e), reportsto(rpo) {}

fink::fink(const fink& e)
	: abstr_emp(e), reportsto(e.reportsto) {}

void fink::ShowAll() const
{
	cout << "This is a fink:\n";
	abstr_emp::ShowAll();
	cout << "Reports to: ";
	cout << reportsto << endl;
}

void fink::SetAll()
{
	cout << "This is a fink:\n";
	abstr_emp::SetAll();
	cout << "Please enter the reports to: ";
	getline(cin, reportsto);
}

highfink::highfink() : abstr_emp(), manager(), fink() {}

highfink::highfink(const std::string& fn, const std::string& ln,
	const std::string& j, const std::string& rpo,
	int ico) : abstr_emp(fn, ln, j), manager(fn, ln, j, ico),
	fink(fn, ln, j, rpo) {}

highfink::highfink(const abstr_emp& e,
	const std::string& rpo, int ico)
	: abstr_emp(e), manager(e, ico), fink(e, rpo) {}

highfink::highfink(const fink& f, int ico)
	: abstr_emp(f), manager(f, ico), fink(f) {}

highfink::highfink(const manager& m, const std::string& rpo)
	: abstr_emp(m), manager(m), fink(m, rpo) {}

highfink::highfink(const highfink& h)
	: abstr_emp(h), manager(h), fink(h) {}

void highfink::ShowAll() const
{
	cout << "This is a high fink:\n";
	abstr_emp::ShowAll();
	cout << "Please enter the in charge of: ";
	cout << InChargeOf() << endl;
	cout << "Please enter the reports to: ";
	cout << ReportsTo() << endl;
}

void highfink::SetAll()
{
	cout << "This is a high fink:\n";
	abstr_emp::SetAll();
	cout << "Please enter the in charge of: ";
	cin >> InChargeOf();
	cin.get();
	cout << "Please enter the reports to: ";
	std::getline(cin, ReportsTo());
}

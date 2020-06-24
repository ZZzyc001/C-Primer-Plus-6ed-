// emp.cpp
#include "emp.h"

/*******************
 * abstr_emp methods
 *******************/
abstr_emp::abstr_emp()
{
    fname = "none";
    lname = "none";
    job = "none";
}

abstr_emp::~abstr_emp() {}

void abstr_emp::ShowAll() const
{
    std::cout << "firstname: " << fname << std::endl;
    std::cout << "lastname: " << lname << std::endl;
    std::cout << "job: " << job << std::endl;
}

void abstr_emp::SetAll()
{
    std::cout << "Enter firstname: ";
    std::getline(std::cin, fname);
    std::cout << "Enter lastname: ";
    std::getline(std::cin, lname);
    std::cout << "Enter job: ";
    std::getline(std::cin, job);
}

std::ofstream& abstr_emp::WriteAll(std::ofstream& fout) const
{
    fout << fname << " " << lname << " " << job;
    return fout;
}

// friend functions
std::ostream& operator<<(std::ostream& os, const abstr_emp& e)
{
    os << e.lname << " " << e.fname << ", " << e.job;
    return os;
}

/******************
 * employee methods
 ******************/

void employee::ShowAll() const
{
    abstr_emp::ShowAll();
}

void employee::SetAll()
{
    abstr_emp::SetAll();
}

std::ofstream& employee::WriteAll(std::ofstream& fout) const
{
    fout << Employee << " ";
    abstr_emp::WriteAll(fout);
    return fout;
}


/*****************
 * manager methods
 *****************/

manager::manager(const abstr_emp& e, int ico)
    : abstr_emp(e)
{
    inchargeof = ico;
}

manager::manager(const manager& m)
    : abstr_emp(m)
{
    inchargeof = m.inchargeof;
}

void manager::ShowAll() const
{
    abstr_emp::ShowAll();
    std::cout << "Inchargeof: " << inchargeof << std::endl;
}

void manager::SetAll()
{
    abstr_emp::SetAll();
    std::cout << "Enter inchargeof: ";
    std::cin >> inchargeof;
    std::cin.get();
}

std::ofstream& manager::WriteAll(std::ofstream& fout) const
{
    fout << Manager << " ";
    abstr_emp::WriteAll(fout);
    fout << " " << inchargeof;
    return fout;
}

/**************
 * fink methods
 **************/

fink::fink(const fink& f)
    : abstr_emp(f)
{
    reportsto = f.reportsto;
}

void fink::ShowAll() const
{
    abstr_emp::ShowAll();
    std::cout << "Reportsto: " << reportsto << std::endl;
}

void fink::SetAll()
{
    abstr_emp::SetAll();
    std::cout << "Enter reportsto: ";
    std::getline(std::cin, reportsto);
}

std::ofstream& fink::WriteAll(std::ofstream& fout) const
{
    fout << Fink << " ";
    abstr_emp::WriteAll(fout);
    fout << " " << reportsto;
    return fout;
}

/******************
 * highfink methods
 ******************/

void highfink::ShowAll() const
{
    abstr_emp::ShowAll();
    std::cout << "Inchargeof: " << manager::InChargeOf() << std::endl;
    std::cout << "Reportsto: " << fink::ReportsTo() << std::endl;
}

void highfink::SetAll()
{
    abstr_emp::SetAll();
    std::cout << "Enter reportsto: ";
    std::getline(std::cin, fink::ReportsTo());
    std::cout << "Enter Inchargeof: ";
    std::cin >> manager::InChargeOf();
    std::cin.get();
}

std::ofstream& highfink::WriteAll(std::ofstream& fout) const
{
    fout << HighFink << " ";
    abstr_emp::WriteAll(fout);
    fout << " " << manager::InChargeOf() << " " << fink::ReportsTo();
    return fout;
}

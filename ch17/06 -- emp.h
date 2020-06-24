// emp.h
#ifndef EMP_H_
#define EMP_H_

#include <iostream>
#include <string>
#include <fstream>

enum classkind { Employee, Manager, Fink, HighFink };

class abstr_emp
{
private:
    std::string fname;
    std::string lname;
    std::string job;
public:
    abstr_emp();
    abstr_emp(const std::string& fn, const std::string& ln,
        const std::string& j) : fname(fn), lname(ln), job(j) {}
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual std::ofstream& WriteAll(std::ofstream& of) const;
    friend std::ostream& operator<<(std::ostream& os, const abstr_emp& e);
    virtual ~abstr_emp() = 0;
};

class employee : public abstr_emp
{
public:
    employee() {}
    employee(const std::string& fn, const std::string& ln,
        const std::string& j) : abstr_emp(fn, ln, j) {}
    virtual void ShowAll() const;
    virtual void SetAll();
    std::ofstream& WriteAll(std::ofstream& fout) const;
};

class manager : virtual public abstr_emp
{
private:
    int inchargeof;
protected:
    int InChargeOf() const { return inchargeof; }
    int& InChargeOf() { return inchargeof; }
public:
    manager() { inchargeof = 0; }
    manager(const std::string& fn, const std::string& ln,
        const std::string& j, int ico = 0)
        : abstr_emp(fn, ln, j), inchargeof(ico) {}
    manager(const abstr_emp& e, int ico);
    manager(const manager& m);
    virtual void ShowAll() const;
    virtual void SetAll();
    std::ofstream& WriteAll(std::ofstream& fout) const;
};

class fink : virtual public abstr_emp
{
private:
    std::string reportsto;
protected:
    const std::string ReportsTo() const { return reportsto; }
    std::string& ReportsTo() { return reportsto; }
public:
    fink() { reportsto = "none"; }
    fink(const std::string& fn, const std::string ln,
        const std::string& j, const std::string rpo)
        : abstr_emp(fn, ln, j), reportsto(rpo) {}
    fink(const abstr_emp& e, const std::string& rpo)
        : abstr_emp(e), reportsto(rpo) {}
    fink(const fink& f);
    virtual void ShowAll() const;
    virtual void SetAll();
    std::ofstream& WriteAll(std::ofstream& fout) const;
};

class highfink : public manager, public fink
{
public:
    highfink() {}
    highfink(const std::string& fn, const std::string& ln,
        const std::string& j, const std::string& rpo, int ico)
        : abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo) {}
    highfink(const abstr_emp& e, const std::string rpo, int ico)
        : abstr_emp(e), manager(e, ico), fink(e, rpo) {}
    highfink(const fink& f, int ico)
        : abstr_emp(f), fink(f), manager((const abstr_emp&)f, ico) {}
    highfink(const manager& m, const std::string rpo)
        : abstr_emp(m), manager(m), fink((const abstr_emp&)m, rpo) {}
    highfink(const highfink& h) : abstr_emp(h), manager(h), fink(h) {}
    virtual void ShowAll() const;
    virtual void SetAll();
    std::ofstream& WriteAll(std::ofstream& fout) const;
};

#endif

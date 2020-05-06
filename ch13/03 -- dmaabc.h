// dma.h
#ifndef DMAABC_H_
#define DMAABC_H_
#include <iostream>

class ABC
{
private:
    char* label;
    int rating;

public:
    ABC(const char* l = "null", int r = 1);
    ABC(const ABC& a);
    virtual ~ABC() = 0;
    virtual void View() const;
    ABC& operator=(const ABC& a);
};

class baseDMA : public ABC
{
public:
    baseDMA(const char* l = "null", int r = 0)
        : ABC(l, r) {}
};

class lacksDMA : public ABC
{
private:
    enum { COL_LEN = 40 };
    char color[COL_LEN];
public:
    lacksDMA(const char* c = "blank", const char* l = "null",
        int r = 0);
    lacksDMA(const char* c, const ABC& a);
    virtual void View() const;
};

class hasDMA : public ABC
{
private:
    char* style;
public:
    hasDMA(const char* s = "none", const char* l = "null",
        int r = 0);
    hasDMA(const char* s, const ABC& c);
    hasDMA(const hasDMA& hs);
    ~hasDMA();
    virtual void View() const;
    hasDMA& operator=(const hasDMA& rs);
};

#endif

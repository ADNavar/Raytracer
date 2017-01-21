#ifndef mycolor_H
#define mycolor_H

#include <iostream>
#include <iomanip>
using namespace std;


class mycolor
{
public:
    /** color methods **/
    mycolor &operator=(const mycolor &toCopy);
    mycolor operator*(double fact) const;
    mycolor operator-(const mycolor &subtrahend) const;
    mycolor operator+(const mycolor &addend) const;
    mycolor operator~();
    friend ostream &operator<<(ostream &out, const mycolor &color);
    friend istream &operator>>(istream &in, mycolor &color);
    double &operator[](int i);

    mycolor();
    mycolor(double newR, double newG, double newB);
    mycolor(double newR);
    mycolor(const mycolor &toCopy);
    ~mycolor();
    double dot(const mycolor &color2);
    mycolor scale(double fact);
    mycolor diff(const mycolor &subtrahend);
    mycolor sum(const mycolor &addend);
    double getR();
    double getG();
    double getB();
    void print();
    double get(int i);

private:
    double r;
    double g;
    double b;

};

#endif

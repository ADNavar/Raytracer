#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <iomanip>
using namespace std;


class myvector
{
private:
    double x;
    double y;
    double z;

public:

    myvector &operator=(const myvector &toCopy);
    myvector operator*(double fact) const;
    myvector operator-(const myvector &subtrahend) const;
    myvector operator+(const myvector &addend) const;
    myvector operator~();
    friend ostream &operator<<(ostream &out, const myvector &v);
    friend istream &operator>>(istream &in, myvector &v);
    double &operator[](int i);


    myvector();
    myvector(double newx, double newy, double newz);
    myvector(double newx);
    myvector(const myvector & toCopy);
    ~myvector();
    double length();
    double dot(const myvector &v2);
    myvector scale(double fact);
    myvector diff(const myvector &subtrahend);
    myvector sum(const myvector &addend);
    myvector unitvec();
    myvector cross(const myvector &v2);
    double getx();
    double gety();
    double getz();
    void print();
    double get(int i);
};

#endif

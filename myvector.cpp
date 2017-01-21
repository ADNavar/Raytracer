/** myvector class


**/
#include <iostream>
#include <math.h>
#include "myvector.h"

using namespace std;

myvector &myvector::operator=(const myvector &toCopy) {
    x = toCopy.x;
    y = toCopy.y;
    z = toCopy.z;
    return *this;
}

/** Overloaded operators **/
/** scale **/
myvector myvector::operator*(double fact) const
{
    return myvector(x*fact, y*fact, z*fact);
}

/** difference **/
myvector myvector::operator-(const myvector &subtrahend) const
{
    return myvector((x-subtrahend.x), (y-subtrahend.y), (z-subtrahend.z));
}

/** sum **/
myvector myvector::operator+(const myvector &addend) const
{
    return myvector((x+addend.x), (y+addend.y), (z+addend.z));
}

/** unitize **/
myvector myvector::operator~()
{
    myvector result;
    result = *this * (1.0/this->length());
    return(result);
}

/** "friend" function to output a myvector **/
ostream &operator<<(ostream &out, const myvector &v)
{
    out << fixed;
    //out << "(" << setprecision(2) << v.x << ", " << v.y << ", " << v.z << ")";
    out << setprecision(2) << v.x << "   " << v.y << "   " << v.z ;
    return out;
}

/** "friend" function to input a myvector **/
istream &operator>>(istream &in, myvector &v)
{
    in >> v.x >> v.y >> v.z;
    return in;
}

/** myvector field access **/
double &myvector::operator[](int i) {
    if(i == 0) return x;
    else if(i == 1) return y;
    else return z;
}


myvector::myvector()
{
    x = 0.0;
    y = 0.0;
    z = 0.0;
}

myvector::myvector(double newx, double newy, double newz)
{
    x = newx;
    y = newy;
    z = newz;
}

myvector::myvector(double newx)
{
    x = newx;
    y = 0;
    z = 0;
}

myvector::myvector(const myvector & toCopy)
{
    x = toCopy.x;
    y = toCopy.y;
    z = toCopy.z;
}

myvector::~myvector()
{
}

double myvector::length()
{
    return sqrt(x*x + y*y + z*z);
}

double myvector::dot(const myvector &v2)
{
    return (x*v2.x + y*v2.y + z*v2.z);
}

myvector myvector::scale(double fact)
{
	return myvector(x*fact, y*fact, z*fact);
}

myvector myvector::diff(const myvector &subtrahend)
{
	return myvector(x - subtrahend.x, y - subtrahend.y, z - subtrahend.z);
}

myvector myvector::sum(const myvector & addend)
{
	return myvector(x + addend.x, y + addend.y, z + addend.z);
}

myvector myvector::unitvec()
{
	double len = length();
	return myvector(x/len, y/len, z/len);
}

myvector myvector::cross(const myvector &v2)
{
   myvector work;
   work.x = y * v2.z - z * v2.y;
   work.y = z * v2.x - x * v2.z;
   work.z = x * v2.y - y * v2.x;
   return work;
}

double myvector:: getx() {
        return(x);
}

double myvector:: gety() {
        return(y);
}

double myvector:: getz() {
        return(z);
}

void myvector::print()
{
    cerr << "(" << x << ", " << y << ", " << z << ")\n";
}


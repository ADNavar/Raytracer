/** mycolor class


**/
#include <iostream>
#include <math.h>
#include "mycolor.h"

using namespace std;

mycolor &mycolor::operator=(const mycolor &toCopy) {
    r = toCopy.r;
    g = toCopy.g;
    b = toCopy.b;
    return *this;
}

/** Overloaded operators **/
/** scale **/
mycolor mycolor::operator*(double fact) const
{
    return mycolor(r*fact, g*fact, b*fact);
}

/** difference **/
mycolor mycolor::operator-(const mycolor &subtrahend) const
{
    return mycolor((r-subtrahend.r), (g-subtrahend.g), (b-subtrahend.b));
}

/** sum **/
mycolor mycolor::operator+(const mycolor &addend) const
{
    return mycolor((r+addend.r), (g+addend.g), (b+addend.b));
}

/** "friend" function to output a mycolor **/
ostream &operator<<(ostream &out, const mycolor &color)
{
    //out << "(" << setprecision(0) << color.r << ", " << color.g << ", " << color.b << ")";
    out << setprecision(0) << color.r << "   " << color.g << " " << color.b;
    return out;
}

/** "friend" function to input a mycolor **/
istream &operator>>(istream &in, mycolor &color)
{
    in >> color.r >> color.g >> color.b;
    return in;
}

/** mycolor field access **/
double &mycolor::operator[](int i) {
    if(i == 0) return r;
    else if(i == 1) return g;
    else return b;
}


mycolor::mycolor()
{
    r = 0.0;
    g = 0.0;
    b = 0.0;
}

mycolor::mycolor(double newR, double newG, double newB)
{
    r = newR;
    g = newG;
    b = newB;
}

mycolor::mycolor(double newR)
{
    r = newR;
    g = 0.0;
    b = 0.0;
}

mycolor::mycolor(const mycolor & toCopy)
{
    r = toCopy.r;
    g = toCopy.g;
    b = toCopy.b;
}

mycolor::~mycolor()
{

}

double mycolor::dot(const mycolor &color2)
{
    return (r*color2.r + g*color2.g + r*color2.b);
}

mycolor mycolor::scale(double fact)
{
	return mycolor(r*fact, g*fact, b*fact);
}

mycolor mycolor::diff(const mycolor &subtrahend)
{
	return mycolor(r - subtrahend.r, g - subtrahend.g, b - subtrahend.b);
}

mycolor mycolor::sum(const mycolor & addend)
{
	return mycolor(r + addend.r, g + addend.g, b + addend.b);
}

double mycolor:: getR() {
        return(r);
}

double mycolor:: getG() {
        return(g);
}

double mycolor:: getB() {
        return(b);
}

void mycolor::print()
{
    cerr << "(" << r << ", " << g << ", " << b << ")\n";
}


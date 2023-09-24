#ifndef Cylinder_H
#define Cylinder_H

#include <iostream>
using namespace std;

class Cylinder
{

private:
    double radius;
    double height;
    double volume;

public:
    Cylinder();
    Cylinder(double radius, double height);
    void getRadius();
    void setRadius();
    void getHeight();
    void setHeight();
    double getVolume();
    void printVolume();
};

#endif

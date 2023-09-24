#include"./cylinder.h"


Cylinder::Cylinder()
    {
    }

   Cylinder:: Cylinder(double radius, double height)
    {
        this->radius = radius;
        this->height = height;
    }

    void Cylinder::getRadius()
    {
        cout << radius;
    }

    void Cylinder::setRadius()
    {
        cout << "ENTER RADIUS = " << endl;
        cin >> this->radius;
    }
    void Cylinder::getHeight()
    {
        cout << height;
    }

    void Cylinder::setHeight()
    {
        cout << "ENTER HEIGHT = ";
        cin >> this->height;
    }

    double Cylinder::getVolume()
    {
        volume = 3.14 * radius * radius * height;
        return volume;
    }

    void Cylinder::printVolume()
    {
        cout << "VOLUME = " << getVolume() << endl;
    }
#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <ostream>
#include <string>

struct Vehicle final
{
    std::string make;
    std::string model;
    int year;
    std::string color;
    double mileage;
    double price;

    friend std::ostream &operator<<(std::ostream &os, const Vehicle &v)
    {
        os << "Make: " << v.make << ", Model: " << v.model << ", Year: " << v.year << ", Color: " << v.color
           << ", Mileage: " << v.mileage << ", Price: " << v.price;

        return os;
    }
};

#endif // VEHICLE_HPP
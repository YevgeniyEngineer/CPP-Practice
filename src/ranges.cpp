#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "read_csv.hpp"
#include "vehicle.hpp"

int main()
{
    const std::string filename = "../data/vehicles_dataset.csv";
    const std::vector<Vehicle> vehicles = readCSV(filename);

    for (const auto &vehicle : vehicles)
    {
        std::cout << vehicle << std::endl;
    }

    return 0;
}
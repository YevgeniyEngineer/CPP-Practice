#include "read_csv.hpp"

std::vector<Vehicle> readCSV(const std::string &filename)
{
    std::vector<Vehicle> vehicles{};
    std::ifstream file{filename};

    std::string line;
    // Skip the header line
    std::getline(file, line);

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string token;
        Vehicle vehicle;
        int column = 0;

        while (std::getline(ss, token, ','))
        {
            switch (column)
            {
            case 0:
                vehicle.make = token;
                break;
            case 1:
                vehicle.model = token;
                break;
            case 2:
                vehicle.year = std::stoi(token);
                break;
            case 3:
                vehicle.color = token;
                break;
            case 4:
                vehicle.mileage = std::stod(token);
                break;
            case 5:
                vehicle.price = std::stod(token);
                break;
            }
            ++column;
        }
        vehicles.push_back(vehicle);
    }

    return vehicles;
}
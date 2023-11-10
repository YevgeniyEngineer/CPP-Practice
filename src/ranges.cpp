#include <filesystem>
#include <fstream>
#include <iostream>
#include <iterator>
#include <ostream>
#include <ranges>
#include <sstream>
#include <string>
#include <vector>

#include "read_csv.hpp"
#include "vehicle.hpp"

std::ostream &operator<<(std::ostream &os, const std::vector<Vehicle> &vehicles)
{
    for (const auto &vehicle : vehicles)
    {
        os << vehicle << '\n';
    }

    return os;
}

// Filter vehicles by make
void filterByMake(const std::vector<Vehicle> &vehicles, const std::string &make)
{
    std::cout << "Vehicles of make " << make << ":\n";

    auto filtered =
        vehicles | std::views::filter([&make](const Vehicle &vehicle) noexcept { return (vehicle.make == make); });

    std::cout << std::vector<Vehicle>(std::make_move_iterator(filtered.begin()),
                                      std::make_move_iterator(filtered.end()))
              << std::endl;
}

int main()
{
    const std::string filename = "../data/vehicles_dataset.csv";
    const std::vector<Vehicle> vehicles = readCSV(filename);

    filterByMake(vehicles, "Toyota");

    return 0;
}
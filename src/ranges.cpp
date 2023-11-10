#include <algorithm>
#include <bits/ranges_algo.h>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <ostream>
#include <ranges>
#include <sstream>
#include <string>
#include <unordered_map>
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

    auto filtered = vehicles | std::views::filter(
                                   [&make](const Vehicle &vehicle) noexcept -> bool { return (vehicle.make == make); });

    std::cout << std::vector<Vehicle>(filtered.begin(), filtered.end()) << std::endl;
}

// Filter vehicles by make and year (two filters)
void filterByMakeOlderThanYear(const std::vector<Vehicle> &vehicles, const std::string &make, const int year)
{
    std::cout << "Vehicles of make " << make << " of years older than " << year << ":\n";

    auto filtered =
        vehicles |
        std::views::filter([&make](const Vehicle &vehicle) noexcept -> bool { return (vehicle.make == make); }) |
        std::views::filter([year](const Vehicle &vehicle) noexcept -> bool { return (vehicle.year < year); });

    std::cout << std::vector<Vehicle>(filtered.begin(), filtered.end()) << std::endl;
}

// Group by color and count
void groupByColorAndCount(std::vector<Vehicle> vehicles)
{
    std::cout << "Grouping by color and counting each group:\n";

    // Sort by color
    std::ranges::sort(vehicles,
                      [](const Vehicle &v1, const Vehicle &v2) noexcept -> bool { return (v1.color < v2.color); });

    std::map<std::string, int> color_count;
    for (const auto &vehicle : vehicles)
    {
        ++color_count[vehicle.color];
    }

    for (const auto &[color, count] : color_count)
    {
        std::cout << "Color: " << color << ", Count: " << count << '\n';
    }
}

void findCheapestVehicle(const std::vector<Vehicle> &vehicles)
{
    const auto min_element = std::ranges::min_element(
        vehicles, [](const Vehicle &v1, const Vehicle &v2) noexcept -> bool { return (v1.price < v2.price); });

    std::cout << "\nCheapest vehicle: \n" << *min_element << std::endl;
}

void computeAverageMileage(const std::vector<Vehicle> &vehicles)
{
}

void concatenateTwoRanges(const std::vector<Vehicle> &vehicles)
{
}

int main()
{
    const std::string filename = "../data/vehicles_dataset.csv";
    const std::vector<Vehicle> vehicles = readCSV(filename);

    filterByMake(vehicles, "Toyota");

    filterByMakeOlderThanYear(vehicles, "Toyota", 2004);

    groupByColorAndCount(vehicles);

    findCheapestVehicle(vehicles);

    return 0;
}
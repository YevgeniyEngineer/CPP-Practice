#ifndef READ_CSV_HPP
#define READ_CSV_HPP

#include "vehicle.hpp"

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

std::vector<Vehicle> readCSV(const std::string &filename);

#endif // READ_CSV_HPP
#include "test_function.h"

#include <fstream>
#include <iosfwd>
#include <sstream>
#include <string>
#include <vector>


std::vector<std::vector<double>> ReadMatrixFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    std::string line;
    std::vector<std::vector<double>> data;

    // Read the file line by line
    while (getline(file, line))
    {
        std::stringstream lineStream(line);
        std::vector<double> row;
        double value;

        // Parse each line into a row of values
        while (lineStream >> value)
        {
            row.push_back(value);
        }
        data.push_back(row);
    }

    std::vector<std::vector<double>> data_transpose(
        data.front().size(), std::vector<double>(data.size()));
    for (std::size_t i = 0; i != data.size(); ++i)
        for (std::size_t j = 0; j != data.front().size(); ++j)
            data_transpose[j][i] = data[i][j];
    return data_transpose;
}
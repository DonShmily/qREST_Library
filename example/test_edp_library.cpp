#include "test_function.h"

#include "../include/edp_library.h"

#include <cstddef>
#include <fstream>
#include <iosfwd>
#include <iostream>
#include <string>
#include <vector>


using namespace std;

void test_edp_library(const string &file_name)
{
    // 读取文件中的数据
    std::vector<double> floor, measurement;
    std::ifstream ifs("../resource/building/floor.txt");
    double temp;
    while (ifs >> temp)
    {
        floor.push_back(temp);
    }
    ifs.close();
    ifs.open("../resource/building/measurement.txt");
    while (ifs >> temp)
    {
        measurement.push_back(temp);
    }
    ifs.close();

    // 创建计算对象
    auto acceleration = ReadMatrixFromFile(file_name);

    // 计算对象赋值
    Building *building_c = new Building;
    *building_c = {
        floor.data(), floor.size(), measurement.data(), measurement.size()};
    size_t col_number = acceleration.size(),
           row_number = acceleration.front().size();
    double **acc_c = new double *[col_number];
    for (std::size_t i = 0; i < col_number; ++i)
    {
        acc_c[i] = new double[row_number];
        std::copy(
            acceleration.at(i).begin(), acceleration.at(i).end(), acc_c[i]);
    }

    // 计算层间位移角
    auto idr_result =
        ModifiedFilteringIntegral(acc_c, row_number, 50, building_c);

    std::ofstream ofs1("../resource/acceleration_data/story_drift.txt");
    for (std::size_t i = 0; i < idr_result->time_step_count; ++i)
    {
        for (std::size_t j = 0; j < idr_result->story_count; ++j)
        {
            ofs1 << idr_result->idr[j][i] << " ";
        }
        ofs1 << endl;
    }
    ofs1.close();

    // 计算最大层间位移角
    auto max_idr = GetMaxIdr(idr_result, 50);

    // 输出结果
    std::ofstream ofs2("../resource/acceleration_data/max_story_drift.txt");
    for (std::size_t j = 0; j < max_idr->story_count; ++j)
    {
        ofs2 << max_idr->max_idr[j] << "\n";
    }
    ofs2.close();

    // 释放内存
    FreeMaxIdr(max_idr);
    FreeIdr(idr_result);
}
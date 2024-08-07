#include <fstream>
#include <string>
#include <vector>


#include "../include/gmp_library.h"
#include "test_function.h"

using namespace std;

void test_gmp_library(const string &file_name)
{
    // 创建计算对象
    std::vector<std::vector<double>> test_acceleration =
        ReadMatrixFromFile(file_name);
    auto &acc = test_acceleration[0];
    auto sa_result = GetResponseSpectrum(acc.data(), acc.size(), 50, 0.05);
    auto psa_result = GetResponseSpectrum(acc.data(), acc.size(), 50, 0.05);

    // 输出结果
    std::ofstream ofs("../resource/acceleration_data/response_spectrum.txt");
    for (std::size_t i = 0; i < sa_result->result_size; ++i)
    {
        ofs << sa_result->Sa[i] << " " << sa_result->Sv[i] << " "
            << sa_result->Sd[i] << " " << psa_result->Sa[i] << " "
            << psa_result->Sv[i] << " " << psa_result->Sd[i] << "\n";
    }
    ofs.close();

    // 释放内存
    FreeResponseSpectrum(sa_result);
    FreeResponseSpectrum(psa_result);
}
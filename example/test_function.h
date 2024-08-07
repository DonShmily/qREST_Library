#ifndef TEST_TEST_FUNCTION_H_
#define TEST_TEST_FUNCTION_H_

#include <string>
#include <vector>


// 测试EDP计算模块
void test_edp_library(const std::string &file_name);

// 测试地震动参数计算模块
void test_gmp_library(const std::string &file_name);

// 读取文件中的矩阵数据
std::vector<std::vector<double>>
ReadMatrixFromFile(const std::string &filename);

#endif // TEST_TEST_FUNCTION_H_

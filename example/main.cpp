// g++ example/*.cpp -Iinclude -Lbin -ledp_library -lgmp_library -o bin/main.exe

#include "test_function.h"

using namespace std;

int main()
{
    // 测试EDP计算模块
    test_edp_library("../resource/acceleration_data/accNS.txt");

    // 测试地震动参数库计算
    test_gmp_library("../resource/acceleration_data/accNS.txt");

    return 0;
}
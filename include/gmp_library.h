#ifndef GMP_LIBRARY_H_
#define GMP_LIBRARY_H_

#ifdef __cplusplus
extern "C"
{
#endif

    // 反应谱计算结果
    typedef struct
    {
        // 反应谱计算结果
        double *Sa;
        double *Sv;
        double *Sd;

        // 以下两个参数是希望能从设置中读取，作为参数提供给计算反应谱的函数
        // 不过目前还没有设置这个功能，故暂时在程序内使用了比较通用的值

        // 计算结果长度
        int result_size;
        // 反应谱横轴间隔
        double dt;
    } ResponseSpectrum;

    // 计算反应谱
    // @param acceleration: 加速度数据
    // @param size: 加速度数据长度
    // @param frequency: 采样频率
    // @param damping_ratio: 阻尼比
    // @return ResponseSpectrum: 反应谱计算结果
    __declspec(dllexport) ResponseSpectrum *
    GetResponseSpectrum(const double *acceleration,
                        int size,
                        double frequency,
                        double damping_ratio);

    // 计算拟反应谱
    // @param acceleration: 加速度数据
    // @param size: 加速度数据长度
    // @param frequency: 采样频率
    // @param damping_ratio: 阻尼比
    // @return ResponseSpectrum: 反应谱计算结果
    __declspec(dllexport) ResponseSpectrum *
    GetPseudoResponseSpectrum(const double *acceleration,
                              int size,
                              double frequency,
                              double damping_ratio);

    // 释放反应谱结果内存
    // @param memory: 反应谱结果
    __declspec(dllexport) void FreeResponseSpectrum(ResponseSpectrum *memory);

    // 计算Fourier幅值谱
    // @param acceleration: 加速度数据
    // @param size: 加速度数据长度
    // @return double*: Fourier幅值谱
    __declspec(dllexport) double *FourierSpectrum(const double *acceleration,
                                                  int size);

    // 释放double数组内存
    // @param memory: double数组
    __declspec(dllexport) void FreeArray(double *memory);

#ifdef __cplusplus
}
#endif
#endif // CPP_M_FUNC_H/
#ifndef ALGORITHM_KAHAN_H
#define ALGORITHM_KAHAN_H

#include "common/common.h"

namespace hl
{
namespace algorithm
{

template <typename T>
T KahanSum(const std::vector<T>& v)
{
    static_assert((std::is_same<T, double>::value || std::is_same<T, float>::value),
                  "should use with float or double");
    return T();
}

template <>
float KahanSum(const std::vector<float>& v)
{
    float sum = 0.0f;
    float small = 0.0f;
    for (float f : v)
    {
        float delta = f - small;
        float tmpSum = sum + delta;
        small = tmpSum - sum - delta;
        sum = tmpSum;
    }
    return sum;
}

template <>
double KahanSum(const std::vector<double>& v)
{
    double sum = 0.0;
    double small = 0.0;
    for (double f : v)
    {
        double delta = f - small;
        double tmpSum = sum + delta;
        small = tmpSum - sum - delta;
        sum = tmpSum;
    }
    return sum;
}

} // namespace algorithm
} // namespace hl

#endif

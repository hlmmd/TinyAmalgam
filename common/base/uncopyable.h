#ifndef COMMON_BASE_UNCOPYABLE_H
#define COMMON_BASE_UNCOPYABLE_H

#include "common/common.h"
namespace hl
{
namespace common
{

class Uncopyable
{
public:
    Uncopyable() {}
    virtual ~Uncopyable() {}

private:
    Uncopyable(const Uncopyable&) = delete;
    Uncopyable& operator=(const Uncopyable&) = delete;
};
} // namespace common
} // namespace hl

#endif // COMMON_BASE_UNCOPYABLE_H

#include "timestamp.h"
#include <time.h>

using namespace hl::common;

const Timestamp &Timestamp::update()
{
    struct timespec temp;
    clock_gettime(CLOCK_MONOTONIC, &temp);
    ns_ = static_cast<uint64_t>(temp.tv_sec) * kNineZero + temp.tv_nsec;
    return *this;
}

int64_t Timestamp::nsTillNow() const
{
    struct timespec temp;
    clock_gettime(CLOCK_MONOTONIC, &temp);
    int64_t tempns = static_cast<uint64_t>(temp.tv_sec) * kNineZero + temp.tv_nsec;
    return tempns - ns_;
}

int64_t Timestamp::nsFromEpoch()
{
    struct timespec temp;
    clock_gettime(CLOCK_REALTIME, &temp);
    return static_cast<uint64_t>(temp.tv_sec) * kNineZero + temp.tv_nsec;
}

std::string Timestamp::nowstr(const char *format)
{
    time_t x = time(0);
    struct tm t;
    localtime_r(&x, &t);

    char buf[32]; // 32 is big enough in most cases
    size_t r = strftime(buf, 32, format, &t);
    return std::string(buf, r);
}
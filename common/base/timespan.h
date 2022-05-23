#ifndef HL_INCLUDE_BASE_TIMESPAN_H_
#define HL_INCLUDE_BASE_TIMESPAN_H_
#include "common/common.h"
namespace hl
{
namespace common
{

class Timespan
{

public:
    Timespan() : ns_(0){};
    ~Timespan() = default;
    explicit Timespan(int64_t ts) : ns_(ts){};

    static const int64_t kNanosecond = 1;
    static const int64_t kMicrosecond = 1000;
    static const int64_t kMillisecond = kMicrosecond * 1000;
    static const int64_t kSecond = kMillisecond * 1000;
    static const int64_t kMinute = kSecond * 60;
    static const int64_t kHour = kMinute * 60;
    static const int64_t kDay = kHour * 24;

    bool operator<(const Timespan& rhs) const { return ns_ < rhs.ns_; };
    bool operator<=(const Timespan& rhs) const { return ns_ <= rhs.ns_; };
    bool operator==(const Timespan& rhs) const { return ns_ == rhs.ns_; };
    bool operator>(const Timespan& rhs) const { return ns_ > rhs.ns_; };
    bool operator>=(const Timespan& rhs) const { return ns_ >= rhs.ns_; };
    bool operator!=(const Timespan& rhs) const { return ns_ != rhs.ns_; };

    Timespan operator-(const Timespan& rhs) { return Timespan(ns_ - rhs.ns_); };
    Timespan operator+(const Timespan& rhs) { return Timespan(ns_ + rhs.ns_); };
    Timespan& operator-=(const Timespan& rhs)
    {
        ns_ -= rhs.ns_;
        return *this;
    };
    Timespan& operator+=(const Timespan& rhs)
    {
        ns_ += rhs.ns_;
        return *this;
    };

    int64_t ns() const { return ns_; }

private:
    int64_t ns_;
};

} // namespace common

} // namespace hl

#endif
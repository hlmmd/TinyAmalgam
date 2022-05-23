#ifndef HL_INCLUDE_BASE_TIMESTAMP_H_
#define HL_INCLUDE_BASE_TIMESTAMP_H_

#include "timespan.h"

namespace hl
{
namespace common
{

// use clock_gettime CLOCK_MONOTONIC
// precision : ns
class Timestamp
{
public:
    Timestamp() : ns_(0){}
    ~Timestamp() = default;

    // update timestamp to now
    const Timestamp& update();

    // get the nsecond  passed from last Timestamp
    int64_t nsTillNow() const;

    // get the usecond  passed from last Timestamp
    int64_t usTillNow() const { return nsTillNow() / kThreeZero; };

    // get the msecond  passed from last Timestamp
    int64_t msTillNow() const { return nsTillNow() / kSixZero; };

    // get the second passed from last Timestamp
    int64_t secondTillNow() const { return nsTillNow() / kNineZero; };

    // calculate the timestamp
    const Timestamp& addTimeInterval(const int second, const int nsecond)
    {
        ns_ += static_cast<int64_t>(second) * kNineZero + nsecond;
        return *this;
    }

    // add by Timespan
    const Timestamp& addTimeInterval(const Timespan& ts)
    {
        ns_ += ts.ns();
        return *this;
    }

    bool operator<(const Timestamp& rhs) const { return ns_ < rhs.ns_; };
    bool operator<=(const Timestamp& rhs) const { return ns_ <= rhs.ns_; };
    bool operator==(const Timestamp& rhs) const { return ns_ == rhs.ns_; };
    bool operator>(const Timestamp& rhs) const { return ns_ > rhs.ns_; };
    bool operator>=(const Timestamp& rhs) const { return ns_ >= rhs.ns_; };
    bool operator!=(const Timestamp& rhs) const { return ns_ != rhs.ns_; };

    int64_t operator-(const Timestamp& rhs) { return ns_ - rhs.ns_; };

    // ns from realtime
    static int64_t nsFromEpoch();

    // return temp time string
    static std::string nowstr(const char* format = "%Y-%m-%d %H:%M:%S");

    static const int64_t kThreeZero = 1000;
    static const int64_t kSixZero = 1000 * 1000;
    static const int64_t kNineZero = 1000 * 1000 * 1000;

    int64_t ns() const { return ns_; }

private:
    int64_t ns_;
};

} // namespace common
} // namespace hl

#endif
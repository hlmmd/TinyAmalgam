#ifndef COMMON_BASE_COUNT_DOWN_LATCH_H
#define COMMON_BASE_COUNT_DOWN_LATCH_H

#include "common/common.h"
#include "uncopyable.h"
namespace hl
{
namespace common
{

class CountDownLatch : private Uncopyable
{
public:
    explicit CountDownLatch(int count) : count_(count)
    {
    }
    void Wait()
    {
        std::unique_lock<std::mutex> _(mutex_);
        while (count_ > 0)
            cv_.wait(_);
    }
    void CountDown()
    {
        std::unique_lock<std::mutex> _(mutex_);
        count_--;
        if (count_ == 0)
            cv_.notify_all();
    }

private:
    int count_;
    std::mutex mutex_;
    std::condition_variable cv_;
};

} // namespace common
} // namespace hl

#endif // COMMON_BASE_COUNT_DOWN_LATCH_H

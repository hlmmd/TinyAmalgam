#ifndef COMMON_BASE_THREAD_POOL_H
#define COMMON_BASE_THREAD_POOL_H

#include "common/common.h"
#include "uncopyable.h"
namespace hl
{
namespace common
{

class ThreadPool : private Uncopyable
{
public:
    using TaskPtr = std::function<void()>;
    ThreadPool(int threadNum, int poolSize = 1024);
    ~ThreadPool();
    void Submit(TaskPtr pTask);

private:
    void Stop()
    {
        stop_ = true;
        emptyCv_.notify_all();
        fullCv_.notify_all();
    }
    const int poolSize_;
    bool stop_;
    std::mutex mutex_;
    std::condition_variable fullCv_;
    std::condition_variable emptyCv_;
    std::queue<TaskPtr> taskQueue_;
    std::vector<ThreadPtr> pThreads_;
};

} // namespace common
} // namespace hl

#endif // COMMON_BASE_THREAD_POOL_H

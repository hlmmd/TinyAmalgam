#include "thread_pool.h"
namespace hl
{
namespace common
{

ThreadPool::ThreadPool(int threadNum, int poolSize) : poolSize_(poolSize),
                                                      stop_(false)
{
    for (int i = 0; i < threadNum; i++)
    {
        ThreadPtr pthread = std::make_shared<std::thread>(
            [this, i]()
            {
                while (!stop_)
                {
                    TaskPtr pTask = nullptr;
                    {
                        std::unique_lock<std::mutex> _(mutex_);
                        if (taskQueue_.empty())
                        {
                            emptyCv_.wait(_);
                        }
                        if (stop_)
                            break;
                        pTask = taskQueue_.front();
                        taskQueue_.pop();
                        fullCv_.notify_one();
                    }
                    if (pTask != nullptr)
                        pTask();
                }
            });
        pThreads_.push_back(std::move(pthread));
    }
}
ThreadPool::~ThreadPool()
{
    Stop();
    for (int i = 0; i < pThreads_.size(); i++)
    {
        pThreads_[i]->join();
    }
}
void ThreadPool::Submit(TaskPtr pTask)
{
    if (pTask == nullptr)
        return;
    std::unique_lock<std::mutex> _(mutex_);
    if (taskQueue_.size() >= poolSize_)
    {
        fullCv_.wait(_);
    }
    if (stop_)
        return;
    taskQueue_.push(pTask);
    emptyCv_.notify_one();
}

} // namespace common
} // namespace hl

#ifndef COMMON_SEQUENCE_PROCESSOR_H
#define COMMON_SEQUENCE_PROCESSOR_H

namespace hl
{
namespace common
{

// 嬴彻科技的一道面试题
template <typename T>
class SequenceProcessor
{
public:
    using Task = std::function<void(T&)>;
    void Add(Task task)
    {
        tasks_.push_back(task);
    }
    T Process(T& t)
    {
        for (auto& func : tasks_)
            func(t);
        return t;
    }

    std::vector<T> ProcessBatch(std::vector<T>& ts)
    {
        std::vector<T> ret;
        for (auto& t : ts)
            ret.push_back(Process(t));
        return ret;
    }

    T Process(T t)
    {
        for (auto& func : tasks_)
            func(t);
        return t;
    }

private:
    std::vector<Task> tasks_;
};

} // namespace common
} // namespace hl

#endif //COMMON_SEQUENCE_PROCESSOR_H

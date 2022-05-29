#ifndef COMMON_BASE_OBJECT_POOL_H
#define COMMON_BASE_OBJECT_POOL_H

#include "common/common.h"
#include "uncopyable.h"
namespace hl
{
namespace common
{

template <typename T, typename... Args>
class ObjectPool : private Uncopyable
{
public:
    using ObjectPtr = std::shared_ptr<T>;
    ObjectPool(int size, Args&&... args)
    {
        for (int i = 0; i < size; i++)
        {
            freeList_.push_front(new T(std::forward<Args>(args)...));
        }
    }
    virtual ~ObjectPool()
    {
        for (auto it = freeList_.begin(); it != freeList_.end(); ++it)
        {
            delete (*it);
        }
    }
    int GetOne(ObjectPtr& pObject)
    {
        ObjectPtr pNewObject;
        {
            std::unique_lock<std::mutex> _(mutex_);
            busyCv_.wait(_, [this]()
                         { return !freeList_.empty(); });
            auto freeNode = freeList_.begin();
            pNewObject.reset(*freeNode, [this](T* p)
                             {
							std::unique_lock<std::mutex> _(mutex_);
							freeList_.push_front(p); });
            freeList_.pop_front();
        }
        pObject = pNewObject;
    }

private:
    std::list<T*> freeList_;
    std::mutex mutex_;
    std::condition_variable busyCv_;
};

} // namespace common
} // namespace hl

#endif // COMMON_BASE_OBJECT_POOL_H

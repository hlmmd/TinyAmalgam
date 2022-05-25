#ifndef COMMON_BASE_SHARED_PTR_H
#define COMMON_BASE_SHARED_PTR_H

#include "common/common.h"
namespace hl
{
namespace common
{

template <typename T>
class SharedPtr
{
public:
    SharedPtr(T* p = nullptr) : pData_(p),
                                pCount_(new unsigned int(1)),
                                pMutex_(new std::mutex())
    {
    }

    ~SharedPtr()
    {
        Decrement();
    }

    SharedPtr(const SharedPtr<T>& other) : pData_(other.pData_),
                                           pCount_(other.pCount_),
                                           pMutex_(other.pMutex_)
    {
        Increment();
    }
    SharedPtr(const SharedPtr<T>&& other) : pData_(other.pData_),
                                            pCount_(other.pCount_),
                                            pMutex_(other.pMutex_)
    {
        other.pData_ = nullptr;
        other.pCount_ = nullptr;
        other.pMutex_ = nullptr;
    }
    SharedPtr<T>& operator=(const SharedPtr<T>& other)
    {
        if (other.pData_ == this->pData_)
            return *this;
        // release 当前数据
        Decrement();
        pData_ = other.pData_;
        pMutex_ = other.pMutex_;
        pCount_ = other.pCount_;
        Increment();
        return *this;
    }

    SharedPtr<T>& operator=(const SharedPtr<T>&& other)
    {
        if (other.pData_ == this->pData_)
            return *this;
        // release 当前数据
        Decrement();
        pData_ = other.pData_;
        pMutex_ = other.pMutex_;
        pCount_ = other.pCount_;
        other.pData_ = nullptr;
        other.pCount_ = nullptr;
        other.pMutex_ = nullptr;
        return *this;
    }

    const int UseCount() const { return *pCount_; }

    T& operator*() { return *pData_; }
    T* operator->() { return pData_; }
    T* Get() { return pData_; }

private:
    void Increment()
    {
        std::lock_guard<std::mutex> _(*pMutex_);
        ++(*pCount_);
    }
    void Decrement()
    {
        pMutex_->lock();
        --(*pCount_);
        if (*pCount_ == 0)
        {
            delete pData_;
            delete pCount_;
            pMutex_->unlock();
            delete pMutex_;
            return;
        }
        pMutex_->unlock();
    }

    void Release()
    {
    }
    T* pData_;
    unsigned int* pCount_;
    std::mutex* pMutex_;
};

} // namespace common
} // namespace hl

#endif // COMMON_BASE_SHARED_PTR_H

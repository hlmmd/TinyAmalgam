
#ifndef COMMON_STRUCTURE_RANDOMIZED_SET_H
#define COMMON_STRUCTURE_RANDOMIZED_SET_H

#include "common/random.h"
#include <unordered_map>
#include <vector>
namespace hl
{
namespace common
{

// 线程不安全
// vector删除的时候，把想删除的元素和最后一个元素交换，再pop_back()，可以达到O(1)复杂度
template <typename Value>
class RandomizedSet
{
public:
    /** Initialize your data structure here. */
    RandomizedSet() : rand_(0xabcddcba)
    {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool Insert(const Value& val)
    {
        if (map_.count(val))
            return false;

        map_[val] = values_.size();
        values_.push_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool Remove(const Value& val)
    {

        if (!map_.count(val))
            return false;

        size_t index = map_[val];
        std::swap(values_[index], values_.back());
        map_[values_[index]] = index;
        values_.pop_back();
        map_.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int GetRandomValue(Value& val)
    {
        if (values_.size() == 0)
            return -1;
        val = values_[static_cast<size_t>(rand_.Next()) % values_.size()];
        return 0;
    }

protected:
    std::unordered_map<Value, size_t> map_;
    std::vector<Value> values_;
    Random rand_;
};

} // namespace common
} // namespace hl
#endif
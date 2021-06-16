/*================================================================
*   Copyright (C) 2021 hlmmd. All rights reserved.
*
*   FileName    : skiplist.h
*   Autor       ：hlmmd
*   Date        : 2021/06/08
*   Description :
*
================================================================*/

#ifndef COMMON_STRUCTURE_SKIPLIST_H
#define COMMON_STRUCTURE_SKIPLIST_H

#include "common/random.h"
#include <algorithm>

namespace hl
{
namespace common
{

template <typename Key, typename Value>
class SkipList
{
public:
    SkipList() : rand_(0xdeadbeef)
    {
        head_ = new SkipNode();
        head_->next = new SkipNode*[kMaxLevel];
        for (int i = 0; i < kMaxLevel; i++)
            head_->next[i] = nullptr;

        level_ = 1;
    }

    ~SkipList()
    {
        SkipNode* p = head_;
        while (p != nullptr)
        {
            SkipNode* q = p->next[0];
            delete p;
            p = q;
        }
    }

    bool Find(const Key& key)
    {
        SkipNode* p = head_;
        for (int l = MaxLevel() - 1; l >= 0; l--)
        {
            while (p->next[l] && p->next[l]->key < key)
            {
                p = p->next[l];
            }
            if (p->next[l] && p->next[l]->key == key)
                return true;
        }
        return false;
    }
    int Insert(const Key& key, const Key& value)
    {
        SkipNode* prev[kMaxLevel];
        GetLessOrEqualPrev(key, prev);

        if (prev[0] != head_ && prev[0]->key == key)
        {
            prev[0]->value = value;
            return 0;
        }

        int level = GetLevel();
        if (level > MaxLevel())
        {
            for (int i = MaxLevel(); i < level; i++)
                prev[i] = head_;
            level_ = level;
        }

        SkipNode* newNode = new SkipNode(key, value, level);

        for (int i = 0; i < level; i++)
        {
            newNode->next[i] = prev[i]->next[i];
            prev[i]->next[i] = newNode;
        }
        return 0;
    }

    // void debug()
    // {
    //     for (int l = MaxLevel() - 1; l >= 0; l--)
    //     {
    //         SkipNode* p = head_;
    //         while (p->next[l])
    //         {
    //             p = p->next[l];
    //             cout << p->key << " ";
    //         }
    //         cout << endl;
    //     }
    // }

    int Erase(const Key& key)
    {
        SkipNode* prev[kMaxLevel];
        SkipNode* p = head_;
        for (int l = MaxLevel() - 1; l >= 0; l--)
        {
            while (p->next[l] && p->next[l]->key < key)
            {
                p = p->next[l];
            }
            prev[l] = p;
        }

        if (prev[0] != head_ && prev[0]->next[0]->key != key)
        {
            return -1;
        }
        SkipNode* q = prev[0]->next[0];

        for (int l = MaxLevel() - 1; l >= 0; l--)
        {
            if (prev[l]->next[l] && prev[l]->next[l]->key == key)
            {
                prev[l]->next[l] = prev[l]->next[l]->next[l];
            }
            if (head_->next[l] == nullptr)
                level_--;
        }
        delete q;
        return 0;
    }
    int Get(const Key& key, Value& value)
    {
        SkipNode* p = head_;
        for (int l = MaxLevel() - 1; l >= 0; l--)
        {
            while (p->next[l] && p->next[l]->key < key)
            {
                p = p->next[l];
            }
            if (p->next[l] && p->next[l]->key == key)
            {
                value = p->next[l]->value;
                return 0;
            }
        }
        return -1;
    }

    const Value& At(const Key& key)
    {
        SkipNode* p = head_;
        for (int l = MaxLevel() - 1; l >= 0; l--)
        {
            while (p->next[l] && p->next[l]->key < key)
            {
                p = p->next[l];
            }
            if (p->next[l] && p->next[l]->key == key)
            {
                return p->next[l]->value;
            }
        }
        return head_->value;
    }
    int MaxLevel() { return level_; }

private:
    struct SkipNode;

    static const int kMaxLevel = 12;
    static const int kBranching = 4;

    void GetLessOrEqualPrev(const Key& key, SkipNode** prev)
    {
        int maxLevel = level_;
        SkipNode* p = head_;
        for (int l = maxLevel - 1; l >= 0; l--)
        {
            while (p->next[l] && p->next[l]->key <= key)
            {
                p = p->next[l];
            }
            prev[l] = p;
        }
    }

    int GetLevel()
    {
        int level = 1;
        while (level < kMaxLevel && (rand_.Next() % kBranching == 0))
        {
            level++;
        }

        return level;
    }

    Random rand_;
    int level_;
    SkipNode* head_;
};

template <typename Key, typename Value>
struct SkipList<Key, Value>::SkipNode
{
    SkipNode() : next(nullptr) {}
    SkipNode(const Key& k, const Value& v) : key(k), value(v), next(nullptr) {}
    SkipNode(const Key& k, const Value& v, int l) : key(k), value(v)
    {
        next = new SkipNode*[l];
        for (int i = 0; i < l; i++)
            next[i] = nullptr;
    }
    ~SkipNode()
    {
        delete[] next;
    }
    Key key;
    Value value;
    SkipNode** next;
};

} // namespace common
} // namespace hl

#endif

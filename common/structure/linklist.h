/*================================================================
*   Copyright (C) 2021 hlmmd. All rights reserved.
*
*   FileName    : linklist.h
*   Autor       ：hlmmd
*   Date        : 2021/06/19
*   Description :
*
================================================================*/

#ifndef COMMON_STRUCTURE_LINKLIST_H
#define COMMON_STRUCTURE_LINKLIST_H
#include <glog/logging.h>
#include <string>
#include <vector>
namespace hl
{
namespace common
{

template <typename T>
class SingleLinkList
{
public:
    SingleLinkList()
    {
        head_ = new Node();
        tail_ = head_;
    }

    ~SingleLinkList()
    {
        Node *p = head_, *q;
        while (p)
        {
            q = p->next;
            delete p;
            p = q;
        }
        head_ = tail_ = nullptr;
    }
    void Push_back(const T& v)
    {
        Node* p = new Node(v);
        tail_->next = p;
        tail_ = p;
    }

    void QuickSort()
    {
        if (head_ == tail_)
            return;
        MyQuickSort(head_->next, tail_);
    }

    void Debug()
    {
        Node* p = head_->next;
        std::string debugStr = "";
        while (p)
        {
            debugStr += std::to_string(p->value) + " ";
            p = p->next;
        }
        LOG(INFO) << debugStr;
    }

private:
    struct SingleListNode;
    using Node = SingleListNode;

    void MySortInsert(Node*& head, Node*& tail, Node* p)
    {
        if (head == nullptr)
            head = tail = p;
        else
        {
            tail->next = p;
            tail = tail->next;
        }
        tail->next = nullptr;
    }

    void MyQuickSort(Node*& head, Node*& tail)
    {
        if (head == nullptr || head->next == nullptr)
            return;

        Node* pivot = head;
        Node* p = head->next;
        Node *smaller = nullptr, *bigger = nullptr;
        Node *s = smaller, *b = bigger;
        while (p)
        {
            Node* q = p->next;
            if (p->value <= pivot->value)
            {
                MySortInsert(smaller, s, p);
            }
            else
            {
                MySortInsert(bigger, b, p);
            }
            p = q;
        }
        MyQuickSort(smaller, s);
        MyQuickSort(bigger, b);

        tail = bigger ? b : pivot;
        pivot->next = bigger;

        if (smaller == nullptr)
        {
            head = pivot;
            return;
        }
        else
        {
            head = smaller;
            s->next = pivot;
            return;
        }
    }

    Node* Mysort(Node* head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        Node* pivot = head;
        Node* p = head->next;
        Node *smaller = nullptr, *bigger = nullptr;
        Node *s = smaller, *b = bigger;
        while (p)
        {
            Node* q = p->next;
            if (p->value <= pivot->value)
            {
                MySortInsert(smaller, s, p);
            }
            else
            {
                MySortInsert(bigger, b, p);
            }
            p = q;
        }
        Node* p1 = Mysort(smaller);
        Node* p2 = Mysort(bigger);

        pivot->next = p2;
        if (p1 == nullptr)
            return pivot;
        Node* pp = p1;
        while (pp && pp->next)
            pp = pp->next;
        pp->next = pivot;
        return p1;
    }

    Node* head_;
    Node* tail_;
};

template <typename T>
struct SingleLinkList<T>::SingleListNode
{
    SingleListNode() : next(nullptr) {}
    SingleListNode(const T& v) : value(v), next(nullptr) {}
    SingleListNode(const T& v, SingleListNode* pnext) : value(v), next(pnext) {}
    T value;
    SingleListNode* next;
};

} // namespace common
} // namespace hl

#endif //LINKLIST_H

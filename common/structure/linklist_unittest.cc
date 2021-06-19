/*================================================================
*   Copyright (C) 2021 hlmmd. All rights reserved.
*
*   FileName    : linklist_unittest.cc
*   Autor       ：hlmmd
*   Date        : 2021/06/19
*   Description :
*
================================================================*/

#include "common/random.h"
#include "linklist.h"
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <gtest/gtest.h>
#include <map>
using namespace std;
using namespace hl;
using namespace hl::common;

DEFINE_string(debug_str, "hello world", "debug str");

TEST(LinkList, QuickSort)
{

    SingleLinkList<int> list;
    Random rand((int64_t)&list);
    const int number = 100;
    const int maxValue = 1000;
    for (int i = 0; i < number; i++)
    {
        int v = rand.Next() % maxValue;
        list.Push_back(v);
    }

    list.Debug();
    list.QuickSort();
    list.Push_back(maxValue);
    list.Debug();
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    google::ParseCommandLineFlags(&argc, &argv, true);
    return RUN_ALL_TESTS();
}

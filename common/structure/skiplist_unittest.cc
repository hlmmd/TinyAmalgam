/*================================================================
*   Copyright (C) 2021 hlmmd. All rights reserved.
*
*   FileName    : skiplist_unittest.cc
*   Autor       ：hlmmd
*   Date        : 2021/06/08
*   Description :
*
================================================================*/

#include "skiplist.h"
#include <gtest/gtest.h>
#include <glog/logging.h>
#include <gflags/gflags.h>
#include <iostream>
#include <map>
using namespace std;
using namespace hl;
using namespace hl::common;

DEFINE_string(debug_str,"hello world","debug str");

TEST(SkipList, ALL)
{
    LOG(INFO) << "test SkipList " << FLAGS_debug_str;
    SkipList<int, int> skipList;
    map<int, int> mymap;
    Random rand(0xffff);

    const int N = 1e6;

    for (int i = 0; i < N; i++)
    {
        int v = rand.Next() % N;
        mymap[v] = i;
        skipList.Insert(v, i);
    }
    for (int i = 0; i < N; i++)
    {
        ASSERT_EQ(mymap.count(i), skipList.Find(i));
    }
    for (int i = 0; i < N / 10; i++)
    {
        int v = rand.Next() % N;
        if (mymap.count(v))
        {
            mymap.erase(v);
            skipList.Erase(v);
        }
    }
    for (int v = 0; v < N; v++)
    {
        ASSERT_EQ(mymap.count(v), skipList.Find(v));
        if (skipList.Find(v))
        {
            ASSERT_EQ(mymap.at(v), skipList.At(v));
        }
    }
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    google::ParseCommandLineFlags(&argc, &argv, true);
    return RUN_ALL_TESTS();
}

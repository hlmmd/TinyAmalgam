/*================================================================
*   Copyright (C) 2021 hlmmd. All rights reserved.
*
*   FileName    : alg_unittest.cc
*   Autor       ：hlmmd
*   Date        : 2021/06/19
*   Description :
*
================================================================*/

#include "sort.h"
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <gtest/gtest.h>

using namespace hl;
using namespace hl::algorithm;

TEST(SORT, WTF)
{
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    google::ParseCommandLineFlags(&argc, &argv, true);
    return RUN_ALL_TESTS();
}

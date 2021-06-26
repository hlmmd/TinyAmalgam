/*================================================================
*   Copyright (C) 2021 hlmmd. All rights reserved.
*
*   FileName    : alg_unittest.cc
*   Autor       ：hlmmd
*   Date        : 2021/06/19
*   Description :
*
================================================================*/

#include "array.h"
#include "sort.h"
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <gtest/gtest.h>

using namespace hl;
using namespace hl::algorithm;
using namespace std;
TEST(ARRAY, PredictTheWinner)
{
    vector<int> nums = {1, 5, 233, 7};
    ASSERT_EQ(true, hl::algorithm::array::PredictTheWinner(nums));
}

TEST(GRAGH, GRAGH_IS_TREE)
{
    int n = 5;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}};
    ASSERT_EQ(false, hl::algorithm::array::GraghisTree(n, edges));
    edges = {{0, 1}, {0, 2}, {0, 3}, {1, 4}};
    ASSERT_EQ(true, hl::algorithm::array::GraghisTree(n, edges));
}

TEST(SORT, WTF)
{
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    google::ParseCommandLineFlags(&argc, &argv, true);
    return RUN_ALL_TESTS();
}

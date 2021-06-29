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
using namespace hl::algorithm::array_alg;
using namespace std;
TEST(ARRAY, PredictTheWinner)
{
    vector<int> nums = {1, 5, 233, 7};
    ASSERT_EQ(true, PredictTheWinner(nums));
}

TEST(GRAGH, GRAGH_IS_TREE)
{
    int n = 5;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}};
    ASSERT_EQ(false, GraghisTree(n, edges));
    edges = {{0, 1}, {0, 2}, {0, 3}, {1, 4}};
    ASSERT_EQ(true, GraghisTree(n, edges));
}

TEST(SORT, WTF)
{
}

TEST(PONY, ESCAPE)
{

    vector<vector<char>> matrix = {
        {'w', 'w', 'e', 'p', ' '},
        {' ', ' ', ' ', 'w', ' '},
        {'w', ' ', ' ', 'w', 'p'},
        {'p', ' ', 'p', ' ', ' '},
    };
    pair<int, int> end = {0, 2};
    auto ret = Escape(matrix, end);

    int count = 0;
    for (int i = 0; i < matrix.size(); i++)
        for (int j = 0; j < matrix[i].size(); j++)
            if (matrix[i][j] == 'p')
                count++;
    ASSERT_EQ(ret.size(), count);
    for (int i = 0; i < ret.size(); i++)
        LOG(INFO) << ret[i];
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    google::ParseCommandLineFlags(&argc, &argv, true);
    return RUN_ALL_TESTS();
}

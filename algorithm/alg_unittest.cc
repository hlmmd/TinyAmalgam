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
#include "kahan.h"
#include "sort.h"
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <gtest/gtest.h>

using namespace hl;
using namespace hl::algorithm;
using namespace hl::algorithm::array_alg;
using namespace std;

TEST(MATH, KahanSum)
{
    vector<float> v(1024 * 1024 * 128, 1.0f);
    ASSERT_FLOAT_EQ(KahanSum(v), 134217728.0f);

    vector<double> v2(1024 * 1024 * 128, 1.0);
    ASSERT_DOUBLE_EQ(KahanSum(v2), 134217728.0);
}

TEST(ARRAY, PredictTheWinner)
{
    vector<int> nums = {1, 5, 233, 7};
    ASSERT_EQ(true, PredictTheWinner(nums));
}

TEST(ARRAY, MaxSameSubStringAfterKReplace)
{
    std::vector<std::tuple<string, int, int>> tests = {
        {"AAAB", 1, 4},
        {"AABABBA", 1, 4},
        {"AAABAABBA", 3, 9}};
    for (auto& t : tests)
    {
        ASSERT_EQ(std::get<2>(t), MaxSameSubStringAfterKReplace(std::get<0>(t), std::get<1>(t)));
    }
}

TEST(MATH, Pow)
{
    long long a = 20, m = 50, mod = 1e9 + 7;
    long long res = 1;
    for (long long i = 0; i < m; i++)
    {
        res *= a;
        res %= mod;
    }
    ASSERT_EQ(PowWithMod(20, 50, mod), res);
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

TEST(PONY, GetMaxPair)
{
    std::vector<int> nums = {6, 3, 0, 4, 2};
    auto ret = GetMaxPair(nums, 3);
    ASSERT_EQ(ret.first, 4);
    ASSERT_EQ(ret.second, 3);

    nums = {2, 5, 3, 1, 3, 5, 7, 4, 2};
    ret = GetMaxPair(nums, 6);
    ASSERT_EQ(ret.first, 3);
    ASSERT_EQ(ret.second, 5);
}

TEST(PONY, GetMaxAndResult)
{
    std::vector<int> nums = {1024, 512, 512, 512, 513, 123, 45, 345, 4234, 23, 4, 23, 23, 1};
    int maxvalue = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            maxvalue = max(maxvalue, nums[i] & nums[j]);
        }
    }
    ASSERT_EQ(maxvalue, GetMaxAndResult(nums));
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    google::ParseCommandLineFlags(&argc, &argv, true);
    google::ShutDownCommandLineFlags();
    return RUN_ALL_TESTS();
}

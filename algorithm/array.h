/*================================================================
*   Copyright (C) 2021 hlmmd. All rights reserved.
*
*   FileName    : array.h
*   Autor       ：hlmmd
*   Date        : 2021/06/22
*   Description :
*
================================================================*/

#ifndef ALGORITHM_ARRAY_H
#define ALGORITHM_ARRAY_H

#include <vector>

namespace hl
{
namespace algorithm
{
namespace array
{

// leetcode 525 https://leetcode.com/problems/contiguous-array/
// 一个由且仅由01组成的数组，求最长的子数组，使得0和1的数量一样多
int findMaxLength(std::vector<int>& nums);

// leetcode 486 https://leetcode.com/problems/predict-the-winner/
// 两个人玩游戏，依次从数组的两端取走一个数，最后sum大者胜，返回先手是否胜利(sum相同算先手胜利)
bool PredictTheWinner(std::vector<int>& nums);

// 判断有向无环图是否构成树
bool GraghisTree(int n, std::vector<std::vector<int>>& edges);

} // namespace array
} // namespace algorithm
} // namespace hl

#endif

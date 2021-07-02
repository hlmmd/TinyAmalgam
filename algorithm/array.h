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

#include <cstdint>
#include <deque>
#include <queue>
#include <vector>
namespace hl
{
namespace algorithm
{
namespace array_alg
{

// leetcode 525 https://leetcode.com/problems/contiguous-array/
// 一个由且仅由01组成的数组，求最长的子数组，使得0和1的数量一样多
int findMaxLength(std::vector<int>& nums);

// leetcode 486 https://leetcode.com/problems/predict-the-winner/
// 两个人玩游戏，依次从数组的两端取走一个数，最后sum大者胜，返回先手是否胜利(sum相同算先手胜利)
bool PredictTheWinner(std::vector<int>& nums);

// 判断有向无环图是否构成树
bool GraghisTree(int n, std::vector<std::vector<int>>& edges);

// PONY 面试题
//  双端队列，长度n(100000)，每次队首取出两个数，将小的放回队首，大的放到队尾，问m(int64)次后队尾是？
int DequeGetM(std::deque<int>& q, int64_t m);

// 一个矩阵，里面p是人，w是墙，空格是空的，e是出口 保证所有人都能出来，返回每个人走出来的步数，出口唯一
std::vector<int> Escape(std::vector<std::vector<char>>& matrix, const std::pair<int, int>& end);

// 整数数组nums，正整数k，每次操作是让nums中任一个数+1,至多操作k次后，nums中出现次数最多值的次数
std::pair<int, int> GetMaxPair(std::vector<int>& nums, int k);

// 整数数组nums，求两两取&得到的最大值
int GetMaxAndResult(std::vector<int>& nums);

} // namespace array_alg
} // namespace algorithm
} // namespace hl

#endif


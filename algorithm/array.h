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

} // namespace array
} // namespace algorithm
} // namespace hl

#endif

/*================================================================
*   Copyright (C) 2021 hlmmd. All rights reserved.
*
*   FileName    : sort.cc
*   Autor       ：hlmmd
*   Date        : 2021/06/19
*   Description :
*
================================================================*/

#include "sort.h"

namespace hl
{
namespace algorithm
{
namespace sort
{
using namespace std;
void sortColors(std::vector<int>& nums)
{
    int small = 0, large = nums.size() - 1;
    for (int i = 0; i < nums.size() && i <= large; i++)
    {
        if (nums[i] == 0)
        {
            swap(nums[i], nums[small]);
            small++;
        }
        else if (nums[i] == 2)
        {
            swap(nums[i], nums[large]);
            large--;
            i--;
        }
    }
}
} // namespace sort
} // namespace algorithm
} // namespace hl

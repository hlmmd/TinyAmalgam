/*================================================================
*   Copyright (C) 2021 hlmmd. All rights reserved.
*
*   FileName    : array.cc
*   Autor       ：hlmmd
*   Date        : 2021/06/22
*   Description :
*
================================================================*/

#include "array.h"
#include <unordered_map>
namespace hl
{
namespace algorithm
{
namespace array
{

using namespace std;
int findMaxLength(vector<int>& nums)
{
    int sum = 0;
    unordered_map<int, int> mymap;
    mymap[0] = -1;

    int maxret = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i] ? 1 : -1;
        if (!mymap.count(sum))
            mymap[sum] = i;
        else
            maxret = max(maxret, i - mymap[sum]);
    }
    return maxret;
}

} // namespace array
} // namespace algorithm
} // namespace hl

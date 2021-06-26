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
#include <glog/logging.h>
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

bool PredictTheWinner(std::vector<int>& nums)
{
    int n = nums.size();
    vector<int> prefixSum(n + 1, 0);
    for (int i = 1; i <= n; i++)
        prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        dp[i][i] = nums[i];
    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i + len - 1 < n; i++)
        {
            int j = i + len - 1;
            int sumij = prefixSum[j + 1] - prefixSum[i];
            dp[i][j] = max(sumij - dp[i + 1][j], sumij - dp[i][j - 1]);
        }
    }
    return 2 * dp[0][n - 1] >= prefixSum.back();
}

} // namespace array
} // namespace algorithm
} // namespace hl

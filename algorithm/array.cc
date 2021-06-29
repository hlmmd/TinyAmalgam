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
#include <functional>
#include <glog/logging.h>
#include <unordered_map>
namespace hl
{
namespace algorithm
{
namespace array_alg
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

bool GraghisTree(int n, std::vector<std::vector<int>>& edges)
{
    if (n < 1 || edges.size() + 1 != n)
        return false;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        v[i] = i;

    std::function<int(int)> find = [&v, &find](int x)
    {
        if (x == v[x])
            return x;
        return find(v[x]);
    };

    for (auto& edge : edges)
    {
        int v1 = find(edge[0]);
        int v2 = find(edge[1]);
        v[v1] = v2;
    }
    int count = 0;
    for (int i = 0; i < n; i++)
        if (v[i] == i)
            count++;
    return count == 1;
}

int DequeGetM(std::deque<int>& q, int64_t m)
{
    int n = q.size();
    if (n == 0)
        return -1;
    if (n == 1)
        return q.front();

    m = m % (n - 1);
    for (int i = 0; i < m; i++)
    {
        int t1 = q.front();
        q.pop_front();
        int t2 = q.front();
        q.pop_front();
        if (t1 > t2)
            swap(t1, t2);
        q.push_front(t1);
        q.push_back(t2);
    }
    return q.front();
}

vector<int> Escape(vector<vector<char>>& matrix, const pair<int, int>& end)
{
    vector<int> ret;
    int m = matrix.size();
    if (m < 0)
        return ret;
    int n = matrix[0].size();
    if (n == 0)
        return ret;

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<pair<int, int>> bfsQueue;
    bfsQueue.push(end);
    visited[end.first][end.second] = true;
    int count = 0;
    while (!bfsQueue.empty())
    {
        int N = bfsQueue.size();
        for (int i = 0; i < N; i++)
        {
            auto p = bfsQueue.front();
            bfsQueue.pop();
            int x = p.first;
            int y = p.second;
            if (matrix[x][y] == 'w')
                continue;
            if (matrix[x][y] == 'p')
            {
                ret.push_back(count);
            }

            vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
            for (auto d : dir)
            {
                int nx = x + d.first;
                int ny = y + d.second;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny])
                {
                    visited[nx][ny] = true;
                    bfsQueue.push({nx, ny});
                }
            }
        }
        count++;
    }

    return ret;
}

} // namespace array_alg
} // namespace algorithm
} // namespace hl

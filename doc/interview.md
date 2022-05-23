```cpp
#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include <algorithm>
using namespace std;


vector<pair<int,int>> positions;
template<typename SoftwareAdapter1,typename SoftwareAdapter2>
class DataTransferPlugin{

    int Init(){
        // 初始化两个软件的adapter
        mpAdapter1.reset(new SoftwareAdapter1);
        mpAdapter1->Init();
        mpAdapter2.reset(new SoftwareAdapter2);
        mpAdapter2->Init();
        // 注册收到消息回调
        mpAdapter1->setReceiveCallBack(std::bind(this,OnReceiveFrom1,_1));
        mpAdapter2->setReceiveCallBack(std::bind(this,OnReceiveFrom2,_1));
        // ……
        mInited = true;
        return 0;
    }

    int Start()
    {
        mRunning = true;
        while(mRunning)
        {
            //event_loop
        };
    }

    int ShutDown()
    {
        mRunning = false;
    }
private:
    bool mInited = false;
    bool mRunning = false;

    // 核心思想时将收到的字节流msg转换成一种中间格式，
    // 提供ToPluginFormat、ToSoftWareFormat 两个模板函数完成转换
    //
    void OnReceiveFrom1(std::string & msg)
    {
        PluginFormat middleMsg;
        ToPluginFormat<SoftwareAdapter1>(msg,middleMsg);
        std::string sendMsg;
        ToSoftWareFormat<SoftwareAdapter2>(middleMsg,sendMsg);
        mpAdapter2->send(sendMsg);
    }

    void OnReceiveFrom2(std::string & msg)
    {
        PluginFormat middleMsg;
        ToPluginFormat<SoftwareAdapter2>(msg,middleMsg);
        std::string sendMsg;
        ToSoftWareFormat<SoftwareAdapter1>(middleMsg,sendMsg);
        mpAdapter1->send(sendMsg);
    }

    std::unique_ptr<SoftwareAdapter1> mpAdapter1;
    std::unique_ptr<SoftwareAdapter2> mpAdapter2;
};




/*
    matrix 表示输入棋盘,matrix[i][j]为棋盘上的豆子数
    path 为输出最大sum路径，每个元素表示(i,j)坐标
    返回值为吃豆人能吃掉的最大豆子数
 */
int MaxSum(const vector<vector<int>> &matrix, vector<pair<int, int>> &path)
{
    int m = matrix.size();
    if (m == 0)
        return 0;
    int n = matrix[0].size();
    if (n == 0)
        return 0;

    // 动态规划， dp[i][j]表示走到(i,j)时能吃到的最大的豆子数
    // 对于(i,j)，要么由（i-1,j)往下走一格，要么由(i,j-1)往右走一格，所以可以得到递推式
    // dp[i][j]  = max(dp[i-1][j],dp[i][j-1]) + matrix[i][j]
    // 由于需要返回路径，用pre来记录一下每个结点的上一个结点
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = matrix[0][0];
    map<pair<int, int>, pair<int, int>> pre;

    for (int i = 1; i < matrix.size(); i++)
    {
        dp[i][0] = matrix[i][0] + dp[i - 1][0];
        pre[{i, 0}] = {i - 1, 0};
    }
    for (int i = 1; i < n; i++)
    {
        dp[0][i] = matrix[0][i] + dp[0][i - 1];
        pre[{0, i}] = {0, i - 1};
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                dp[i][j] = dp[i - 1][j] + matrix[i][j];
                pre[{i, j}] = {i - 1, j};
            }
            else
            {
                dp[i][j] = dp[i][j - 1] + matrix[i][j];
                pre[{i, j}] = {i, j - 1};
            }
        }
    }
    // 从终点开始，通过Pre一直走到起点，最后再翻转path，得到路径
    path.push_back({m - 1, n - 1});
    while (1)
    {
        auto last = path.back();
        if (last.first == 0 && last.second == 0)
        {
            break;
        }
        path.push_back(pre[last]);
    }
    std::reverse(path.begin(), path.end());

    return dp[m - 1][n - 1];
}


int MaxSum(const vector<vector<int>> &matrix, vector<pair<int, int>> &path)
{
    int m = matrix.size();
    if (m == 0)
        return 0;
    int n = matrix[0].size();
    if (n == 0)
        return 0;

    for(int i= 0 ;i<m;i++)
    {
        for(int j = 0 ;j<n;j++)
        {
            matrix[i][j] = 
        }
    }
    return 0;
}


int main()
{
    vector<vector<int>> matrix = {
        {0, 3, 4}, {2, 5, 8}, {3, 4, 2}, {5, 2, 6}};
    std::vector<pair<int, int>> path;
    int maxSum = MaxSum(matrix, path);
    cout << "maxSum " << maxSum << endl;
    cout << "path " << endl;
    for (const auto &p : path)
        cout << p.first << " " << p.second << endl;
    return 0;
}

```
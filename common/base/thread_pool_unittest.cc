#include "count_down_latch.h"
#include "thread_pool.h"
#include "shared_ptr.h"
#include "timestamp.h"
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <gtest/gtest.h>
using namespace std;
using namespace hl;
using namespace hl::common;

DEFINE_string(debug_str, "hello world", "debug str");

void DoSomeThing()
{
    int size = 100;
    long long temp = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                temp += i * j * k;
                temp &= 0x11223344;;
            }
        }
    }
}

TEST(ThreadPool, FUNCTEST)
{
    int threadNum = 16, threadPoolSize = 100;
    std::shared_ptr<ThreadPool> pThreadPool =
        std::make_shared<ThreadPool>(threadNum, threadPoolSize);
    int taskSize = 1024;
    std::shared_ptr<CountDownLatch> pCounter = std::make_shared<CountDownLatch>(taskSize);
    Timestamp t;
    t.update();
    for (int i = 0; i < taskSize; i++)
    {
        auto func = [pCounter]()
        {
            DoSomeThing();
            pCounter->CountDown();
        };
        //  func();
        pThreadPool->Submit(func);
    }
    pCounter->Wait();

    cout << "threadpool used time " << t.msTillNow() << endl;

    t.update();
    for (int i = 0; i < taskSize; i++)
    {
        DoSomeThing();
    }
    cout << "sync used time " << t.msTillNow() << endl;
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    google::ParseCommandLineFlags(&argc, &argv, true);
    google::ShutDownCommandLineFlags();
    return RUN_ALL_TESTS();
}

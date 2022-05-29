#include "count_down_latch.h"
#include "object_pool.h"
#include "shared_ptr.h"
#include "timestamp.h"
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <gtest/gtest.h>
using namespace std;
using namespace hl;
using namespace hl::common;

class TestObject
{
public:
    explicit TestObject(int seq = 0) : seq_(seq)
    {
        LOG(ERROR) << "construct " << seq_;
    }
    virtual ~TestObject()
    {
        LOG(ERROR) << "desctrut " << seq_;
    }
    int value() const { return seq_; }

private:
    int seq_;
};
ObjectPool<TestObject>::ObjectPtr pObject;
TEST(ObjectPool, FUNCTEST)
{
    int poolSize = 2;
    auto pObjectPool = std::make_shared<ObjectPool<TestObject>>(poolSize);

    pObjectPool->GetOne(pObject);
    pObjectPool->GetOne(pObject);
    pObjectPool->GetOne(pObject);
    pObjectPool->GetOne(pObject);
    {
        ObjectPool<TestObject>::ObjectPtr p2, p3;
        pObjectPool->GetOne(p2);
        LOG(ERROR) << " p2 ";
        p2 = nullptr;
        pObjectPool->GetOne(p3);
    }
    cout << pObject.get() << endl;
    cout << pObject->value() << endl;
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    google::ParseCommandLineFlags(&argc, &argv, true);
    google::ShutDownCommandLineFlags();
    RUN_ALL_TESTS();
    cout << pObject.get() << endl;
    cout << pObject->value() << endl;
    return 0;
}

#include "randomize_set.h"
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <gtest/gtest.h>
#include <map>
using namespace std;
using namespace hl;
using namespace hl::common;

DEFINE_string(debug_str, "hello world", "debug str");

TEST(RANDOMIZED_SET, ALL)
{
    RandomizedSet<int> randomSet;
    int value = 0;
    ASSERT_EQ(true, randomSet.Insert(1));
    ASSERT_EQ(true, randomSet.Insert(3));
    ASSERT_EQ(true, randomSet.Insert(9));
    ASSERT_EQ(false, randomSet.Insert(1));
    ASSERT_EQ(true, randomSet.Remove(1));
    ASSERT_EQ(false, randomSet.Remove(1));
    ASSERT_EQ(false, randomSet.Remove(2));
    ASSERT_EQ(0, randomSet.GetRandomValue(value));
    if (value != 3 && value != 9)
    {
        LOG(ERROR) << "get random fail, value: " << value;
        ASSERT_EQ(0, 1);
    }
    ASSERT_EQ(true, randomSet.Remove(3));
    ASSERT_EQ(true, randomSet.Remove(9));
    ASSERT_EQ(-1, randomSet.GetRandomValue(value));
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    google::ParseCommandLineFlags(&argc, &argv, true);
    return RUN_ALL_TESTS();
}

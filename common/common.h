#ifndef COMMON_COMMON_H
#define COMMON_COMMON_H

#include <stdint.h>

#include <deque>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>
#include <string>

#include <atomic>
#include <condition_variable>
#include <functional>
#include <mutex>
#include <thread>

#include <glog/logging.h>

namespace hl
{
using std::placeholders::_1;
using std::placeholders::_2;
using std::placeholders::_3;
using std::placeholders::_4;

using ThreadPtr = std::shared_ptr<std::thread>;
} // namespace hl

#endif // COMMON_COMMON_H

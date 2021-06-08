#ifndef COMMON_VIDEO_STRUCT_H
#define COMMON_VIDEO_STRUCT_H

#include <stdint.h>

namespace hl
{

namespace common
{

namespace video
{

class Frame
{
    Frame() = default;
    virtual ~Frame() = default;

    virtual int64_t Id() = 0;

    virtual bool isFinishFrame() = 0;
};

}; // namespace video

}; // namespace common
}; // namespace hl

#endif

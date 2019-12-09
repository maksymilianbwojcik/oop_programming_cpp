#ifndef INC_08_FAKE_MOCK_OR_STUB_TIMEMOCK_H
#define INC_08_FAKE_MOCK_OR_STUB_TIMEMOCK_H
#include "TestIncludes.h"
#include "gmock/gmock-generated-function-mockers.h"
#include "../../include/TimeImpl.h"

class TimeMock : public Time
{
public:
    MOCK_METHOD1( create, void(bool endless));
    MOCK_CONST_METHOD0(now, long long());
    MOCK_METHOD0(flow, void());

};
#endif //INC_08_FAKE_MOCK_OR_STUB_TIMEMOCK_H

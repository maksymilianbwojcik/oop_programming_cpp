#ifndef INC_08_FAKE_MOCK_OR_STUB_OBSERVERMOCK_H
#define INC_08_FAKE_MOCK_OR_STUB_OBSERVERMOCK_H
#include "TestIncludes.h"
#include "../../include/ObserverImpl.h"

class ObserverMock : public Observer
{
public:
    MOCK_METHOD2( remember, void(std::string question, std::string answer) );
    MOCK_CONST_METHOD1( answer, std::string(std::string question));
};
#endif //INC_08_FAKE_MOCK_OR_STUB_OBSERVERMOCK_H

#include "Universe.h"
#include "TestIncludes.h"

class Interface {
public:
    virtual int test() = 0;
};

class Implementation : public Interface {
    public:
    int test() override {
        return 10;
    }
};

class MyMock : public Interface {
public:
    MOCK_METHOD0(test, int());
};

class Dummy {
    Interface &interface;
public:
    explicit Dummy(Interface &interface) : interface(interface) {}
    int execute() { return interface.test(); }
};

TEST(Universe, Create)
{
    // TODO: Test Universe class...

    MyMock myMock{};
    Dummy dummy{myMock};

    EXPECT_CALL(myMock, test()).WillOnce(Return(10));

    EXPECT_EQ(10, dummy.execute());
}


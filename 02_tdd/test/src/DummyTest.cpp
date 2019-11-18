#include "TestIncludes.h"
#include "Dummy.h"

TEST(Dummy, Hello) {

    Dummy dummy{};
    ASSERT_EQ("Hello!", dummy.hello());
}

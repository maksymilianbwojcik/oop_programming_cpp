#include "Dummy.h"
#include "TestIncludes.h"

TEST(Dummy, Add_SeparateBitNumbers)
{
    Dummy dummy{};
    EXPECT_EQ(3, dummy.add(1, 2));
}

TEST(Dummy, Add_OverlapingBitNumbers)
{
    Dummy dummy{};
    EXPECT_EQ(5, dummy.add(2, 3));
}

#include <gtest/gtest.h>
#include "main.cpp"


TEST(Dummy, Add)
{
auto dummy = Dummy{};
EXPECT_EQ(4, dummy.add(1, 3));
}

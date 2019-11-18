#include "TestIncludes.h"
#include "TextWrapper.h"


TEST(TextWrapper, CreateInstance)
{
    auto wrapper = TextWrapper{};
}

TEST(TextWrapper, HasColumnsGetter)
{
    auto wrapper = TextWrapper{};
    EXPECT_EQ(10, wrapper.columns(10));
}


TEST(TextWrapper, HasDataGetter)
{
    auto wrapper = TextWrapper{};
    EXPECT_EQ(wrapper.textToTransform("not"), "not");
}

TEST(TextWrapper, Test1)
{
    auto wrapper = TextWrapper{};
   // EXPECT_EQ(wrapper.arguments(wrapper.columns(1), wrapper.textToTransform(" ")), " ");
}

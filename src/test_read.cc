#include "test.h"

#include <string>

TEST_SUITE(read, { int num; std::string str; }, "Read a string and output s-exp")

TEST_SETUP
{
    data.num = 5;
    data.str = "foo";
}

TEST_TEARDOWN
{
    data.num = 0;
}

TEST(number)
{
    ASSERT_EQUAL(4, data.num);
}

TEST(str)
{
    ASSERT_EQUAL(data.str, "bufoo");
}

TEST_BEGIN
TEST_RUN(number);
TEST_RUN(number);
TEST_RUN(number);
TEST_RUN(str);
TEST_END
